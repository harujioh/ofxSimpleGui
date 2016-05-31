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
    void update() {
        ofColor nowBackgroundColor = backgroundColor;
        ofColor nowBorderColor = borderColor;
        if (bActive) {
            nowBackgroundColor = backgroundActiveColor;
            nowBorderColor = borderActiveColor;
        } else if (bHover) {
            nowBorderColor = borderHoverColor;
        }

        background.clear();
        background.setFilled(true);
        background.setFillColor(nowBackgroundColor);
        background.setStrokeColor(nowBorderColor);
        background.setStrokeWidth(borderWidth);
        background.rectangle(rect);

        check.clear();
        if (value) {
            check.setFilled(false);
            check.setStrokeColor(backgroundOnColor);
            check.setStrokeWidth(2);
            check.moveTo(rect.x + rect.width * 2 / 10, rect.y + rect.height * 6 / 10);
            check.lineTo(rect.x + rect.width * 4 / 10, rect.y + rect.height * 8 / 10);
            check.lineTo(rect.x + rect.width * 8 / 10, rect.y + rect.height * 2 / 10);
        }
    }

    virtual void render() {
        background.draw();
        check.draw();
    }

    ofPath check;
};
