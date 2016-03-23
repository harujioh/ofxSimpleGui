#pragma once

#include "ofxSimpleSlider.h"

template <typename Type>
class ofxScrollbar : public ofxSimpleSlider<Type> {
   public:
    ofxScrollbar() : ofxSimpleSlider<Type>() {}
    virtual ~ofxScrollbar(){};

    ofxScrollbar* setup(const std::string& name, Type value, Type min, Type max, float width = ofxSimpleBaseGui::defaultWidth, float height = ofxSimpleBaseGui::defaultHeight, float gripWidth = 20) {
        this->name = name;
        this->value.set(name, value, min, max);
        grip.width = gripWidth;
        this->setSize(width, height);
        this->setBorderWidth(1);

        return this;
    }

    void setGripSize(float width, float height) { grip.setSize(width, height); }

    virtual bool onMousePressed(ofMouseEventArgs& args) {
        if (grip.inside(args.x, args.y)) {
            this->bHandling = true;
        } else if (this->rect.inside(args.x, args.y)) {
            float w = this->rect.width - this->borderWidth * 2 - grip.width;
            Type v = ((args.x - grip.width / 2) - (this->rect.x + this->borderWidth)) / w * (this->value.getMax() - this->value.getMin());
            this->changeValue(v);
            return true;
        }
        return false;
    }

    virtual bool onMouseDragged(ofMouseEventArgs& args) {
        if (this->bHandling) {
            float w = this->rect.width - this->borderWidth * 2 - grip.width;
            Type v = ((args.x - grip.width / 2) - (this->rect.x + this->borderWidth)) / w * (this->value.getMax() - this->value.getMin());
            this->changeValue(v);
            return true;
        }
        return false;
    }

    double operator=(Type v) {
        this->changeValue(v, false);
        return v;
    }

    operator const Type&() { return this->value; }

   protected:
    virtual void update() {
        float w = this->rect.width - this->borderWidth * 2 - grip.width;
        float h = this->rect.height - this->borderWidth * 2;
        w = w * this->value.get() / (this->value.getMax() - this->value.getMin());

        grip.set(this->rect.x + this->borderWidth + w, this->rect.y + this->borderWidth, grip.width, h);

        this->bar.clear();
        this->bar.setFillColor(this->barColor);
        this->bar.setFilled(true);
        this->bar.rectangle(grip);

        if (!this->bUpdateOnReleaseOnly || !this->bHandling) {
            if (this->value != this->lastValue) {
                this->lastValue = this->value;
            }
        }
    }

    ofRectangle grip;
};

typedef ofxScrollbar<float> ofxFloatScrollbar;
typedef ofxScrollbar<int> ofxIntScrollbar;