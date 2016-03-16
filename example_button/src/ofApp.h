#pragma once

#include "ofMain.h"
#include "ofxSimpleGui.h"

class ofApp : public ofBaseApp {
   public:
    void setup();
    void update();
    void draw();

    void clickButton() { ofLogNotice("button"); }

   private:
    ofxSimpleButton button;
};
