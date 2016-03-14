#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    slider.setup("slider", 30, 0, 100);
    slider.setShape(10, 10, ofGetWidth() - 20, 20);
    slider.addListener(this, &ofApp::onValueChange);
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() { slider.draw(); }

//--------------------------------------------------------------
void ofApp::keyPressed(int key) { slider = ofRandom(slider.getMin(), slider.getMax()); }

void ofApp::onValueChange(int& value) { ofLogNotice() << value; }