#include "ofxSimpleSlider.h"

template <typename Type>
ofxSimpleSlider<Type>::ofxSimpleSlider() {
    registerMouseEvents();
}

template <typename Type>
ofxSimpleSlider<Type>* ofxSimpleSlider<Type>::setup(const std::string& name, Type value, Type min, Type max, float width, float height) {
    this->name = name;
    this->value.set(name, value, min, max);
    setSize(width, height);
    setBorderWidth(1);

    return this;
}

template <typename Type>
void ofxSimpleSlider<Type>::resize() {
    background.clear();
    background.setFillColor(backgroundColor);
    background.setFilled(true);
    background.setStrokeColor(borderColor);
    background.setStrokeWidth(borderWidth);
    background.rectangle(rect);

    update();
}

template <typename Type>
void ofxSimpleSlider<Type>::update() {
    float w = rect.width - borderWidth * 2;
    float h = rect.height - borderWidth * 2;
    w = w * value.get() / (value.getMax() - value.getMin());

    bar.clear();
    bar.setFillColor(barColor);
    bar.setFilled(true);
    bar.rectangle(rect.x + borderWidth, rect.y + borderWidth, w, h);

    if (!bUpdateOnReleaseOnly || !bHandling) {
        if (value != lastValue) {
            lastValue = value;
        }
    }

    if (textVisible) {
        textMesh = getTextMesh(ofToString(value), b);
    }
}

template <typename Type>
void ofxSimpleSlider<Type>::render() {
    background.draw();
    bar.draw();

    if (textVisible) {
        ofSetColor(textColor);
        bindFontTexture();
        textMesh.draw();
        unbindFontTexture();
    }
}

template <typename Type>
void ofxSimpleSlider<Type>::changeValue(Type v, bool notifyEvent) {
    v = value.getMin() > v ? value.getMin() : v;
    v = value.getMax() < v ? value.getMax() : v;
    if (value != v) {
        value = v;
        update();

        if (notifyEvent) {
            if (!bUpdateOnReleaseOnly) {
                ofNotifyEvent(changeValueEvent, v);
            } else {
                ofNotifyEvent(changingValueEvent, v);
            }
        }
    }
}

template <typename Type>
void ofxSimpleSlider<Type>::setMin(Type min) {
    value.setMin(min);
    update();
}

template <typename Type>
Type ofxSimpleSlider<Type>::getMin() {
    return value.getMin();
    update();
}

template <typename Type>
void ofxSimpleSlider<Type>::setMax(Type max) {
    value.setMax(max);
}

template <typename Type>
Type ofxSimpleSlider<Type>::getMax() {
    return value.getMax();
}

template <typename Type>
bool ofxSimpleSlider<Type>::onMousePressed(ofMouseEventArgs& args) {
    if (rect.inside(args.x, args.y)) {
        bHandling = true;

        float w = rect.width - borderWidth * 2;
        Type v = (args.x - (rect.x + borderWidth)) / w * (value.getMax() - value.getMin());
        changeValue(v);
        return true;
    }
    return false;
}

template <typename Type>
bool ofxSimpleSlider<Type>::onMouseDragged(ofMouseEventArgs& args) {
    if (bHandling) {
        float w = rect.width - borderWidth * 2;
        Type v = (args.x - (rect.x + borderWidth)) / w * (value.getMax() - value.getMin());
        changeValue(v);
        return true;
    }
    return false;
}

template <typename Type>
bool ofxSimpleSlider<Type>::onMouseReleased(ofMouseEventArgs& args) {
    if (bHandling) {
        bHandling = false;
        update();

        if (bUpdateOnReleaseOnly) {
            Type v = value;
            ofNotifyEvent(changeValueEvent, v);
        }
    }
    return rect.inside(args.x, args.y);
}

template <typename Type>
bool ofxSimpleSlider<Type>::onMouseScrolled(ofMouseEventArgs& args) {
    return false;
}

template <typename Type>
double ofxSimpleSlider<Type>::operator=(Type v) {
    changeValue(v, false);
    return v;
}

template <typename Type>
ofxSimpleSlider<Type>::operator const Type&() {
    return value;
}

template class ofxSimpleSlider<int8_t>;
template class ofxSimpleSlider<uint8_t>;
template class ofxSimpleSlider<int16_t>;
template class ofxSimpleSlider<uint16_t>;
template class ofxSimpleSlider<int32_t>;
template class ofxSimpleSlider<uint32_t>;
template class ofxSimpleSlider<int64_t>;
template class ofxSimpleSlider<uint64_t>;
template class ofxSimpleSlider<float>;
template class ofxSimpleSlider<double>;
