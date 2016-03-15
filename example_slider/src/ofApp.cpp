#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    slider.setup("slider", 0, 0, 100);
    slider.setShape(15, 10, ofGetWidth() - 30, 20);
    slider.addListener(this, &ofApp::onValueChangeSlider);
    slider = ofRandom(slider.getMin(), slider.getMax());

    scrollbar.setup("scrollbar", 0, 0, 100);
    scrollbar.setShape(15, 40, ofGetWidth() - 30, 20);
    scrollbar.addListener(this, &ofApp::onValueChangeScrollbar);
    scrollbar = ofRandom(scrollbar.getMin(), scrollbar.getMax());

    seekbar.setup("seekbar", 0, 0, 100);
    seekbar.setShape(15, 70, ofGetWidth() - 30, 20);
    seekbar.addListener(this, &ofApp::onValueChangeSeekbar);
    seekbar = ofRandom(seekbar.getMin(), seekbar.getMax());
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
    slider.draw();
    scrollbar.draw();
    seekbar.draw();
}
