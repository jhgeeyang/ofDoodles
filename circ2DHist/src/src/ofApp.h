#pragma once
#include "ofMain.h"
#include "ofFbo.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

	// mistake not to include the header	
		ofFbo fbo;
		
};
