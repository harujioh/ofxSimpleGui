#pragma once

#include "ofxToggleButton.h"

class ofxCheckBox : public ofxToggleButton {
   public:
    ofxCheckBox() {}
    virtual ~ofxCheckBox(){};

    ofxCheckBox* setup(const std::string& name, float width = defaultWidth, float height = defaultHeight) { ofxToggleButton::setup(name, OTHER, width, height); }

    bool operator=(bool v) {
        value = v;
        update();
        return v;
    }
    operator const bool&() { return value; }

   protected:
};
