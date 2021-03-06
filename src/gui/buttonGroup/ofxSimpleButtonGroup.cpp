#include "ofxSimpleButtonGroup.h"

ofxSimpleButtonGroup::~ofxSimpleButtonGroup() {
    for (auto it = buttons.begin(); it != buttons.end(); ++it) {
        delete *it;
    }
}

ofxSimpleButtonGroup* ofxSimpleButtonGroup::setup(const std::string& name, float buttonWidth, float buttonHeight, float buttonMargin) {
    this->name = name;
    this->buttonWidth = buttonWidth;
    this->buttonHeight = buttonHeight;
    this->buttonMargin = buttonMargin;
    setSize(0, 0);

    ofxSimpleButton::addAllListener(this, &ofxSimpleButtonGroup::clickedButton);

    return this;
}

void ofxSimpleButtonGroup::resize() {}

void ofxSimpleButtonGroup::update() {}

void ofxSimpleButtonGroup::render() {
    for (auto it = buttons.begin(); it != buttons.end(); ++it) {
        (*it)->draw();
    }
}

void ofxSimpleButtonGroup::add(ofxSimpleButton* button) {
    if (buttons.size() == 0) {
        button->setShape(b.x, b.y + b.height, buttonWidth, buttonHeight);
        value = button;
    } else {
        button->setShape(b.x, b.y + b.height + buttonMargin, buttonWidth, buttonHeight);
    }
    buttons.push_back(button);

    setSize(buttonWidth, b.height + buttonMargin + buttonHeight);
}

void ofxSimpleButtonGroup::add(const std::string& name) {
    ofxSimpleButton* button = new ofxSimpleButton();
    button->setup(name);
    add(button);
}

vector<string> ofxSimpleButtonGroup::getAllName() {
    vector<string> all;
    for (ofxSimpleButton* button : buttons) {
        all.push_back(button->getName());
    }
    return all;
}

void ofxSimpleButtonGroup::clickedButton(ofxSimpleBaseGui& button) {
    for (auto it = buttons.begin(); it != buttons.end(); ++it) {
        if (*it == &button) {
            changeValue(**it);
        }
    }
}

void ofxSimpleButtonGroup::changeValue(ofxSimpleButton& button, bool notifyEvent) {
    value = &button;
    if (notifyEvent) {
        string name = button.getName();
        ofNotifyEvent(changeEvent, name);
    }
}
