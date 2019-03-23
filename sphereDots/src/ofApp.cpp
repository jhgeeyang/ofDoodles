#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetWindowTitle("OF");

	ofBackground(239);
	ofSetColor(39);
	ofEnableDepthTest();
	ofSetLineWidth(1.4);
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSeedRandom(39);
	// locations in header(vector - glm3)
	this->locations.clear();
	int radius = 300;
	for(int i = 0; i< 500; i ++){
	
		auto base_location = glm::vec3(ofRandom(-radius,radius), (int)(ofRandom(-radius, radius) + ofGetFrameNum()*5)%(radius*2) - radius, ofRandom(-radius,radius));
		// vec3 is the point on raidus
		double randVal =20;
		glm::vec3 randAdd = glm::vec3(ofRandom(-randVal,randVal),ofRandom(100,0.1),ofRandom(-0.1,0.1));


		//glm::vec3 location = glm::normalize(base_location)*radius+randAdd;
		glm::vec3 location = glm::normalize(base_location)*radius;
		auto rotation_y = glm::rotate(glm::mat4(), ofMap(ofGetFrameNum()%300, 0, 300, -PI, PI), glm::vec3(0,1,0));
		location = glm::vec4(location,0)*rotation_y;
		this -> locations.push_back(location);
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	this -> cam.begin();
	ofRotateX(180);
	
	// draw 4 ever thing in locations vec
	// RadomValue - outward vector wiggle on sphere. 
	for(auto& location : this -> locations){
		// the point size 
		ofSetColor(ofRandom(0,200),24,9);
		ofDrawSphere(location ,5);
		
		for(auto& other: this -> locations){
			if(location == other) {continue;}
			float distance = glm::distance(location, other);
			if(distance <100){
				ofDrawLine(location, other);
			}
		}
	}
	this -> cam.end();

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
