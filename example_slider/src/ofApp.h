#pragma once

#include "ofMain.h"
#include "ofxSimpleGui.h"

class ofApp : public ofBaseApp {
   public:
    void setup();
    void update();
    void draw();

    void onValueChangeSlider(int &value) { ofLogNotice("slider") << value; }
    void onValueChangeScrollbar(int &value) { ofLogNotice("scrollbar") << value; }
    void onValueChangeSeekbar(int &value) { ofLogNotice("seekbar") << value; }

   private:
    ofxSimpleIntSlider slider;
    ofxIntScrollbar scrollbar;
    ofxIntSeekbar seekbar;
};
