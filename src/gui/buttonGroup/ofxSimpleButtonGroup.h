#pragma once

#include "ofxSimpleBaseGui.h"
#include "ofxSimpleButton.h"

class ofxSimpleButtonGroup : public ofxSimpleBaseGui {
   public:
    ofxSimpleButtonGroup() {}
    virtual ~ofxSimpleButtonGroup();

    ofxSimpleButtonGroup* setup(const std::string& name, float buttonWidth = defaultWidth, float buttonHeight = defaultHeight, float buttonMargin = 0);

    template <class ListenerClass, typename ListenerMethod>
    void addListener(ListenerClass* listener, ListenerMethod method) {
        ofAddListener(changeEvent, listener, method);
    }

    template <class ListenerClass, typename ListenerMethod>
    void removeListener(ListenerClass* listener, ListenerMethod method) {
        ofRemoveListener(changeEvent, listener, method);
    }

    virtual void add(const std::string& name);
    virtual vector<string> getAllName();

    void clickedButton(ofxSimpleBaseGui& button);

   protected:
    virtual void resize();
    virtual void update();
    virtual void render();

    void add(ofxSimpleButton* button);

    ofxSimpleButton* value = NULL;
    ofEvent<string> changeEvent;

    float buttonWidth;
    float buttonHeight;
    float buttonMargin;
    vector<ofxSimpleButton*> buttons;

    virtual void changeValue(ofxSimpleButton& button, bool notifyEvent = true);
};