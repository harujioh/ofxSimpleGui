#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    defaultButton.setup("default", DEFAULT);
    defaultButton.setShape(15, 10, 70, 30);
    defaultButton.addListener(this, &ofApp::clickDefaultButton);

    primaryButton.setup("primary", PRIMARY);
    primaryButton.setShape(100, 10, 70, 30);
    primaryButton.addListener(this, &ofApp::clickPrimaryButton);

    successButton.setup("success", SUCCESS);
    successButton.setShape(185, 10, 70, 30);
    successButton.addListener(this, &ofApp::clickSuccessButton);

    infoButton.setup("info", INFO);
    infoButton.setShape(15, 50, 70, 30);
    infoButton.addListener(this, &ofApp::clickInfoButton);

    warningButton.setup("warning", WARNING);
    warningButton.setShape(100, 50, 70, 30);
    warningButton.addListener(this, &ofApp::clickWarningButton);

    dangerButton.setup("danger", DANGER);
    dangerButton.setShape(185, 50, 70, 30);
    dangerButton.addListener(this, &ofApp::clickDangerButton);

    ofBackground(0xffffff);
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
    defaultButton.draw();
    primaryButton.draw();
    successButton.draw();
    infoButton.draw();
    warningButton.draw();
    dangerButton.draw();
}
