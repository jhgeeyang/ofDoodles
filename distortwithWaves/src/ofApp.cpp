#include "ofApp.h"

// LETS DEFINE FUNC
ofImage ofApp::wave(ofImage sourceImg){

	ofImage newImg;

	//newImg.clone(sourceImg); DEPRECATED
	newImg = sourceImg;
	// return elapsed time
	float time = ofGetElapsedTimef();
	// iterate through every pixel in ImgArr
	// calc distortion
	// the set color val
	int height =  (int)(image1.getHeight());
	int width = (int)(image1.getHeight());
	for(int y =0; y<height; y++){
		for(int x =0; x<width; x++){
			// calc distortion
			float noise = ofNoise(time + y * 0.001) * noiseScale; // muliplier 0.001 smooths the waveform
			float noiseAmp = noise * amplitude; // rescale the noiseval
			float waveform = sin((y * wavelength) + time * ySpeed); // classic waveform - INDEED
			float wave = (waveform + distortion) *noiseAmp; // distortion(shift on x - axis)

			int xWave = x + wave; // distorted pixel location (from orig img)
			
			// set newImg color
			ofColor color = sourceImg.getColor( xWave,y);
			newImg.setColor(x,y,color);

		}
	}
	newImg.update();
	return newImg;
}
//--------------------------------------------------------------
void ofApp::setup(){
	image1.load("image/test.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){
	//img2 is now the result of the processing by wave func
	image2 = wave(image1); //WTF FUZZ?

}

//--------------------------------------------------------------
void ofApp::draw(){
	// bg color
	ofBackgroundGradient(ofColor::white, ofColor::gray);
	// draw image
	ofSetColor(255,255,250);
	image2.draw(0,0);

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
