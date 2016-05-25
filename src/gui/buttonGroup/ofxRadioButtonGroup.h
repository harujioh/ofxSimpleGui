#pragma once

#include "ofxSimpleButtonGroup.h"
#include "ofxRadioButton.h"

class ofxRadioButtonGroup : public ofxSimpleButtonGroup {
   public:
    ofxRadioButtonGroup() {}
    virtual ~ofxRadioButtonGroup() {}

    virtual void add(const std::string& name) { add(name, buttonMargin); }
    virtual void add(const std::string& name, float margin) {
        ofxSimpleButton* button = new ofxRadioButton();
        button->setup(name);

        if (buttons.size() == 0) {
            *(ofxRadioButton*)button = true;
        }
        ofxSimpleButtonGroup::add(button, margin);
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
        for (auto it = buttons.begin(); it != buttons.end(); ++it) {
            (*(ofxRadioButton*)*it) = *it == &button;
        }

        value = &button;
        if (notifyEvent) {
            string name = button.getName();
            ofNotifyEvent(changeEvent, name);
        }
    }

    string stringValue;
};