#pragma once

#include "ofxSimpleSlider.h"

template <typename Type>
class ofxScrollSlider : public ofxSimpleSlider<Type> {
   public:
    ofxScrollSlider() : ofxSimpleSlider<Type>() {}
    ~ofxScrollSlider(){};

    ofxScrollSlider* setup(const std::string& name, Type value, Type min, Type max, float width = ofxSimpleBaseGui::defaultWidth, float height = ofxSimpleBaseGui::defaultHeight) {
        this->name = name;
        this->value.set(name, value, min, max);
        this->setSize(width, height);

        return this;
    }

    virtual bool onMousePressed(ofMouseEventArgs& args) {
        if (grip.inside(args.x, args.y)) {
            this->bHandling = true;
        } else if (this->rect.inside(args.x, args.y)) {
            float w = this->rect.width - this->borderWidth * 2 - barWidth;
            Type v = ((args.x - barWidth / 2) - (this->rect.x + this->borderWidth)) / w * (this->value.getMax() - this->value.getMin());
            this->changeValue(v);
            return true;
        }
        return false;
    }

    virtual bool onMouseDragged(ofMouseEventArgs& args) {
        if (this->bHandling) {
            float w = this->rect.width - this->borderWidth * 2 - barWidth;
            Type v = ((args.x - barWidth / 2) - (this->rect.x + this->borderWidth)) / w * (this->value.getMax() - this->value.getMin());
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
    virtual void resize() {
        this->background.clear();
        this->background.setFillColor(this->backgroundColor);
        this->background.setFilled(true);
        this->background.setStrokeColor(this->borderColor);
        this->background.setStrokeWidth(this->borderWidth);
        this->background.rectangle(this->rect);

        this->update();
    }

    virtual void update() {
        float w = this->rect.width - this->borderWidth * 2 - barWidth;
        float h = this->rect.height - this->borderWidth * 2;
        w = w * this->value.get() / (this->value.getMax() - this->value.getMin());

        grip.set(this->rect.x + this->borderWidth + w, this->rect.y + this->borderWidth, barWidth, h);

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
    float barWidth = 20;
};

typedef ofxScrollSlider<float> ofxFloatScrollSlider;
typedef ofxScrollSlider<int> ofxIntScrollSlider;