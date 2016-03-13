#pragma once

#include "ofxSimpleBaseGui.h"
#include "ofParameter.h"

template <typename Type>
class ofxSimpleSlider : public ofxSimpleBaseGui {
   public:
    ofxSimpleSlider();

    void setMin(Type min);
    Type getMin();
    void setMax(Type max);
    Type getMax();

    void setUpdateOnReleaseOnly(bool bUpdateOnReleaseOnly);

    virtual bool onMousePressed(ofMouseEventArgs& args);
    virtual bool onMouseDragged(ofMouseEventArgs& args);
    virtual bool onMouseReleased(ofMouseEventArgs& args);
    virtual bool onMouseScrolled(ofMouseEventArgs& args);

   protected:
    virtual void render();

   private:
    ofParameter<Type> value;

    bool bUpdateOnReleaseOnly;
};

typedef ofxSimpleSlider<float> ofxSimpleFloatSlider;
typedef ofxSimpleSlider<int> ofxSimpleIntSlider;