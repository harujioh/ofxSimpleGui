#pragma once

#include "ofxScrollbar.h"

enum SeekbarGripForm { RECT, CIRCLE };

template <typename Type>
class ofxSeekbar : public ofxScrollbar<Type> {
   public:
    ofxSeekbar() : ofxScrollbar<Type>() {}
    virtual ~ofxSeekbar(){};

    ofxSeekbar* setup(const std::string& name, Type value, Type min, Type max, float width = ofxSimpleBaseGui::defaultWidth, float height = ofxSimpleBaseGui::defaultHeight, float gripDiameter = 20) {
        this->name = name;
        this->value.set(name, value, min, max);
        this->grip.setSize(gripDiameter, gripDiameter);
        this->borderWidth = 0;

        this->setSize(width, height);

        return this;
    }

    void setGripForm(SeekbarGripForm form) { gripForm = form; }

    virtual bool onMousePressed(ofMouseEventArgs& args) {
        ofRectangle rect = this->rect;
        rect.x -= this->grip.width / 2;
        rect.width += this->grip.width;
        if (rect.inside(args.x, args.y)) {
            this->bHandling = true;

            float w = this->rect.width - this->borderWidth * 2;
            Type v = (args.x - (this->rect.x + this->borderWidth)) / w * (this->value.getMax() - this->value.getMin());
            this->changeValue(v);
            return true;
        }
        return false;
    }

    virtual bool onMouseDragged(ofMouseEventArgs& args) {
        if (this->bHandling) {
            float w = this->rect.width - this->borderWidth * 2;
            Type v = (args.x - (this->rect.x + this->borderWidth)) / w * (this->value.getMax() - this->value.getMin());
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
        seek.clear();
        seek.setStrokeColor(seekBorderColor);
        seek.setStrokeWidth(1);
        seek.rectangle(this->rect.x, this->rect.y + this->rect.height / 2, this->rect.width, 1);

        ofxSimpleSlider<Type>::resize();
    }

    virtual void render() {
        this->background.draw();

        seek.draw();

        this->bar.draw();
    }

    virtual void update() {
        float w = this->rect.width - this->borderWidth * 2;
        float h = this->rect.height - this->borderWidth * 2;
        w = w * this->value.get() / (this->value.getMax() - this->value.getMin());

        this->grip.setPosition(this->rect.x + w - this->grip.width / 2, this->rect.y);

        this->bar.clear();
        this->bar.setFillColor(this->barColor);
        this->bar.setFilled(true);
        if (gripForm == RECT) {
            this->bar.rectangle(this->grip);
        } else {
            this->bar.ellipse(this->grip.x + this->grip.width / 2, this->grip.y + this->grip.height / 2, this->grip.width, this->grip.height);
        }

        if (!this->bUpdateOnReleaseOnly || !this->bHandling) {
            if (this->value != this->lastValue) {
                this->lastValue = this->value;
            }
        }
    }

    SeekbarGripForm gripForm = CIRCLE;
    ofPath seek;

    ofColor seekBorderColor = ofColor(0, 0, 0);
};

typedef ofxSeekbar<float> ofxFloatSeekbar;
typedef ofxSeekbar<int> ofxIntSeekbar;