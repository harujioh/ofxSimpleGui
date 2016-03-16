#include "ofxSimpleButton.h"

ofxSimpleButton::ofxSimpleButton() { registerMouseEvents(); }

ofxSimpleButton* ofxSimpleButton::setup(const std::string& name, ButtonType type, float width, float height) {
    this->name = name;
    this->value = false;
    setSize(width, height);
    setButtonType(type);

    return this;
}

void ofxSimpleButton::setButtonType(ButtonType type) {
    switch (type) {
        case PRIMARY:
            backgroundColor = ofColor(0x33, 0x7a, 0xb7);
            borderColor = ofColor(0x2e, 0x6d, 0xa4);
            backgroundHoverColor = ofColor(0x28, 0x60, 0x90);
            borderHoverColor = ofColor(0x20, 0x4d, 0x74);
            backgroundActiveColor = ofColor(0x20, 0x4d, 0x74);
            borderActiveColor = ofColor(0x12, 0x2b, 0x40);
            textColor = ofColor(0xff, 0xff, 0xff);
            break;
        case SUCCESS:
            backgroundColor = ofColor(0x5c, 0xb8, 0x5c);
            borderColor = ofColor(0x4c, 0xae, 0x4c);
            backgroundHoverColor = ofColor(0x44, 0x9d, 0x44);
            borderHoverColor = ofColor(0x39, 0x84, 0x39);
            backgroundActiveColor = ofColor(0x39, 0x84, 0x39);
            borderActiveColor = ofColor(0x25, 0x56, 0x25);
            textColor = ofColor(0xff, 0xff, 0xff);
            break;
        case INFO:
            backgroundColor = ofColor(0x5b, 0xc0, 0xde);
            borderColor = ofColor(0x46, 0xb8, 0xda);
            backgroundHoverColor = ofColor(0x31, 0xb0, 0xd5);
            borderHoverColor = ofColor(0x26, 0x9a, 0xbc);
            backgroundActiveColor = ofColor(0x26, 0x9a, 0xbc);
            borderActiveColor = ofColor(0x1b, 0x6d, 0x85);
            textColor = ofColor(0xff, 0xff, 0xff);
            break;
        case WARNING:
            backgroundColor = ofColor(0xf0, 0xad, 0x4e);
            borderColor = ofColor(0xee, 0xa2, 0x36);
            backgroundHoverColor = ofColor(0xec, 0x97, 0x1f);
            borderHoverColor = ofColor(0xd5, 0x85, 0x12);
            backgroundActiveColor = ofColor(0xd5, 0x85, 0x12);
            borderActiveColor = ofColor(0x98, 0x5f, 0x0d);
            textColor = ofColor(0xff, 0xff, 0xff);
            break;
        case DANGER:
            backgroundColor = ofColor(0xd9, 0x53, 0x4f);
            borderColor = ofColor(0xd4, 0x3f, 0x3a);
            backgroundHoverColor = ofColor(0xc9, 0x30, 0x2c);
            borderHoverColor = ofColor(0xac, 0x29, 0x25);
            backgroundActiveColor = ofColor(0xac, 0x29, 0x25);
            borderActiveColor = ofColor(0x76, 0x1c, 0x19);
            textColor = ofColor(0xff, 0xff, 0xff);
            break;
        default:
            backgroundColor = ofColor(0xff, 0xff, 0xff);
            borderColor = ofColor(0xcc, 0xcc, 0xcc);
            backgroundHoverColor = ofColor(0xe6, 0xe6, 0xe6);
            borderHoverColor = ofColor(0xad, 0xad, 0xad);
            backgroundActiveColor = ofColor(0xd4, 0xd4, 0xd4);
            borderActiveColor = ofColor(0x8c, 0x8c, 0x8c);
            textColor = ofColor(0x00, 0x00, 0x00);
            break;
    }
}

void ofxSimpleButton::resize() {
    textMesh = getTextMesh(name, b);

    update();
}

void ofxSimpleButton::update() {
    float w = rect.width - borderWidth * 2;
    float h = rect.height - borderWidth * 2;

    ofColor nowBackgroundColor = backgroundColor;
    ofColor nowBorderColor = borderColor;
    if (bActive) {
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

void ofxSimpleButton::render() {
    background.draw();

    ofSetColor(textColor);
    bindFontTexture();
    textMesh.draw();
    unbindFontTexture();
}

void ofxSimpleButton::changeValue(bool v, bool notifyEvent) {
    if (notifyEvent) {
        ofNotifyEvent(clickEvent);
    }
}

bool ofxSimpleButton::onMouseMoved(ofMouseEventArgs& args) {
    bPressed = false;
    if (rect.inside(args.x, args.y)) {
        if (!bHover) {
            bHover = true;
            update();
        }
        return true;
    }
    if (bHover) {
        bHover = false;
        update();
    }
    return false;
}

bool ofxSimpleButton::onMousePressed(ofMouseEventArgs& args) {
    if (rect.inside(args.x, args.y)) {
        if (!bPressed) {
            bPressed = true;
            bActive = true;
            update();
        }
        return true;
    }
    return false;
}

bool ofxSimpleButton::onMouseDragged(ofMouseEventArgs& args) {
    if (bPressed) {
        bool bInside = rect.inside(args.x, args.y);
        if (bInside != bActive) {
            bActive = bInside;
            update();
        }
        return true;
    }
    return false;
}

bool ofxSimpleButton::onMouseReleased(ofMouseEventArgs& args) {
    bool bClick = false;
    bool bInside = rect.inside(args.x, args.y);
    bool bUpdate = false;

    if (bHover != bInside) {
        bHover = bInside;
        bUpdate = true;
    }
    if (bPressed) {
        bClick = true;
        bPressed = false;
        bActive = false;
        bUpdate = true;
    }
    if (bUpdate) {
        update();
    }
    if (bClick && bInside) {
        changeValue(true);
        return true;
    }
    return false;
}

ofxSimpleButton::operator const bool&() { return value; }
