#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    shader.load("Shaders/shader");
    
    gui.setup();
    gui.add(scale.setup("scale", ofVec3f(1.0, 1.0, 1.0), ofVec3f(0.0, 0.0, 0.0), ofVec3f(10.0, 10.0, 10.0)));
    gui.add(translate.setup("translate", ofVec3f(1.0, 1.0, 1.0), ofVec3f(-300.0, -300.0, -300.0), ofVec3f(300.0, 300.0, 300.0)));
    
  
    
    
    scaleMatrix.set(scale->x, 0.0, 0.0, 0.0,
                    0.0 , scale->y, 0.0, 0.0,
                    0.0, 0.0, scale->z, 0.0,
                    0.0, 0.0, 0.0, 1.0);
    
    translateMatrix.set(1.0, 0.0, 0.0, translate->x,
                    0.0 , 1.0, 0.0, translate->y,
                    0.0, 0.0, 1.0, translate->z,
                    0.0, 0.0, 0.0, 1.0);
    
    modelMatrix = ofMatrix4x4::newIdentityMatrix();
    modelMatrix.preMult(scaleMatrix);
    modelMatrix.preMult(translateMatrix);
    
   
}

//--------------------------------------------------------------
void ofApp::update(){
    scaleMatrix.set(scale->x, 0.0, 0.0, 0.0,
                    0.0 , scale->y, 0.0, 0.0,
                    0.0, 0.0, scale->z, 0.0,
                    0.0, 0.0, 0.0, 1.0);
    
    translateMatrix.set(1.0, 0.0, 0.0, translate->x,
                        0.0 , 1.0, 0.0, translate->y,
                        0.0, 0.0, 1.0, translate->z,
                        0.0, 0.0, 0.0, 1.0);
    
    modelMatrix = ofMatrix4x4::newIdentityMatrix();
    modelMatrix.preMult(scaleMatrix);
    modelMatrix.preMult(translateMatrix);
}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    
    
    cam.begin();
    ofMatrix4x4 viewMatrix;
    viewMatrix = ofGetCurrentViewMatrix();
    ofMatrix4x4 projMatrix = cam.getProjectionMatrix();
    
    shader.begin();
    shader.setUniformMatrix4f("modelMatrix",  ofMatrix4x4::getTransposedOf(modelMatrix));
    shader.setUniformMatrix4f("viewMatrix",  viewMatrix);
    shader.setUniformMatrix4f("projMatrix",  projMatrix);
    cam.getProjectionMatrix();
    ofDrawRectangle(0.0, 0.0, 300.0, 300.0);
    //mesh.draw();
    shader.end();
    
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_SHIFT){
        cout << "Shader Load" << endl;
       
        shader.load("Shaders/shader");
    }
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
