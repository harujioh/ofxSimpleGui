#pragma once

#include "ofxSimpleBaseGui.h"

enum ButtonType { OTHER, DEFAULT, PRIMARY, SUCCESS, INFO, WARNING, DANGER };

class ofxSimpleButton : public ofxSimpleBaseGui {
   public:
    ofxSimpleButton();
    virtual ~ofxSimpleButton(){};

    ofxSimpleButton* setup(const std::string& name, ButtonType type = ButtonType::DEFAULT, float width = defaultWidth, float height = defaultHeight);

    void setButtonType(ButtonType type);

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

    template <class ListenerClass, typename ListenerMethod>
    static void addAllListener(ListenerClass* listener, ListenerMethod method) {
        ofAddListener(clickAllEvent, listener, method);
    }

    template <class ListenerClass, typename ListenerMethod>
    static void removeAllListener(ListenerClass* listener, ListenerMethod method) {
        ofRemoveListener(clickAllEvent, listener, method);
    }

   protected:
    virtual void resize();
    virtual void update();
    virtual void render();

    ofEvent<void> clickEvent;
    static ofEvent<ofxSimpleBaseGui> clickAllEvent;

    ofColor backgroundHoverColor;
    ofColor borderHoverColor;
    ofColor backgroundActiveColor;
    ofColor borderActiveColor;

    bool bHover = false;
    bool bPressed = false;
    bool bActive = false;

    virtual void changeValue(bool notifyEvent = true);
};
