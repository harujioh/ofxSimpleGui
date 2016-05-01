#pragma once

#include "ofConstants.h"
#include "ofBaseTypes.h"
#include "ofParameter.h"
#include "ofTrueTypeFont.h"
#include "ofBitmapFont.h"
#include "ofGraphics.h"

enum Align { CENTER, LEFT, RIGHT };

enum Valign { MIDDLE, TOP, BOTTOM };

class ofxSimpleBaseGui {
   public:
    ofxSimpleBaseGui();
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

    static void setDefaultFontSize(const int& defaultFontSize) { ofxSimpleBaseGui::defaultFontSize = defaultFontSize; }
    static void setDefaultWidth(const int& defaultWidth) { ofxSimpleBaseGui::defaultWidth = defaultWidth; }
    static void setDefaultHeight(const int& defaultHeight) { ofxSimpleBaseGui::defaultHeight = defaultHeight; }
    static void setDefaultBackgroundColor(const ofColor& defaultBackgroundColor) { ofxSimpleBaseGui::defaultBackgroundColor = defaultBackgroundColor; }
    static void setDefaultBorderColor(const ofColor& defaultBorderColor) { ofxSimpleBaseGui::defaultBorderColor = defaultBorderColor; }
    static void setDefaultTextColor(const ofColor& defaultTextColor) { ofxSimpleBaseGui::defaultTextColor = defaultTextColor; }
    static void setDefaultBorderWidth(const float& defaultBorderWidth) { ofxSimpleBaseGui::defaultBorderWidth = defaultBorderWidth; }

    static void loadFont(const std::string& filename = OF_TTF_MONO, int fontsize = 10, bool _bAntiAliased = true, bool _bFullCharacterSet = false, int dpi = 0);

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
    virtual void resize() { update(); };
    virtual void update() = 0;

    ofxSimpleBaseGui* parent = nullptr;
    std::string name;

    ofRectangle rect;
    ofRectangle b, p;

    ofPath background;
    ofColor backgroundColor = defaultBackgroundColor;
    ofColor borderColor = defaultBorderColor;
    ofColor textColor = defaultTextColor;
    float borderWidth = defaultBorderWidth;

    ofBitmapFont bitmapFont;
    static ofTrueTypeFont font;
    static bool useTTF;
    static float fontHeight;
    ofVboMesh textMesh;

    ofMesh getTextMesh(const string& text, float x, float y);
    ofMesh getTextMesh(const string& text, ofRectangle rect, Align align = Align::CENTER, Valign valign = Valign::MIDDLE);
    ofRectangle getTextBoundingBox(const string& text, float x = 0, float y = 0);

    void registerMouseEvents();
    void unregisterMouseEvents();

    void bindFontTexture();
    void unbindFontTexture();

    static int defaultFontSize;
    static int defaultWidth;
    static int defaultHeight;
    static ofColor defaultBackgroundColor;
    static ofColor defaultBorderColor;
    static ofColor defaultTextColor;
    static float defaultBorderWidth;

   private:
    static string BASE_FONT_SIZE_CHAR;

    bool bRegisteredForMouseEvents = false;

    void resizeRect();
};
