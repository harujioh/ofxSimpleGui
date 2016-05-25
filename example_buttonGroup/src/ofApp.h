#pragma once

#include "ofMain.h"
#include "ofxSimpleGui.h"

class ofApp : public ofBaseApp {
   public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);

    void changeButtonGroup1(string &name) { ofLogNotice("group1") << name; }
    void changeButtonGroup2(string &name) { ofLogNotice("group2") << name; }
    void changeRadioGroup1(string &name) { ofLogNotice("radio") << name; }
    void changeCheckGroup2(vector<string> &names) { ofLogNotice("check") << names.size(); }

   private:
    ofxSimpleButtonGroup buttonGroup1;
    ofxSimpleButtonGroup buttonGroup2;
    ofxRadioButtonGroup radioGroup;
    ofxCheckBoxGroup checkGroup;
};
