//
//  TravelLocationMapViewController.swift
//  Virtual_Tourist
//
//  Created by ShimmenNobuyoshi on 2015/05/31.
//  Copyright (c) 2015年 Shimmen Nobuyoshi. All rights reserved.
//

import UIKit
import CoreData
import MapKit

class TravelLocationMapViewController: UIViewController, MKMapViewDelegate {

    @IBOutlet weak var mapView: MKMapView! { didSet { self.enableUserPin() } }
    var destination: Location?
    var destinations = [Location]()
    var noImage = false
    var picturesFetched = false
    var filePath : String {
        let manager = NSFileManager.defaultManager()
        let url = manager.URLsForDirectory(.DocumentDirectory, inDomains: .UserDomainMask).first!
        return url.URLByAppendingPathComponent("mapRegionArchive").path!
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        self.restoreMapRegion(false)
    }

    override func viewWillAppear(animated: Bool) {
        super.viewWillAppear(animated)
        destinations = fetchAllDestinations()
        if destinations.count > 0 {
            mapAllThePlaces(destinations)
        }
    }

    override func viewWillDisappear(animated: Bool) {
        super.viewWillDisappear(animated)
         let dictionary = [
            "latitude" : self.mapView.region.center.latitude,
            "longitude" : self.mapView.region.center.longitude,
            "latitudeDelta" : self.mapView.region.span.latitudeDelta,
            "longitudeDelta" : self.mapView.region.span.longitudeDelta
        ]
        NSKeyedArchiver.archiveRootObject(dictionary, toFile: filePath)
    }

    func restoreMapRegion(animated: Bool) {
        if let regionDictionary = NSKeyedUnarchiver.unarchiveObjectWithFile(filePath) as? [String : AnyObject] {
            let longitude = regionDictionary["longitude"] as! CLLocationDegrees
            let latitude = regionDictionary["latitude"] as! CLLocationDegrees
            let center = CLLocationCoordinate2D(latitude: latitude, longitude: longitude)
            let longitudeDelta = regionDictionary["latitudeDelta"] as! CLLocationDegrees
            let latitudeDelta = regionDictionary["longitudeDelta"] as! CLLocationDegrees
            let span = MKCoordinateSpan(latitudeDelta: latitudeDelta, longitudeDelta: longitudeDelta)
            let savedRegion = MKCoordinateRegion(center: center, span: span)
            self.mapView.setRegion(savedRegion, animated: animated)
        }
    }

    func fetchAllDestinations() -> [Location] {
        var error: NSError?
        let fetchRequest = NSFetchRequest(entityName: "Location")
        let results: [AnyObject]?
        do {
            results = try sharedContext().executeFetchRequest(fetchRequest)
        } catch let error1 as NSError {
            error = error1
            results = nil
        }
        if error != nil {
            self.displayAlertView("Sorry, error occured for some reason...")
        }
        return results as! [Location]
    }

    func displayAlertView(message: String) {
        let alertController = UIAlertController(title: "Loading pictures Failed", message: message, preferredStyle: .Alert)
        let action = UIAlertAction(title: "OK", style: .Default) { (action) in
            self.dismissViewControllerAnimated(true, completion: nil)
        }
        alertController.addAction(action)
        self.presentViewController(alertController, animated: true, completion: nil)
    }

    func mapAllThePlaces(places: [Location]) {
        let annotations = places.map() {
            place -> MKPointAnnotation in
            return place.pin
        }
        self.mapView.addAnnotations(annotations)
    }

    func sharedContext() -> NSManagedObjectContext {
        return CoreDataStackManager.sharedInstance.managedObjectContext
    }

    lazy var temporaryContext: NSManagedObjectContext = {
        var context = NSManagedObjectContext(concurrencyType: NSManagedObjectContextConcurrencyType.MainQueueConcurrencyType)
        context.persistentStoreCoordinator = self.sharedContext().persistentStoreCoordinator
        return context
    }()

    func enableUserPin() {
        let lpgr = UILongPressGestureRecognizer(target: self, action: "action:")
        lpgr.minimumPressDuration = 2
        self.mapView.addGestureRecognizer(lpgr)
    }

    func action(gestureRecognizer: UIGestureRecognizer) {
        let gestureState = gestureRecognizer.state
        switch gestureState {
        case .Began:
            createDragEffect(gestureRecognizer)
        case .Changed:
            createDragEffect(gestureRecognizer)
        case .Ended:
            destinationSet(gestureRecognizer)
        default:
            break
        }
    }

    func createDragEffect(gestureRecognizer: UIGestureRecognizer){
        var temporaryDestinations = [MKPointAnnotation]()
        let wayPoints = gestureRecognizer.locationInView(self.mapView)
        let location: CLLocationCoordinate2D = self.mapView.convertPoint(wayPoints, toCoordinateFromView: self.mapView)
        let temporaryDestination = Location(wayPoints: location, context: temporaryContext)
        temporaryDestinations.append(temporaryDestination.pin)
        self.mapView.addAnnotation(temporaryDestination.pin)
    }

    func destinationSet(gestureRecognizer: UIGestureRecognizer) {
        self.mapView.removeAnnotations(self.mapView.annotations)
        let wayPoints = gestureRecognizer.locationInView(self.mapView)
        let location: CLLocationCoordinate2D = self.mapView.convertPoint(wayPoints, toCoordinateFromView: self.mapView)
        self.destination = Location(wayPoints: location, context: sharedContext())
        self.destinations.append(destination!)
        CoreDataStackManager.sharedInstance.saveContext()
        self.mapAllThePlaces(self.destinations)
        self.fetchPictures(self.destinations.last!)
    }

    func fetchPictures(destination: Location) {
        if self.destination!.pictures.isEmpty {
            FlickrClient.sharedInstance.getImagesFromFlickr(self.destination!) { success, dic, error in
                dispatch_async(dispatch_get_main_queue()) {
                    if success == true && dic != nil {
                        FlickrClient.sharedInstance.handleFlickr(success, dics: dic!, destination: self.destination!) { completed in self.picturesFetched = true }
                    }
                }
            }
        } else {
            self.noImage = true
        }
    }

    func mapView(mapView: MKMapView, didSelectAnnotationView view: MKAnnotationView) {
        let pinCoordinate = view.annotation!.coordinate
        for destination in self.destinations {
            if destination.pin.coordinate.latitude == pinCoordinate.latitude {
                if destination.pin.coordinate.longitude == pinCoordinate.longitude {
                    self.destination = destination
                    if self.destination != destinations.last || self.picturesFetched == false {
                        FlickrClient.sharedInstance.getImagesFromFlickr(self.destination!) { success, dic, error in
                            dispatch_async(dispatch_get_main_queue()) {
                                if success == true && dic != nil {
                                    FlickrClient.sharedInstance.handleFlickr(success, dics: dic!, destination: self.destination!) { completed in
                                            self.performSegueWithIdentifier("showPictures", sender: self)
                                        }
                                } else {
                                    self.noImage = true
                                }
                            }
                        }
                    }
                    self.performSegueWithIdentifier("showPictures", sender: self)
                }
            }
        }
    }

    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        if segue.identifier == "showPictures" {
            let pav = segue.destinationViewController as! PhotoAlbumViewController
            pav.destination = self.destination
            if self.noImage == true {
                pav.noImageLabel.hidden = false
            }
            if self.destination?.pictures.count > 0 {
                pav.shouldUpdateBottomButton = true
            }
        }
    }

}
