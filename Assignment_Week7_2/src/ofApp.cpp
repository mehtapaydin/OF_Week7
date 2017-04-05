#include "ofApp.h"
#include "wave.h"



vector<wave> waves;

//void ofApp::add(ofPoint l){
//    
//    for (int i=0; i<5; i++){
//        wave newWaves;
//        newWaves.setup();
//        waves.push_back(newWaves);
//    }
//
//}


//--------------------------------------------------------------
void ofApp::setup(){
    
    for (int i=0; i<5; i++){
        wave newWaves;
        newWaves.setup();
        waves.push_back(newWaves);
        }

    
}

//--------------------------------------------------------------
void ofApp::update(){
    
        for(int i=0; i<waves.size(); i++){
            waves[i].update();
            
            if(waves[i].t.x<0||waves[i].t.x>ofGetWidth()||waves[i].t.y<0||waves[i].t.y>ofGetHeight()){
                waves.erase(waves.begin()+i);
                wave newWaves;
                newWaves.setup();
                newWaves.t= ofPoint(ofRandom(ofGetWindowWidth()), ofRandom(ofGetHeight()),0);
                waves.push_back(newWaves);
            }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    for (int i=0; i<waves.size(); i++){
        wave newWaves;
        newWaves.setup();
         waves[i].draw();
    }

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
