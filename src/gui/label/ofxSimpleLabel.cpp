#include "ofxSimpleLabel.h"

// ofxSimpleLabel* ofxSimpleLabel::setup(const std::string& name) {
//    this->name = name;
//    this->value = name;
//    this->resizeWithText = true;
//
//    return this;
//}

ofxSimpleLabel* ofxSimpleLabel::setup(const std::string& name, float width, float height) {
    this->name = name;
    this->value = name;
    this->resizeWithText = false;
    setSize(width, height);

    return this;
}

void ofxSimpleLabel::update() {
    background.clear();
    background.setFilled(true);
    background.setFillColor(backgroundColor);
    background.setStrokeColor(borderColor);
    background.setStrokeWidth(borderWidth);
    background.rectangle(rect);

    textMesh = getTextMesh(ofToString(value), b, align, valign);
}

void ofxSimpleLabel::render() {
    background.draw();

    ofSetColor(textColor);
    bindFontTexture();
    textMesh.draw();
    unbindFontTexture();
}

string ofxSimpleLabel::operator=(string v) {
    value = v;
    update();
    return v;
}

ofxSimpleLabel::operator const string&() { return value; }
