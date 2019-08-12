#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
    
    ofVboMesh mesh;
    ofEasyCam cam;
    ofShader shader;
    unsigned char pixels[256*256*4];
    unsigned char pixels2[256*256*4];
    GLuint texID, texID2;
};
