#include "ofxSimpleLabel.h"

ofxSimpleLabel* ofxSimpleLabel::setup(const std::string& name, float width, float height) {
    this->name = name;
    this->value = false;
    setSize(width, height);

    return this;
}


void ofxSimpleLabel::resize() {
    textMesh = getTextMesh(name, b);
    
    update();
}

void ofxSimpleLabel::update() {
    background.clear();
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
