#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    buttonGroup1.setup("normal", 60, 20, 10);
    buttonGroup1.setPosition(10, 10);
    buttonGroup1.add("hoge1");
    buttonGroup1.add("hoge2");
    buttonGroup1.addListener(this, &ofApp::changeButtonGroup1);

    buttonGroup2.setup("normal", 60, 20, 10);
    buttonGroup2.setPosition(90, 10);
    buttonGroup2.add("hoge1");
    buttonGroup2.add("hoge2");
    buttonGroup2.addListener(this, &ofApp::changeButtonGroup2);

    radioGroup.setup("radio", 20, 20, 10);
    radioGroup.setPosition(170, 10);
    radioGroup.add("hoge1");
    radioGroup.add("hoge2");
    radioGroup.addListener(this, &ofApp::changeRadioGroup1);

    checkGroup.setup("check", 20, 20, 10);
    checkGroup.setPosition(250, 10);
    checkGroup.add("hoge1");
    checkGroup.add("hoge2");
    checkGroup.addListener(this, &ofApp::changeCheckGroup2);

    ofBackground(0xffffff);
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
    buttonGroup1.draw();
    buttonGroup2.draw();
    radioGroup.draw();
    checkGroup.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == '0') {
        radioGroup = "hoge1";

        vector<string> checkValues;
        checkValues.push_back("hoge1");
        checkGroup = checkValues;
    } else {
        string radioValue = radioGroup;
        ofLogNotice("radio") << radioValue;

        vector<string> checkValues = checkGroup;
        for (string checkValue : checkValues) {
            ofLogNotice("check") << checkValue;
        }
    }
}