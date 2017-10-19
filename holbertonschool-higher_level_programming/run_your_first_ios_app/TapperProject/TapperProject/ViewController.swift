//
//  ViewController.swift
//  TapperProject
//
//  Created by Icarus on 5/25/16.
//  Copyright © 2016 Icarus. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    // class attributes go here
    var tapsRequested:Int? = 0
    var tapsDone:Int = 0
    var timer: NSTimer = NSTimer()
    
    @IBOutlet weak var tfTaps: UITextField!
    @IBOutlet weak var btnPlay: UIButton!
    @IBOutlet weak var btnCoin: UIButton!
    @IBOutlet weak var lblTaps: UILabel!
    @IBOutlet weak var imgTapper: UIImageView!
    
  
    @IBAction func playBtn(sender: AnyObject) {
        if self.tfTaps != nil && self.tfTaps.text != "" {
            self.tapsRequested = Int(self.tfTaps.text!)
            
            if self.tapsRequested != nil {
                self.lblTaps.hidden = false
                self.btnPlay.hidden = true
                self.imgTapper.hidden = true
                self.tfTaps.hidden = true
                self.btnCoin.hidden = false
                
            }
        }
    }
    
    
    @IBAction func tapBtn(sender: AnyObject) {
        // action from clicCoin
        
        if timer.valid {
            timer.invalidate()
        }
        timer = NSTimer.scheduledTimerWithTimeInterval(1.0, target: self, selector: #selector (resetGame), userInfo: nil, repeats: false)
        
        self.tapsDone += 1
        if self.tapsDone == self.tapsRequested {
            self.lblTaps.text = "YOU DID IT!!!"
        }
        if self.tapsDone > self.tapsRequested {
            self.resetGame()
        }
        else {
            self.updateTapsLabel()
        }

    }
    
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        self.resetGame()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func updateTapsLabel() {
        self.lblTaps.text = String(tapsDone) + " Taps!"
    }
    
    func resetGame() {
        self.tapsDone = 0
        self.tapsRequested = 0
        
        self.lblTaps.text = String(tapsDone) + " Taps!"
        self.tfTaps.text = ""
        
        
        self.lblTaps.hidden = true
        self.lblTaps.hidden = true
        self.btnPlay.hidden = false
        self.imgTapper.hidden = false
        self.tfTaps.hidden = false
        self.btnCoin.hidden = true
    }

}

