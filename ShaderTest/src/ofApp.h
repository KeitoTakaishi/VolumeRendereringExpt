#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "transformMatrix.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    ofShader shader;
    ofMatrix4x4 scaleMatrix;
    ofMatrix4x4 translateMatrix;
    ofMatrix4x4 modelMatrix;
    
    //Gui
    ofxPanel modelMatrixGui;
    ofxVec3Slider scale;
    ofxVec3Slider translate;
    ofxVec2Slider skewX;
    ofxVec2Slider skewY;
    ofxVec2Slider skewZ;
    ofxFloatSlider delta;
    
    ofxPanel viewMatrixGui;
    ofxVec3Slider eyePos;
    ofxVec3Slider eyeTarget;
    
    ofxFloatSlider fov;
    ofxFloatSlider near;
    ofxFloatSlider far;
    
    

    ofEasyCam cam;
};
