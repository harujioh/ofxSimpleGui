#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    button1.setup("button1");
    button1.setShape(15, 10, 100, 30);
    button1.addListener(this, &ofApp::clickButton1);

    button2.setup("button2");
    button2.setShape(130, 10, 100, 30);
    button2.addListener(this, &ofApp::clickButton2);

    ofBackground(0xffffff);
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
    button1.draw();  //
    button2.draw();  //
}
