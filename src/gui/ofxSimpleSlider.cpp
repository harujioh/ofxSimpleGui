#include "ofxSimpleSlider.h"

template <typename Type>
ofxSimpleSlider<Type>::ofxSimpleSlider() {
    registerMouseEvents();
}

template <typename Type>
void ofxSimpleSlider<Type>::render() {}

template <typename Type>
void ofxSimpleSlider<Type>::setMin(Type min) {
    value.setMin(min);
}

template <typename Type>
Type ofxSimpleSlider<Type>::getMin() {
    return value.getMin();
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
    ofLogNotice("ofxSimpleSlider::mousePressed") << args.x << ", " << args.y;
    return false;
}

template <typename Type>
bool ofxSimpleSlider<Type>::onMouseDragged(ofMouseEventArgs& args) {
    ofLogNotice("ofxSimpleSlider::mouseDragged") << args.x << ", " << args.y;
    return false;
}

template <typename Type>
bool ofxSimpleSlider<Type>::onMouseReleased(ofMouseEventArgs& args) {
    ofLogNotice("ofxSimpleSlider::mouseReleased") << args.x << ", " << args.y;
    return false;
}

template <typename Type>
bool ofxSimpleSlider<Type>::onMouseScrolled(ofMouseEventArgs& args) {
    ofLogNotice("ofxSimpleSlider::mouseScrolled") << args.x << ", " << args.y;
    return false;
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
