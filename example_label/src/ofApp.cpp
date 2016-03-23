#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofxSimpleBaseGui::loadFont();

    label.setup("", 100);
    label.setPosition(20, 20);
    label.setBackgroundColor(ofColor::white);
}

//--------------------------------------------------------------
void ofApp::update() {
    uint64_t now = ofGetElapsedTimeMillis();
    if (lastInteractiveMillis == 0 || lastInteractiveMillis + interactiveInterval <= now) {
        lastInteractiveMillis = now;

        label = ofToString(now);
    }
}

//--------------------------------------------------------------
void ofApp::draw() { label.draw(); }
