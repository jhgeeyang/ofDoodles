#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetWindowTitle("OF");
	
	ofBackground(239);
	ofSetColor(39);
	ofEnableDepthTest();

	this->font.loadFont("comicSans.ttf",50,true,true,true);
}

//--------------------------------------------------------------
void ofApp::update(){

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw(){
	this->cam.begin();
	ofRotateX(180);

	string word = "JIHYUN";
	for(int y= -100; y<=100; y+=50){
		float noise_seed_x = ofRandom(1000);
		float noise_seed_y = ofRandom(1000);
		auto path_list = this->font.getStringAsPoints(word,true,false);

		for(int point_index=0; point_index <path_list.size(); point_index++){

			auto outline = path_list[point_index].getOutline();
			ofBeginShape();
			for(int outline_index=0; outline_index< outline.size(); outline_index++){
				if(outline_index !=0){ ofNextContour(true);}

				outline[outline_index] = outline[outline_index].getResampledByCount(100);
				auto vertices = outline[outline_index].getVertices();
				for(int vertices_index = 0; vertices_index < vertices.size(); vertices_index++){

					auto location = glm::vec3(vertices[vertices_index].x - this->font.stringWidth(word)*0.5,y+vertices[vertices_index].y+this->font.stringHeight(word)*0.5,0);
auto rotation_y = glm::rotate(glm::mat4(), ofMap(ofNoise(noise_seed_y, ofGetFrameNum() * 0.008 + (location.y + y) * 0.0005), 0, 1, -PI * 0.5, PI * 0.5), glm::vec3(0, 1, 0));
auto rotation_x = glm::rotate(glm::mat4(), ofMap(ofNoise(noise_seed_x, ofGetFrameNum() * 0.008 + (location.x + y) * 0.0005), 1, 1, -PI * 0.5, PI * 0.5), glm::vec3(1, 0, 0));

					location = glm::vec4(location, 0)*rotation_x * rotation_y;
ofVertex(location);
				}
			}
		ofEndShape(true);
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
