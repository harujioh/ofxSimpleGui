#pragma once

#include "ofMain.h"
#include "ofxSimpleGui.h"

class ofApp : public ofBaseApp {
   public:
    void setup();
    void update();
    void draw();

    void clickButton1() { ofLogNotice("button1"); }
    void clickButton2() { ofLogNotice("button2"); }

   private:
    ofxSimpleButton button1, button2;
};
