//
//  wave.h
//  Assignment_Week7_2
//
//  Created by Mehtap Aydin on 4/5/17.
//
//
#include "ofMain.h"
#include "ofApp.h"

#ifndef wave_h
#define wave_h

class wave {
    
public:
    wave();
    void setup();
    void update();
    void draw();
    ofPoint loc;
    ofPoint p1;
    ofPoint p2;
    ofPoint t;
    ofPoint lctn;
    
    ofFbo fbo;
    ofColor color;
    ofColor black;

    
private:
    
    float time = ofGetElapsedTimef();

    
    float sTime;	// start time
    float sWeight;      // scale weight
    float fallSpeed;	// how fast to fall
    float fallWiggle;   // back and forth
    
    float dScale;
    float dScaleX;	// delta scales
    float dScaleY;
    float dScaleZ;
    float rX;		// rotate angles
    float rY;
    float rZ;
    float x;
    float y;
    float z;
    
};

#endif /* wave_h */
