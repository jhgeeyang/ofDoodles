#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetWindowTitle("OF");
	ofBackground(20);
	
	this-> fbo.allocate(ofGetWidth(),ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
	this-> fbo.begin();
	ofClear(0);

	for(int x=0; x< ofGetWidth(); x+=20){
		int y = ofNoise(x*0.005 + ofGetFrameNum()*0.015)*ofGetHeight();
		ofDrawCircle(x,y,7);
		ofDrawCircle(x+30,y,7);
		ofDrawCircle(x+50,y,7);

		ofDrawLine(ofVec2f(x,y),ofVec2f(x,ofGetHeight()/2));
		ofDrawLine(ofVec2f(x+30,y),ofVec2f(x+30,ofGetHeight()/2));
		ofDrawLine(ofVec2f(x+50,y),ofVec2f(x+50,ofGetHeight()/2));
	
	}
	this-> fbo.end();

}

//--------------------------------------------------------------
void ofApp::draw(){

	this-> fbo.draw(0,0);
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
