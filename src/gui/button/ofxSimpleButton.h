#pragma once

#include "ofxSimpleBaseGui.h"

class ofxSimpleButton : public ofxSimpleBaseGui {
   public:
    ofxSimpleButton();
    virtual ~ofxSimpleButton(){};

    ofxSimpleButton* setup(const std::string& name, float width = defaultWidth, float height = defaultHeight);

    virtual bool onMouseMoved(ofMouseEventArgs& args);
    virtual bool onMousePressed(ofMouseEventArgs& args);
    virtual bool onMouseDragged(ofMouseEventArgs& args);
    virtual bool onMouseReleased(ofMouseEventArgs& args);

    template <class ListenerClass, typename ListenerMethod>
    void addListener(ListenerClass* listener, ListenerMethod method) {
        ofAddListener(clickEvent, listener, method);
    }

    template <class ListenerClass, typename ListenerMethod>
    void removeListener(ListenerClass* listener, ListenerMethod method) {
        ofRemoveListener(clickEvent, listener, method);
    }

    operator const bool&();

   protected:
    virtual void update();
    virtual void render();

    bool value = false;
    ofEvent<void> clickEvent;

    ofColor backgroundHoverColor = ofColor(0xe6e6e6);
    ofColor borderHoverColor = ofColor(0xadadad);
    ofColor backgroundActiveColor = ofColor(0xd4d4d4);
    ofColor borderActiveColor = ofColor(0x8c8c8c);

    bool bHover = false;
    bool bPressed = false;
    bool bActive = false;

    virtual void changeValue(bool v, bool notifyEvent = true);
};
