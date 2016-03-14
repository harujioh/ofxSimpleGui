#pragma once

#include "ofConstants.h"
#include "ofBaseTypes.h"
#include "ofParameter.h"
#include "ofTrueTypeFont.h"

class ofxSimpleBaseGui {
   public:
    virtual ~ofxSimpleBaseGui();

    void draw();

    std::string getName();
    void setName(const std::string& name);

    void setPosition(const ofPoint& p);
    void setPosition(float x, float y);
    void setSize(float w, float h);
    void setShape(ofRectangle r);
    void setShape(float x, float y, float w, float h);

    ofPoint getPosition() const;
    ofRectangle getShape() const;
    float getWidth() const;
    float getHeight() const;

    ofColor getBackgroundColor() const;
    ofColor getBorderColor() const;
    ofColor getTextColor() const;
    float getBorderWidth() const;

    void setBackgroundColor(const ofColor& color);
    void setBorderColor(const ofColor& color);
    void setTextColor(const ofColor& color);
    void setBorderWidth(const float& width);

    void setParent(ofxSimpleBaseGui* parent);
    ofxSimpleBaseGui* getParent();

    bool mouseMoved(ofMouseEventArgs& args);
    bool mousePressed(ofMouseEventArgs& args);
    bool mouseDragged(ofMouseEventArgs& args);
    bool mouseReleased(ofMouseEventArgs& args);
    bool mouseScrolled(ofMouseEventArgs& args);
    void mouseEntered(ofMouseEventArgs& args) {}
    void mouseExited(ofMouseEventArgs& args) {}

    virtual bool onMouseMoved(ofMouseEventArgs& args);
    virtual bool onMousePressed(ofMouseEventArgs& args);
    virtual bool onMouseDragged(ofMouseEventArgs& args);
    virtual bool onMouseReleased(ofMouseEventArgs& args);
    virtual bool onMouseScrolled(ofMouseEventArgs& args);

   protected:
    virtual void render() = 0;
    virtual void resize() = 0;

    ofxSimpleBaseGui* parent = nullptr;
    std::string name;

    ofRectangle rect;
    ofRectangle b, p;

    ofColor backgroundColor = defaultBackgroundColor;
    ofColor borderColor = defaultBorderColor;
    ofColor textColor = defaultTextColor;
    float borderWidth = defaultBorderWidth;

    void registerMouseEvents();
    void unregisterMouseEvents();

    static int defaultWidth;
    static int defaultHeight;
    static ofColor defaultBackgroundColor;
    static ofColor defaultBorderColor;
    static ofColor defaultTextColor;
    static float defaultBorderWidth;

   private:
    bool bRegisteredForMouseEvents = false;

    void resizeRect();
};
