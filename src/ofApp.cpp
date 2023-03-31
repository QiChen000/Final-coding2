#include "ofApp.h"
using namespace ofxCv;


//--------------------------------------------------------------
void ofApp::setup(){
    cam.setup(640,480);
    
    tracker.setup();

}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if(cam.isFrameNew()){
        tracker.update(toCv(cam));
        if(tracker.getFound()){
            facePoints = tracker.getImagePoints();
        }
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.draw(0,0);
    if(tracker.getFound()){
        tracker.draw();
        for(int i=0; i < facePoints.size(); i++){
            ofDrawCircle(facePoints[i], 3);
            ofDrawBitmapString(i,facePoints[i]);
        }
    }

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
