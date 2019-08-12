#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofDisableArbTex();
    shader.load("Shaders/shader");
    img.load("texture01.jpeg");
    
    mesh.setMode(ofPrimitiveMode::OF_PRIMITIVE_TRIANGLE_FAN);
    float imgSize = img.getWidth();
    imgSize = 1.0;
    float size = 100.0;
    mesh.addTexCoord(ofVec2f(0.0, 0.0));
    mesh.addVertex(ofVec3f(-size, size, 0.0));
    mesh.addTexCoord(ofVec2f(0, imgSize));
    mesh.addVertex(ofVec3f(-size, -size, 0.0));
    mesh.addTexCoord(ofVec2f(imgSize, imgSize));
    mesh.addVertex(ofVec3f(size, -size, 0.0));
    mesh.addTexCoord(ofVec2f(imgSize, 0.0));
    mesh.addVertex(ofVec3f(size, size, 0.0));
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    img.getTexture().bind();
    cam.begin();
    shader.begin();
    mesh.draw();
    shader.end();
    cam.end();
    img.getTexture().unbind();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
