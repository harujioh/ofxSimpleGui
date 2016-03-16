#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    button.setup("button");
    button.setShape(15, 10, 100, 20);
    button.addListener(this, &ofApp::clickButton);

    ofBackground(0xffffff);
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
    button.draw();  //
}
