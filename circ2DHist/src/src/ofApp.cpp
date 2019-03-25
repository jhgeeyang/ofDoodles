#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");
	this->fbo.allocate(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update() {
	int deg_span = 10;
	float radius = 30;
	float radius_span = 15;

	this->fbo.begin();
	ofClear(0);

	for (int deg = 0; deg < 360; deg += deg_span) {
		radius = 100;
		int layer = ofNoise(radius * cos(deg * DEG_TO_RAD) * 0.025, radius * sin(deg * DEG_TO_RAD) * 0.025, ofGetFrameNum() * 0.005) * 15 + 1;
		for (int i = 0; i < layer; i++) {

// When you use ofVertex - call it between Begin & End
			ofNoFill();
			ofSetColor(230,0,0);
			ofBeginShape();
			
			// Current Deg
			for (int tmp_deg = deg; tmp_deg <= deg + deg_span; tmp_deg += 1) {
				ofVertex(radius * cos(tmp_deg * DEG_TO_RAD) + ofGetWidth() / 2, radius * sin(tmp_deg * DEG_TO_RAD) + ofGetHeight() / 2);
			}
			// Next step Deg
			for (int tmp_deg = deg + deg_span; tmp_deg >= deg; tmp_deg -= 1) {
				ofVertex((radius + radius_span) * cos(tmp_deg * DEG_TO_RAD) + ofGetWidth() / 2, (radius + radius_span) * sin(tmp_deg * DEG_TO_RAD) + ofGetHeight() / 2);
			}
			
			ofEndShape(true);

			// next radius for next array
			radius += radius_span;
		}
	}

	this->fbo.end();
}

//--------------------------------------------------------------
void ofApp::draw() {
// center of the canvas
	this->fbo.draw(0, 0);
}

//--------------------------------------------------------------
