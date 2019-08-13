#pragma once

#include "ofMain.h"
#include "ofxVolumetrics.h"
#include "ofxGui.h"
#include "BoundingBox.hpp"
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		
    
		
    ofEasyCam cam;

    ofxVolumetrics myVolume;
    unsigned char * volumeData;
    int volWidth, volHeight, volDepth;
    ofImage background;
    ofxImageSequencePlayer imageSequence;
    bool linearFilter;
    
    
    ofxPanel gui;
    ofxVec3Slider aabb_size;
    ofxIntSlider wrapMode;
    ofxIntSlider magFilterMode;
    ofxIntSlider minFilterMode;
    
    
    BoundingBox *boundingBox;
    ofShader shader;
};
