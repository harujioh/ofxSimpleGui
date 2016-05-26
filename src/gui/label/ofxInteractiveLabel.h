#pragma once

#include "ofxSimpleLabel.h"

class ofxInteractiveLabel : public ofxSimpleLabel {
   public:
    virtual void update() {
        background.clear();
        background.setFilled(true);
        background.setFillColor(firstDrawn ? backgroundInteractiveColor : backgroundColor);
        background.setStrokeColor(borderColor);
        background.setStrokeWidth(borderWidth);
        background.rectangle(rect);

        textMesh = getTextMesh(ofToString(value), b, align, valign);

        if (firstDrawn) {
            lastUpdateMillis = ofGetElapsedTimeMillis();
        }
    }

    virtual void render() {
        uint64_t now = ofGetElapsedTimeMillis();
        if (lastUpdateMillis > 0) {
            if (lastUpdateMillis + interactiveTime < now) {
                updateBackground(backgroundColor);
                lastUpdateMillis = 0;
            } else {
                float rate = (float)(now - lastUpdateMillis) / interactiveTime;
                int r = backgroundInteractiveColor.r * (1.0f - rate) + backgroundColor.r * rate;
                int g = backgroundInteractiveColor.g * (1.0f - rate) + backgroundColor.g * rate;
                int b = backgroundInteractiveColor.b * (1.0f - rate) + backgroundColor.b * rate;
                int a = backgroundInteractiveColor.a * (1.0f - rate) + backgroundColor.a * rate;

                updateBackground(ofColor(r, g, b, a));
            }
        }
        background.draw();

        ofSetColor(textColor);
        bindFontTexture();
        textMesh.draw();
        unbindFontTexture();

        if (!firstDrawn) {
            firstDrawn = true;
        }
    }

    string operator=(string v) {
        if (value != v) {
            value = v;
            update();
        }
        return v;
    }

    operator const string&() { return value; }

    static void setDefaultInteractiveTime(const int& defaultInteractiveTime) { ofxInteractiveLabel::defaultInteractiveTime = defaultInteractiveTime; }
    static void setDefaultBackgroundColor(const ofColor& defaultBackgroundColor) { ofxInteractiveLabel::defaultBackgroundColor = defaultBackgroundColor; }
    static void setDefaultBackgroundInteractiveColor(const ofColor& defaultBackgroundInteractiveColor) { ofxInteractiveLabel::defaultBackgroundInteractiveColor = defaultBackgroundInteractiveColor; }

   protected:
    uint64_t lastUpdateMillis = 0;
    int interactiveTime = defaultInteractiveTime;
    ofColor backgroundColor = defaultBackgroundColor;
    ofColor backgroundInteractiveColor = defaultBackgroundInteractiveColor;

    bool firstDrawn = false;

    static int defaultInteractiveTime;
    static ofColor defaultBackgroundColor;
    static ofColor defaultBackgroundInteractiveColor;

    void updateBackground(ofColor nowBackgroundColor) {
        background.clear();
        background.setFilled(true);
        background.setFillColor(nowBackgroundColor);
        background.setStrokeColor(borderColor);
        background.setStrokeWidth(borderWidth);
        background.rectangle(rect);
    }
};