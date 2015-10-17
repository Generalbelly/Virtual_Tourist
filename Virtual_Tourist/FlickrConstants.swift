//
//  FlickrConstants.swift
//  Virtual_Tourist
//
//  Created by ShimmenNobuyoshi on 2015/06/01.
//  Copyright (c) 2015年 Shimmen Nobuyoshi. All rights reserved.
//

import Foundation

extension FlickrClient {

    struct Constants {
        static let API_KEY = "685995c2dc6b21b9ca97e913e5b6ace8"
        static let My_API_Secret = "1d1f4e250da904e3"
        static let BaseURL = "https://api.flickr.com/services/rest/"
        static let METHOD = "flickr.photos.search"
        static let EXTRAS = "url_m"
        static let SAFE_SEARCH = "1"
        static let FORMAT = "json"
        static let NO_JSON_CALLBACK = "1"
    }

    struct Keys {
        static let METHOD = "method"
        static let API_KEY = "api_key"
        static let SAFE_SEARCH = "safe_search"
        static let LAT = "lat"
        static let LON = "lon"
        static let EXTRAS = "extras"
        static let FORMAT = "format"
        static let NO_JSON_CALLBACK = "nojsoncallback"
    }

}