#pragma once

#include "ofxToggleButton.h"

class ofxRadioButton : public ofxToggleButton {
   public:
    ofxRadioButton() {}
    virtual ~ofxRadioButton(){};

    ofxRadioButton* setup(const std::string& name, float width = defaultWidth, float height = defaultHeight) { ofxToggleButton::setup(name, OTHER, width, height); }

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
        if (value) {
            nowBackgroundColor = backgroundOnColor;
        } else if (bActive) {
            nowBackgroundColor = backgroundActiveColor;
            nowBorderColor = borderActiveColor;
        } else if (bHover) {
            nowBackgroundColor = backgroundHoverColor;
            nowBorderColor = borderHoverColor;
        }

        background.clear();
        background.setFilled(true);
        background.setFillColor(nowBackgroundColor);
        background.setStrokeColor(nowBorderColor);
        background.setStrokeWidth(borderWidth);
        background.moveTo(rect.x + rect.width, rect.y + rect.height / 2);
        background.ellipse(rect.x + rect.width / 2, rect.y + rect.height / 2, rect.width, rect.height);
        background.close();
    }

    virtual void changeValue(bool notifyEvent = true) {
        if (!value) {
            ofxToggleButton::changeValue(notifyEvent);
        }
    }
};
