#pragma once

#include "ofxSimpleButtonGroup.h"
#include "ofxCheckBox.h"

class ofxCheckBoxGroup : public ofxSimpleButtonGroup {
   public:
    ofxCheckBoxGroup() {}
    virtual ~ofxCheckBoxGroup() {}

    template <class ListenerClass, typename ListenerMethod>
    void addListener(ListenerClass* listener, ListenerMethod method) {
        ofAddListener(changeEvent, listener, method);
    }

    template <class ListenerClass, typename ListenerMethod>
    void removeListener(ListenerClass* listener, ListenerMethod method) {
        ofRemoveListener(changeEvent, listener, method);
    }

    virtual void add(const std::string& name, bool selected = false) {
        ofxSimpleButton* button = new ofxCheckBox();
        button->setup(name);
        ofxSimpleButtonGroup::add(button);

        *(ofxCheckBox*)button = selected;
        changeValue(*button);
    }

    const string operator=(const string s) {
        for (auto it = buttons.begin(); it != buttons.end(); ++it) {
            *(ofxCheckBox*)*it = (*it)->getName() == s;
        }
        update();
        return s;
    }

    vector<string> operator=(vector<string>& v) {
        for (auto it = buttons.begin(); it != buttons.end(); ++it) {
            for (string s : v) {
                *(ofxCheckBox*)*it = (*it)->getName() == s;
            }
        }
        update();
        return v;
    }
    operator const vector<string>&() { return values; }

    bool operator==(const string s) const {
        for (auto it = buttons.begin(); it != buttons.end(); ++it) {
            if (*(ofxCheckBox*)*it == true && (*it)->getName() == s) {
                return true;
            }
        }
        return false;
    }

    bool operator!=(const string s) const { return !(*this == s); }

   protected:
    virtual void changeValue(ofxSimpleButton& button, bool notifyEvent = true) {
        value = &button;
        values.clear();
        for (auto it = buttons.begin(); it != buttons.end(); ++it) {
            if (*(ofxCheckBox*)*it == true) {
                values.push_back((*it)->getName());
            }
        }

        if (notifyEvent) {
            ofNotifyEvent(changeEvent, values);
        }
    }

    vector<string> values;
    ofEvent<vector<string>> changeEvent;
};