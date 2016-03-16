#pragma once

#include "ofxSimpleBaseGui.h"

template <typename Type>
class ofxSimpleSlider : public ofxSimpleBaseGui {
   public:
    ofxSimpleSlider();
    virtual ~ofxSimpleSlider(){};

    ofxSimpleSlider* setup(const std::string& name, Type value, Type min, Type max, float width = defaultWidth, float height = defaultHeight);

    bool isHandling() { return bHandling; }

    void setMin(Type min);
    Type getMin();
    void setMax(Type max);
    Type getMax();

    void setUpdateOnReleaseOnly(bool bUpdateOnReleaseOnly) { this->bUpdateOnReleaseOnly = bUpdateOnReleaseOnly; }

    virtual bool onMousePressed(ofMouseEventArgs& args);
    virtual bool onMouseDragged(ofMouseEventArgs& args);
    virtual bool onMouseReleased(ofMouseEventArgs& args);
    virtual bool onMouseScrolled(ofMouseEventArgs& args);

    template <class ListenerClass, typename ListenerMethod>
    void addListener(ListenerClass* listener, ListenerMethod changedMethod, ListenerMethod changingMethod = NULL) {
        ofAddListener(changeValueEvent, listener, changedMethod);
        if(changingMethod != NULL){
            ofAddListener(changingValueEvent, listener, changingMethod);
        }
    }

    template <class ListenerClass, typename ListenerMethod>
    void removeListener(ListenerClass* listener, ListenerMethod changedMethod, ListenerMethod changingMethod = NULL) {
        ofRemoveListener(changeValueEvent, listener, changedMethod);
        if(changingMethod != NULL){
            ofRemoveListener(changingValueEvent, listener, changingMethod);
        }
    }

    void set(Type v);
    double operator=(Type v);
    operator const Type&();

   protected:
    virtual void resize();
    virtual void update();
    virtual void render();

    ofParameter<Type> value, lastValue;
    ofEvent<Type> changeValueEvent;
    ofEvent<Type> changingValueEvent;

    ofPath bar;

    ofColor barColor = ofColor(128, 128, 128);

    bool bUpdateOnReleaseOnly = false;

    bool bHandling = false;

    virtual void changeValue(Type v, bool notifyEvent = true);
};

typedef ofxSimpleSlider<float> ofxSimpleFloatSlider;
typedef ofxSimpleSlider<int> ofxSimpleIntSlider;