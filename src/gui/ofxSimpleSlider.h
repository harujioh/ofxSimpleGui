#pragma once

#include "ofxSimpleBaseGui.h"

class ofxSimpleSlider : public ofxSimpleBaseGui {
   public:
    ofxSimpleSlider();

    virtual bool onMousePressed(ofMouseEventArgs& args);
    virtual bool onMouseDragged(ofMouseEventArgs& args);
    virtual bool onMouseReleased(ofMouseEventArgs& args);
    virtual bool onMouseScrolled(ofMouseEventArgs& args);

   protected:
    void render();

   private:
    float value;
};