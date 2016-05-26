#pragma once

#include "ofxSimpleButtonGroup.h"
#include "ofxRadioButton.h"

class ofxRadioButtonGroup : public ofxSimpleButtonGroup {
   public:
    ofxRadioButtonGroup() {}
    virtual ~ofxRadioButtonGroup() {}

    virtual void add(const std::string& name, bool selected = false) {
        ofxSimpleButton* button = new ofxRadioButton();
        button->setup(name);
        ofxSimpleButtonGroup::add(button);

        if (buttons.size() == 1 || selected) {
            changeValue(*(ofxRadioButton*)button);
        }
    }

    string operator=(string v) {
        for (auto it = buttons.begin(); it != buttons.end(); ++it) {
            if ((*it)->getName() == v) {
                changeValue(**it);
                break;
            }
        }
        update();
        return v;
    }
    operator const string&() {
        stringValue = value->getName();
        return stringValue;
    }

   protected:
    virtual void changeValue(ofxSimpleButton& button, bool notifyEvent = true) {
        value = &button;
        for (auto it = buttons.begin(); it != buttons.end(); ++it) {
            (*(ofxRadioButton*)*it) = *it == &button;
        }

        if (notifyEvent) {
            string name = button.getName();
            ofNotifyEvent(changeEvent, name);
        }
    }

    string stringValue;
};