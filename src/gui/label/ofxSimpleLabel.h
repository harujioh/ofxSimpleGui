#pragma once

#include "ofxSimpleBaseGui.h"

class ofxSimpleLabel : public ofxSimpleBaseGui {
   public:
    ofxSimpleLabel(){};
    virtual ~ofxSimpleLabel(){};

    //    ofxSimpleLabel* setup(const std::string& name);
    ofxSimpleLabel* setup(const std::string& name, float width = defaultWidth, float height = defaultHeight);

    void setAlign(Align align) { this->align = align; }
    void setValign(Valign valign) { this->valign = valign; }

    string operator=(string v);
    operator const string&();
    bool operator==(const string& obj) const;
    bool operator!=(const string& obj) const;

   protected:
    virtual void update();
    virtual void render();

    bool resizeWithText;

    string value;
};
