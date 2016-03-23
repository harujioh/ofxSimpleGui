#pragma once

class ofxInteractiveLabel : public ofxSimpleLabel {
   public:
    virtual void update() {
        background.clear();
        background.setFilled(true);
        background.setFillColor(backgroundInteractiveColor);
        background.setStrokeColor(borderColor);
        background.setStrokeWidth(borderWidth);
        background.rectangle(rect);

        textMesh = getTextMesh(ofToString(value), b, align, valign);

        lastUpdateMillis = ofGetElapsedTimeMillis();
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

                updateBackground(ofColor(r, g, b));
            }
        }
        background.draw();

        ofSetColor(textColor);
        bindFontTexture();
        textMesh.draw();
        unbindFontTexture();
    }

    string operator=(string v) {
        value = v;
        update();
        return v;
    }

    operator const string&() { return value; }

   protected:
    uint64_t lastUpdateMillis = 0;
    int interactiveTime = 250;
    ofColor backgroundInteractiveColor = ofColor::red;

    void updateBackground(ofColor nowBackgroundColor) {
        background.clear();
        background.setFilled(true);
        background.setFillColor(nowBackgroundColor);
        background.setStrokeColor(borderColor);
        background.setStrokeWidth(borderWidth);
        background.rectangle(rect);
    }
};