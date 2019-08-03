#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		
    float determinant(ofVec3f a, ofVec3f b, ofVec3f c);
    
    //triangle
    ofVec3f trianglePos[3];
    ofMesh triangle;
    
    //ray
    ofSpherePrimitive rayObj;
    //ofVec3f ray = ofVec3f(0, 100, 0.0);
    ofVec3f ray = ofVec3f(0, 0.0, 100.0);
    ofVec3f originalRayPos = ofVec3f(0, 0, 100);
    
    
    float t;
    //utils
    ofEasyCam cam;
    //ofxFloatSlider rayX, rayY, rayZ;
    ofxVec3Slider rayVec;
    ofxPanel gui;
    
    //for culc
    ofVec3f p;
    ofVec3f d; //origin - v0
    ofVec3f invRay;
    ofVec3f edge1, edge2;
    float denominator = 0;
    
    float r = 0;
    bool isCross = false;
};


