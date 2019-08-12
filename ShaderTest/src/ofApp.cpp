#include "ofApp.h"
/*
openGL : matrix style is "row-major"
GLSL : matrix style is "col-major"
 */
//--------------------------------------------------------------
void ofApp::setup(){
//    ofMatrix4x4 t;
//    t.translate(100.0, 200.0, 300.0);
//    cout << t << endl;
    
    ofBackground(0.0);
    shader.load("Shaders/shader");
    
    modelMatrixGui.setup("modelMatrix");
    modelMatrixGui.add(scale.setup("scale", ofVec3f(1.0, 1.0, 1.0), ofVec3f(0.0, 0.0, 0.0), ofVec3f(10.0, 10.0, 10.0)));
    modelMatrixGui.add(translate.setup("translate", ofVec3f(1.0, 1.0, 1.0), ofVec3f(-300.0, -300.0, -300.0), ofVec3f(300.0, 300.0, 300.0)));
    modelMatrixGui.add(skewX.setup("skewX", ofVec2f(0.0, 0.0), ofVec2f(-10.0, -10.0), ofVec2f(10.0, 10.0)));
    modelMatrixGui.add(skewY.setup("skewY", ofVec2f(0.0, 0.0), ofVec2f(-10.0, -10.0), ofVec2f(10.0, 10.0)));
    modelMatrixGui.add(skewZ.setup("skewZ", ofVec2f(0.0, 0.0), ofVec2f(-10.0, -10.0), ofVec2f(10.0, 10.0)));
    
    //viewMatrixGui.setup("viewMatrix");
    modelMatrixGui.add(eyePos.setup("eyePos", ofVec3f(0.0, 0.0, 100.0), ofVec3f(-300.0, -300.0, -300.0), ofVec3f(300.0, 300.0, 300.0)));
    modelMatrixGui.add(eyeTarget.setup("eyeTarget", ofVec3f(0.0, 50.0, 0.0), ofVec3f(-300.0, -300.0, -300.0), ofVec3f(300.0, 300.0, 300.0)));
    
    modelMatrixGui.add(fov.setup("fov", 60.0, 30.0, 180.0));
    modelMatrixGui.add(near.setup("near", 0.1, 0.0, 100.0));
    modelMatrixGui.add(far.setup("far", 60.0, 30.0, 100.0));
                       
   
    
    //gui.add(delta.setup("delta", 0.0, 0.0, 10.0));
  
    
    
    scaleMatrix.set(scale->x, 0.0, 0.0, 0.0,
                    0.0 , scale->y, 0.0, 0.0,
                    0.0, 0.0, scale->z, 0.0,
                    0.0, 0.0, 0.0, 1.0);
    
    translateMatrix.set(1.0,          skewY->x,     skewZ->x,     0.0,
                        skewX->x ,    1.0,          skewZ->y,     0.0,
                        skewX->y,     skewY->y,     1.0,          0.0,
                        translate->x, translate->y, translate->z, 1.0);
    
    
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
    
    translateMatrix.set(1.0,          skewY->x,     skewZ->x,     0.0,
                        skewX->x ,    1.0,          skewZ->y,     0.0,
                        skewX->y,     skewY->y,     1.0,          0.0,
                        translate->x, translate->y, translate->z, 1.0);

//
//    translateMatrix.set(1.0, 0.0, 0.0, 0.0,
//                        0.0 , 1.0, 0.0, 0.0,
//                        0.0, 0., 1.0, 0.0,
//                        translate->x, translate->y, translate->z, 1.0);
//
    
    modelMatrix = ofMatrix4x4::newIdentityMatrix();
    modelMatrix.preMult(scaleMatrix);
    modelMatrix.preMult(translateMatrix);
}

//--------------------------------------------------------------
void ofApp::draw(){
    modelMatrixGui.draw();
    //viewMatrixGui.draw();
    
    
    cam.begin();
    ofMatrix4x4 viewMatrix;
    viewMatrix = ofGetCurrentViewMatrix();
    
    /*
    ofMatrix4x4 _c;
    _c =  transformMatrix::getViewMatrix(ofVec3f(eyePos->x, eyePos->y, eyePos->z),
                                         ofVec3f(eyeTarget->x, eyeTarget->y, eyeTarget->z),
                                         ofVec3f(0.0, 1.0, 0.0));
    
    
    ofSetColor(255);
    ofDrawBox(eyePos->x, eyePos->y, eyePos->z, 50.0, 50.0, 50.0);
    
    float size = 300.0;

    ofSetColor(255, 0.0, 0.0);
    ofDrawLine(eyePos->x, eyePos->y, eyePos->z, -size*_c.getRowAsVec3f(2).x, -size*_c.getRowAsVec3f(2).y, -size*_c.getRowAsVec3f(2).z);
    ofSetColor(0.0, 255.0, 0.0);
    ofDrawLine(eyePos->x, eyePos->y, eyePos->z, size*_c.getRowAsVec3f(1).x, size*_c.getRowAsVec3f(1).y, size*_c.getRowAsVec3f(1).z);
    ofSetColor(0.0, 0.0, 255.0);
    ofDrawLine(eyePos->x, eyePos->y, eyePos->z, size*_c.getRowAsVec3f(0).x, size*_c.getRowAsVec3f(0).y, size*_c.getRowAsVec3f(0).z);
    */
    
    
    ofMatrix4x4 projMatrix = cam.getProjectionMatrix();
    //projMatrix = transformMatrix::getProjMatrix(fov * 60.0 / 180.0, far, near);
    
    ofDrawAxis(1000.0);
    shader.begin();
    shader.setUniformMatrix4f("modelMatrix",  modelMatrix);
    shader.setUniformMatrix4f("viewMatrix",  viewMatrix);
    //shader.setUniformMatrix4f("projMatrix",  ofMatrix4x4::getTransposedOf(projMatrix));
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
        skewX = skewY = skewZ = ofVec2f(0.0, 0.0);
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
