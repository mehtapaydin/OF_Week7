#include "ofApp.h"



ofFbo fbo, spFbo;
ofColor color(100,0,200);
ofColor black(0,0,0);

float rX=0;
float rY=0;
float rZ=0;
float dScale;
float dScaleX = 1; //delta scale
float dScaleY = 1;
float dScaleZ = 1;
float sTime;	// start time
float sWeight;      // scale weight
float fallSpeed;	// how fast to fall
float fallWiggle;   // back and forth
ofPoint loc;



void ofApp::setup(){
    
    sWeight = ofRandom(-0.1, 0.2);
    fallSpeed = ofRandom(-1, 1.5);
    
    ofSetVerticalSync(true);
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F); // higher precision alpha (no artifacts)
    spFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    spFbo.begin();
    ofClear(255,255,255, 0);
    spFbo.end();
    
    ofSetBackgroundColor(black);
    
}





//--------------------------------------------------------------
void ofApp::update(){

    float time = ofGetElapsedTimef();
    rX = ofSignedNoise(time * 0.5) * 180.0;
    rY = ofSignedNoise(time * 0.3) * 180.0;
    rZ = ofSignedNoise(time * 0.9) * 180.0;
//    dScaleX = 1- ofNoise(time * 0.2);
//    dScaleY = 1- ofNoise(time * 0.4);
//    dScaleZ = 1- ofNoise(time * 0.6);
    
    fallWiggle = ofSignedNoise(time * 0.6) * ofRandom(1, 70);
    loc += ofPoint(fallWiggle, fallSpeed);

}

//--------------------------------------------------------------
void ofApp::draw(){

    fbo.begin();
        ofSetColor(0,0,0,1);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        ofSetColor(color);
    
    
    ofPushMatrix();
        float z = ofSignedNoise((ofGetElapsedTimef() + sTime) * 0.9) * 400;

        ofTranslate(loc.x, loc.y, z);
        ofRotateX(rX);
        ofRotateY(rY);
        ofRotateZ(rZ);
    
        ofDrawLine(-20, 0, 20, 0);
    ofPopMatrix();

    
    fbo.end();
    
    ofSetColor(255,255,255);  // always set the color before drawing the fbo
    fbo.draw(255,0);
    
  


    

    
  

   
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
