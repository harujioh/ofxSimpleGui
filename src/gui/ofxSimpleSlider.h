#pragma once

#include "ofxSimpleBaseGui.h"
#include "ofParameter.h"

template <typename Type>
class ofxSimpleSlider : public ofxSimpleBaseGui {
   public:
    ofxSimpleSlider();

    ofxSimpleSlider* setup(const std::string& name, Type value, Type min, Type max, float width = defaultWidth, float height = defaultHeight);

    void setMin(Type min);
    Type getMin();
    void setMax(Type max);
    Type getMax();

    void setUpdateOnReleaseOnly(bool bUpdateOnReleaseOnly);

    virtual bool onMousePressed(ofMouseEventArgs& args);
    virtual bool onMouseDragged(ofMouseEventArgs& args);
    virtual bool onMouseReleased(ofMouseEventArgs& args);
    virtual bool onMouseScrolled(ofMouseEventArgs& args);

    double operator=(Type v);
    operator const Type&();

   protected:
    virtual void resize();
    virtual void render();

    virtual void update();

    ofParameter<Type> value, lastValue;

    ofPath background;
    ofPath bar;

    ofColor barColor = ofColor(128, 128, 128);

    bool bUpdateOnReleaseOnly = false;

    bool bHandling = false;
};

typedef ofxSimpleSlider<float> ofxSimpleFloatSlider;
typedef ofxSimpleSlider<int> ofxSimpleIntSlider;