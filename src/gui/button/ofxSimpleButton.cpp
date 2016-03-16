#include "ofxSimpleButton.h"

ofxSimpleButton::ofxSimpleButton() { registerMouseEvents(); }

ofxSimpleButton* ofxSimpleButton::setup(const std::string& name, float width, float height) {
    this->name = name;
    this->value = false;
    setSize(width, height);

    backgroundColor = ofColor(0xffffff);
    borderColor = ofColor(0xcccccc);

    return this;
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

void ofxSimpleButton::render() { background.draw(); }

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
