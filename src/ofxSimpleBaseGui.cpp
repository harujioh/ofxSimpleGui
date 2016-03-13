#include "ofxSimpleBaseGui.h"

ofxSimpleBaseGui::~ofxSimpleBaseGui() { unregisterMouseEvents(); }

void ofxSimpleBaseGui::registerMouseEvents() {
    if (bRegisteredForMouseEvents) {
        return;
    }
    bRegisteredForMouseEvents = true;
    ofRegisterMouseEvents(this, OF_EVENT_ORDER_BEFORE_APP);
}

void ofxSimpleBaseGui::unregisterMouseEvents() {
    if (!bRegisteredForMouseEvents) {
        return;
    }
    ofUnregisterMouseEvents(this, OF_EVENT_ORDER_BEFORE_APP);
    bRegisteredForMouseEvents = false;
}

void ofxSimpleBaseGui::draw() { render(); }

std::string ofxSimpleBaseGui::getName() { return name; }

void ofxSimpleBaseGui::setName(const std::string& name) { this->name = name; }

void ofxSimpleBaseGui::setPosition(const ofPoint& p) {
    b.x = p.x;
    b.y = p.y;
    resize();
}

void ofxSimpleBaseGui::setPosition(float x, float y) {
    b.x = x;
    b.y = y;
    resize();
}

void ofxSimpleBaseGui::setSize(float w, float h) {
    b.width = w;
    b.height = h;
    resize();
}

void ofxSimpleBaseGui::setShape(ofRectangle r) {
    b = r;
    resize();
}

void ofxSimpleBaseGui::setShape(float x, float y, float w, float h) {
    b.set(x, y, w, h);
    resize();
}

ofPoint ofxSimpleBaseGui::getPosition() const { return ofPoint(b.x, b.y); }

ofRectangle ofxSimpleBaseGui::getShape() const { return b; }

float ofxSimpleBaseGui::getWidth() const { return b.width; }

float ofxSimpleBaseGui::getHeight() const { return b.height; }

void ofxSimpleBaseGui::resize() { rect.set(b.x, b.y, b.width + p.x + p.width, b.height + p.y + p.height); }

ofColor ofxSimpleBaseGui::getBackgroundColor() const { return backgroundColor; }

ofColor ofxSimpleBaseGui::getBorderColor() const { return borderColor; }

ofColor ofxSimpleBaseGui::getTextColor() const { return textColor; }

void ofxSimpleBaseGui::setBackgroundColor(const ofColor& color) { backgroundColor = color; }

void ofxSimpleBaseGui::setBorderColor(const ofColor& color) { borderColor = color; }

void ofxSimpleBaseGui::setTextColor(const ofColor& color) { textColor = color; }

void ofxSimpleBaseGui::setParent(ofxSimpleBaseGui* parent) { parent = parent; }

ofxSimpleBaseGui* ofxSimpleBaseGui::getParent() { return parent; }

bool ofxSimpleBaseGui::mouseMoved(ofMouseEventArgs& args) {
    bool result = onMouseMoved(args);
    return result;
}

bool ofxSimpleBaseGui::mousePressed(ofMouseEventArgs& args) {
    bool result = onMousePressed(args);
    return result;
}

bool ofxSimpleBaseGui::mouseDragged(ofMouseEventArgs& args) {
    bool result = onMouseDragged(args);
    return result;
}

bool ofxSimpleBaseGui::mouseReleased(ofMouseEventArgs& args) {
    bool result = onMouseReleased(args);
    return result;
}

bool ofxSimpleBaseGui::mouseScrolled(ofMouseEventArgs& args) {
    bool result = onMouseScrolled(args);
    return result;
}

bool ofxSimpleBaseGui::onMouseMoved(ofMouseEventArgs& args) { return rect.inside(args.x, args.y); }

bool ofxSimpleBaseGui::onMousePressed(ofMouseEventArgs& args) { return rect.inside(args.x, args.y); }

bool ofxSimpleBaseGui::onMouseDragged(ofMouseEventArgs& args) { return rect.inside(args.x, args.y); }

bool ofxSimpleBaseGui::onMouseReleased(ofMouseEventArgs& args) { return rect.inside(args.x, args.y); }

bool ofxSimpleBaseGui::onMouseScrolled(ofMouseEventArgs& args) { return rect.inside(args.x, args.y); }
