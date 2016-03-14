#pragma once

#include "ofMain.h"
#include "ofxSimpleGui.h"

class ofApp : public ofBaseApp {
   public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);

    void onValueChange(int &value);

   private:
    ofxIntSeekbar slider;
};
