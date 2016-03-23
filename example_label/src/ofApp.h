#pragma once

#include "ofMain.h"
#include "ofxSimpleGui.h"

class ofApp : public ofBaseApp {
   public:
    void setup();
    void update();
    void draw();

   private:
    ofxInteractiveLabel label;

    uint64_t lastInteractiveMillis = 0;
    int interactiveInterval = 1000;
};
