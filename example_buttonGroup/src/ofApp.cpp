#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    buttonGroup1.setup("normal", 60, 20, 10);
    buttonGroup1.setPosition(15, 10);
    buttonGroup1.add("hoge1");
    buttonGroup1.add("hoge2");
    buttonGroup1.addListener(this, &ofApp::changeButtonGroup1);

    buttonGroup2.setup("normal", 60, 20, 10);
    buttonGroup2.setPosition(90, 10);
    buttonGroup2.add("hoge1");
    buttonGroup2.add("hoge2");
    buttonGroup2.addListener(this, &ofApp::changeButtonGroup2);

    ofBackground(0xffffff);
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
    buttonGroup1.draw();
    buttonGroup2.draw();
}
