#pragma once

#include "ofMain.h"
#include "ofxSimpleGui.h"

class ofApp : public ofBaseApp {
   public:
    void setup();
    void update();
    void draw();

    void changeButtonGroup1(string &name) { ofLogNotice("group1") << name; }
    void changeButtonGroup2(string &name) { ofLogNotice("group2") << name; }

   private:
    ofxSimpleButtonGroup buttonGroup1;
    ofxSimpleButtonGroup buttonGroup2;
};
