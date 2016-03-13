#include "ofxSimpleSlider.h"

ofxSimpleSlider::ofxSimpleSlider() { registerMouseEvents(); }

void ofxSimpleSlider::render() {}

bool ofxSimpleSlider::onMousePressed(ofMouseEventArgs& args) {
    ofLogNotice("ofxSimpleSlider::mousePressed") << args.x << ", " << args.y;
    return false;
}

bool ofxSimpleSlider::onMouseDragged(ofMouseEventArgs& args) {
    ofLogNotice("ofxSimpleSlider::mouseDragged") << args.x << ", " << args.y;
    return false;
}

bool ofxSimpleSlider::onMouseReleased(ofMouseEventArgs& args) {
    ofLogNotice("ofxSimpleSlider::mouseReleased") << args.x << ", " << args.y;
    return false;
}

bool ofxSimpleSlider::onMouseScrolled(ofMouseEventArgs& args) {
    ofLogNotice("ofxSimpleSlider::mouseScrolled") << args.x << ", " << args.y;
    return false;
}