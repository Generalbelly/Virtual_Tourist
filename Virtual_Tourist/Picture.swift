//
//  Picture.swift
//  Virtual_Tourist
//
//  Created by ShimmenNobuyoshi on 2015/06/09.
//  Copyright (c) 2015年 Shimmen Nobuyoshi. All rights reserved.
//

import Foundation
import CoreData
import UIKit

class Picture: NSManagedObject {

    @NSManaged var id: String?
    @NSManaged var imageUrlString: String?
    @NSManaged var destination: Location?

    override init(entity: NSEntityDescription, insertIntoManagedObjectContext context: NSManagedObjectContext?) {
        super.init(entity: entity, insertIntoManagedObjectContext: context)
    }

    init(dic: [String: String], context: NSManagedObjectContext) {
        let entity = NSEntityDescription.entityForName("Picture", inManagedObjectContext: context)
        super.init(entity: entity!, insertIntoManagedObjectContext: context)
        self.imageUrlString = dic["imageUrlString"]
        self.id = dic["id"]
    }

    var image: UIImage? {
        get {
            return ImageHandler.sharedImageHandler.imageWithIdentifier(self.id)
        }
    }

}