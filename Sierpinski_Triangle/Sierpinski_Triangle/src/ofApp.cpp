#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	tri = new TriangleControl();
}

//--------------------------------------------------------------
void ofApp::update() {
	tri->Update();

}

//--------------------------------------------------------------
void ofApp::draw() {
	tri->Draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	int a = 0;

	if (key == 'S' || key == 's')
		a = 1;
	if (key == 'A' || key == 'a')
		a = -1;

	tri->GetKeyPress(a);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
