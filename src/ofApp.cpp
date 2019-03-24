#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetWindowTitle("OF");

	ofBackground(220);
	ofSetColor(39);
	ofSetLineWidth(5);

}

//--------------------------------------------------------------
void ofApp::update(){
	ofSeedRandom(60);

}

//--------------------------------------------------------------
void ofApp::draw(){
	int span =60;
	for( int x = span* 0.5; x <ofGetWidth(); x += span){
	
		for( int y = span* 1.5; y <ofGetHeight(); y += span){
			int len = ofMap(ofNoise(x*0.005,y*0.005,ofGetFrameNum()*0.01),0,1,0
					, span* 0.75);
			// Cross w/ strech
			//Rotate?
		//	ofRotateZ(10);
		
			ofDrawLine(x-len,y,x+len,y);
			ofDrawLine(x,y-len,x,y+len);
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
