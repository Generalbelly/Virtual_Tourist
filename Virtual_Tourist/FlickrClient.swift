//
//  FlickrClient.swift
//  Virtual_Tourist
//
//  Created by ShimmenNobuyoshi on 2015/06/01.
//  Copyright (c) 2015年 Shimmen Nobuyoshi. All rights reserved.
//

import Foundation
import UIKit

class FlickrClient: NSObject {

    static let sharedInstance = FlickrClient()
    var session: NSURLSession

    override init() {
        session = NSURLSession.sharedSession()
    }

    func getImagesFromFlickr(destination: Location, completionHandler: ((success: Bool, dics: [[String: String]]?, error: NSError?) -> Void)) {
        let methodArguments = [
            FlickrClient.Keys.METHOD: FlickrClient.Constants.METHOD,
            FlickrClient.Keys.API_KEY: FlickrClient.Constants.API_KEY,
            FlickrClient.Keys.SAFE_SEARCH: FlickrClient.Constants.SAFE_SEARCH,
            FlickrClient.Keys.LAT: destination.lat!,
            FlickrClient.Keys.LON: destination.lon!,
            FlickrClient.Keys.EXTRAS: FlickrClient.Constants.EXTRAS,
            FlickrClient.Keys.FORMAT: FlickrClient.Constants.FORMAT,
            FlickrClient.Keys.NO_JSON_CALLBACK: FlickrClient.Constants.NO_JSON_CALLBACK,
        ]
        var dics = [[String: String]]()
        let urlString = FlickrClient.Constants.BaseURL + escapedParameters(methodArguments)
        let url = NSURL(string: urlString)
        let request = NSMutableURLRequest(URL: url!)
        request.HTTPMethod = "POST"
        let task = session.dataTaskWithRequest(request) { data, response, downloadingError in
            if let res = response as? NSHTTPURLResponse {
                if res.statusCode != 200 {
                    completionHandler(success: false, dics: nil, error: downloadingError)
                }
            }
            if downloadingError != nil {
                completionHandler(success: false, dics: nil, error: downloadingError)
            } else {
                let parsedResult = (try! NSJSONSerialization.JSONObjectWithData(data!, options: NSJSONReadingOptions.AllowFragments)) as! [String: AnyObject]
                let info = parsedResult["photos"] as! [String: AnyObject]
                if let photoDictionary = info["photo"] as? [[String: AnyObject]] {
                    if photoDictionary.count > 0 {
                        for item in photoDictionary {
                            let imageUrlString = item["url_m"] as! String
                            let id = item["id"] as! String
                            let dic = ["imageUrlString": imageUrlString, "id": id]
                            dics.append(dic)
                        }
                        completionHandler(success: true, dics: dics, error: nil)
                    } else {
                        completionHandler(success: false, dics: nil, error: nil)
                    }
                }
            }
        }
        task.resume()

    }

    func handleFlickr(success: Bool, dics: [[String: String]], destination: Location,  completionHandler: ( Bool -> Void )) {
        for item in dics {
            let picture = Picture(dic: item, context: CoreDataStackManager.sharedInstance.managedObjectContext)
            picture.destination = destination
        }
        CoreDataStackManager.sharedInstance.saveContext()
        completionHandler(true)
    }

    func escapedParameters(parameters: [String : AnyObject]) -> String {
        var urlVars = [String]()
        for (key, value) in parameters {
            let stringValue = "\(value)"
            let escapedValue = stringValue.stringByAddingPercentEncodingWithAllowedCharacters(NSCharacterSet.URLQueryAllowedCharacterSet())
            urlVars += [key + "=" + "\(escapedValue!)"]
        }
        return (!urlVars.isEmpty ? "?" : "") + urlVars.joinWithSeparator("&")
    }
}