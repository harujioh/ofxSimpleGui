#pragma once

#include "ofMain.h"
#include "ofxSimpleGui.h"

class ofApp : public ofBaseApp {
   public:
    void setup();
    void update();
    void draw();

    void clickDefaultButton() { ofLogNotice("default"); }
    void clickPrimaryButton() { ofLogNotice("primary"); }
    void clickSuccessButton() { ofLogNotice("success"); }
    void clickInfoButton() { ofLogNotice("info"); }
    void clickWarningButton() { ofLogNotice("warning"); }
    void clickDangerButton() { ofLogNotice("danger"); }

   private:
    ofxSimpleButton defaultButton;
    ofxSimpleButton primaryButton;
    ofxSimpleButton successButton;
    ofxSimpleButton infoButton;
    ofxSimpleButton warningButton;
    ofxSimpleButton dangerButton;
};
