#pragma once

#include "ofMain.h"
//#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		// define this func
		ofImage wave(ofImage sourceImg);
		ofImage image1; // orig
		ofImage image2; // modified
	private: 
		float wavelength = 0.05;
		float amplitude = 40.0;
		float noiseScale = 8.9;
		float distortion = 25;
		float ySpeed  = 4.0;
};
