#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetWindowTitle("oF");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(3);
	ofEnableDepthTest();

}

//--------------------------------------------------------------
void ofApp::update(){
	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw(){
	// from ofApp.cpp
	this->cam.begin();
	
	// size of the grid 
	auto size =34;
	for (int x = -500; x<=500; x+=size){
	for (int y = -500; y<=500; y+=size){

		// Random Height
		auto height = ofMap(ofNoise(x*0.005,y*0.005,ofGetFrameNum()*0.01),
0,1,50,500);
	for (int z = 0; z<=height; z+=size){
		ofColor fill_color(ofMap(z,0,500,39,239));
		ofSetColor(fill_color);
		ofDrawBox(glm::vec3(x,y,z), size-1);

		ofNoFill();
		ofSetColor(39);
		ofDrawBox(glm::vec3(x,y,z), size);


	}
	}
	}
	this->cam.end();

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
