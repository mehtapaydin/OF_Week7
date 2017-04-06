//
//  wave.cpp
//  Assignment_Week7_2
//
//  Created by Mehtap Aydin on 4/5/17.
//
//

#include "wave.h"
#include "ofMain.h"

wave::wave(){

}

void wave::setup(){
    
    color.set(ofRandom(255), ofRandom(255), ofRandom(255));
    
    p1 = ofPoint(ofRandom(-20,0));
    p2 = ofPoint(ofRandom(20, 0));
    
    t = ofPoint(ofGetWidth()/3, ofGetHeight()/3, 0);
    
    ofSetVerticalSync(true);
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F); // higher precision alpha (no artifacts)
    
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    ofSetBackgroundColor(0);

}


    


void wave::update(){
    
    float time = ofGetElapsedTimef();

  
    rX = ofSignedNoise(time * 0.5) * 180.0;  // rotate +- 400deg
    rY = ofSignedNoise(time * 0.3) * 180.0;
    rZ = ofSignedNoise(time * 0.9) * 180.0;

//    float x = ofMap(ofSignedNoise(time * 0.2), -1, 1, 0, ofGetWidth());
//    float y = ofMap(ofSignedNoise(time * 0.4), -1, 1, 0, ofGetHeight());
//    float z = ofMap(ofSignedNoise(time * 0.6), -1, 1, -800, 800);
    
    float x = ofSignedNoise(time * 0.8) * ofRandom(1, 50);
    float y = ofSignedNoise(time * 0.1) * ofRandom(1, 50);
    float z = ofSignedNoise(time * 0.5) * ofRandom(1, 50);


     t += ofPoint(x, y, z);
    
    
}


void wave::draw(){
    
    fbo.begin();
    ofSetColor(0,0,0,1);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(color);

    ofPushMatrix();
        ofTranslate(t);
        ofRotateX(rX);
        ofRotateY(rY);
        ofRotateZ(rZ);
    
    ofDrawLine(p1, p2);

    ofPopMatrix();
    
    fbo.end();
    
    ofSetColor(255,255,255);  // always set the color before drawing the fbo
    fbo.draw(255,0);
   
    
}
