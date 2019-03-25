#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetWindowTitle("OF");
	ofBackground(220);

	ofEnableDepthTest();

	for(int i=0; i <1024; i++)
		this->confetti.push_back(shared_ptr<Confetti>(new Confetti()));

}

//--------------------------------------------------------------
void ofApp::update(){
	for(int i=0; i < this->confetti.size(); i++)
		this->confetti[i]->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	this->cam.begin();

	ofTranslate(0, 0, -ofGetWidth()/2);
	ofRotateZ(180);
	ofTranslate(-ofGetWidth()/2, 0, -ofGetHeight()/2);
	
	for(int i=0; i < this->confetti.size(); i++)
		this->confetti[i]->draw();

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
