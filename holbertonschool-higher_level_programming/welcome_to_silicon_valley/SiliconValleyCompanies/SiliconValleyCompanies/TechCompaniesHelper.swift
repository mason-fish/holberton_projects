//
//  TechCompaniesHelper.swift
//  SiliconValleyCompanies
//
//  Created by Icarus on 5/27/16.
//  Copyright © 2016 Icarus. All rights reserved.
//

import Foundation

class TechCompaniesHelper {
    static var companies:[String] = ["Holberton", "Linkedin", "Docker", "Google", "Yahoo", "Apple"]
    
    static func getTechCompanies() -> [String] {
        return companies
    }
}