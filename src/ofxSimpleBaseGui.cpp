#include "ofxSimpleBaseGui.h"

ofxSimpleBaseGui::ofxSimpleBaseGui() { ofxSimpleBaseGui::loadFont(OF_TTF_MONO, 10, true, true); }

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

void ofxSimpleBaseGui::bindFontTexture() {
    if (useTTF) {
        font.getFontTexture().bind();
    } else {
        bitmapFont.getTexture().bind();
    }
}

void ofxSimpleBaseGui::unbindFontTexture() {
    if (useTTF) {
        font.getFontTexture().unbind();
    } else {
        bitmapFont.getTexture().unbind();
    }
}

void ofxSimpleBaseGui::draw() { render(); }

std::string ofxSimpleBaseGui::getName() { return name; }

void ofxSimpleBaseGui::setName(const std::string& name) { this->name = name; }

void ofxSimpleBaseGui::setPosition(const ofPoint& p) {
    b.x = p.x;
    b.y = p.y;
    resizeRect();
}

void ofxSimpleBaseGui::setPosition(float x, float y) {
    b.x = x;
    b.y = y;
    resizeRect();
}

void ofxSimpleBaseGui::setSize(float w, float h) {
    b.width = w;
    b.height = h;
    resizeRect();
}

void ofxSimpleBaseGui::setShape(ofRectangle r) {
    b = r;
    resizeRect();
}

void ofxSimpleBaseGui::setShape(float x, float y, float w, float h) {
    b.set(x, y, w, h);
    resizeRect();
}

ofPoint ofxSimpleBaseGui::getPosition() const { return ofPoint(b.x, b.y); }

ofRectangle ofxSimpleBaseGui::getShape() const { return b; }

float ofxSimpleBaseGui::getWidth() const { return b.width; }

float ofxSimpleBaseGui::getHeight() const { return b.height; }

void ofxSimpleBaseGui::resizeRect() {
    rect.set(b.x, b.y, b.width + p.x + p.width, b.height + p.y + p.height);
    resize();
}

ofColor ofxSimpleBaseGui::getBackgroundColor() const { return backgroundColor; }

ofColor ofxSimpleBaseGui::getBorderColor() const { return borderColor; }

ofColor ofxSimpleBaseGui::getTextColor() const { return textColor; }

float ofxSimpleBaseGui::getBorderWidth() const { return borderWidth; }

void ofxSimpleBaseGui::setBackgroundColor(const ofColor& color) { backgroundColor = color; }

void ofxSimpleBaseGui::setBorderColor(const ofColor& color) { borderColor = color; }

void ofxSimpleBaseGui::setTextColor(const ofColor& color) { textColor = color; }

void ofxSimpleBaseGui::setBorderWidth(const float& width) { borderWidth = width; }

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

void ofxSimpleBaseGui::loadFont(const std::string& filename, int fontsize, bool antiAliased, bool fullCharacterSet, int dpi) {
    ofxSimpleBaseGui::font.load(filename, fontsize, antiAliased, fullCharacterSet, false, 0, dpi);
    ofxSimpleBaseGui::useTTF = true;
}

ofMesh ofxSimpleBaseGui::getTextMesh(const string& text, float x, float y) {
    if (useTTF) {
        return font.getStringMesh(text, x, y);
    } else {
        return bitmapFont.getMesh(text, x, y);
    }
}

ofMesh ofxSimpleBaseGui::getTextMesh(const string& text, ofRectangle rect, Align align, Valign valign) {
    ofRectangle textRect = getTextBoundingBox(text);

    float x;
    if (align == Align::LEFT) {
        x = rect.x;
    } else if (align == Align::RIGHT) {
        x = rect.x + rect.width - textRect.width;
    } else {
        x = rect.x + (rect.width - textRect.width) / 2;
    }

    float y;
    if (valign == Valign::TOP) {
        y = rect.y + textRect.height;
    } else if (valign == Valign::BOTTOM) {
        y = rect.y + rect.height;
    } else {
        y = rect.y + (rect.height + textRect.height) / 2;
    }
    return getTextMesh(text, x, y);
}

ofRectangle ofxSimpleBaseGui::getTextBoundingBox(const string& text, float x, float y) {
    if (useTTF) {
        return font.getStringBoundingBox(text, x, y);
    } else {
        return bitmapFont.getBoundingBox(text, x, y);
    }
}

ofTrueTypeFont ofxSimpleBaseGui::font;
bool ofxSimpleBaseGui::useTTF = false;

int ofxSimpleBaseGui::defaultWidth = 200;
int ofxSimpleBaseGui::defaultHeight = 20;
ofColor ofxSimpleBaseGui::defaultBackgroundColor = ofColor(255, 255, 255, 0);
ofColor ofxSimpleBaseGui::defaultBorderColor = ofColor(0, 0, 0);
ofColor ofxSimpleBaseGui::defaultTextColor = ofColor(0, 0, 0);
float ofxSimpleBaseGui::defaultBorderWidth = 1;
