#pragma once

#include "ofxSimpleButton.h"

class ofxToggleButton : public ofxSimpleButton {
   public:
    ofxToggleButton() {}
    virtual ~ofxToggleButton(){};

    bool operator=(bool v) {
        value = v;
        update();
        return v;
    }
    operator const bool&() { return value; }

   protected:
    bool value = false;

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
        background.rectangle(rect);
    }

    virtual void render() { background.draw(); }

    ofColor backgroundOnColor = ofColor(64, 64, 64);

    virtual void changeValue(bool notifyEvent = true) {
        value = !value;
        update();

        if (notifyEvent) {
            ofNotifyEvent(clickAllEvent, *this);
            ofNotifyEvent(clickEvent);
        }
    }
};
