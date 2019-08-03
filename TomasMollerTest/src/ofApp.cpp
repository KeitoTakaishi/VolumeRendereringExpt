#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    gui.setup();
//    gui.add(rayX.setup("x", 0.0, -2.0, 2.0));
//    gui.add(rayY.setup("y", 0.0, -2.0, 2.0));
//    gui.add(rayZ.setup("z", -1.0, -2.0, 2.0));
    gui.add(rayVec.setup("ray", ofVec3f(0.0, 0.0, 0.0), ofVec3f(-2.0, -2.0, -2.0), ofVec3f(2.0, 2.0, 2.0)));
    //gui.add(t.setup("coef", 30.0, .0, 100.0));
    
    trianglePos[0] = ofVec3f(50.0, -100.0, 0.0);
    trianglePos[1] = ofVec3f(0.0, 100.0, 0.0);
    trianglePos[2] = ofVec3f(-50.0, -100.0, 0.0);
    
    for(int i = 0; i < 3; i++){
        triangle.addVertex(trianglePos[i]);
        triangle.addIndex(i);
        triangle.addColor(ofColor::gray);
    }
    
    cam.setPosition(0, 200.0, 0.0);
    rayObj.setPosition(originalRayPos);
    rayObj.setRadius(10.0);
    
    /*
    //determinant test code
    ofVec3f a = ofVec3f(1, -2, 0);
    ofVec3f b = ofVec3f(3, 5, 2);
    ofVec3f c = ofVec3f(6, 1, 3);
    cout << " det is : " << determinant(a, b, c) << endl;
    */
    
    //culc
    //Edge1*u + Edge2*v - ray * t = rayOriginal - V0
    //d is rayOriginal - V0
    d = originalRayPos - trianglePos[0];
    invRay = -ray;
    edge1 = trianglePos[1] - trianglePos[0];
    edge2 = trianglePos[2] - trianglePos[0];
    
    // denominator for Cramer
    denominator = determinant(edge1, edge2, invRay);
    
}
//--------------------------------------------------------------
void ofApp::update(){
    r = 0;
    isCross = false;
    ray = ofVec3f(rayVec->x, rayVec->y, rayVec->z);
    invRay = -ray;
    denominator = determinant(edge1, edge2, invRay);
    if(denominator <= 0){
        cout << "not cross" << endl;
    }else{
        float u = determinant(d, edge2, invRay)/denominator;
        if ((u >= 0) && (u <= 1)) {
            float v = determinant(edge1, d, invRay)/denominator;
            if ((v >= 0) && (u + v <= 1)) {
                t = determinant(edge1, edge2, d) / denominator;
                if(t >= 0.0){
                    isCross = true;
                    cout << t << endl;
                    r = 255;
                }
            }
        }
    }
    //p = trianglePos[0] + edge1 * u + edge2 * v;
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableDepthTest();
    cam.begin();
    ofPushStyle();
    ofSetColor(r+100, r+100, r+100);
    rayObj.draw();
    ofDrawLine(originalRayPos, originalRayPos+ray*t);
    ofPopStyle();
    triangle.draw();
    cam.end();
    
    ofDisableDepthTest();
    gui.draw();
    if(isCross){
        ofDrawBitmapString("Ray Coef : " + ofToString(t), 20.0, 150.0);
    }else{
        ofDrawBitmapString("not Cross ", 20.0, 150.0);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
float ofApp::determinant(ofVec3f a, ofVec3f b, ofVec3f c){
    return( (a.x*b.y*c.z)
           +(a.y*b.z*c.x)
           +(a.z*b.x*c.y)
           -(a.z*b.y*c.x)
           -(a.x*b.z*c.y)
           -(a.y*b.x*c.z));
}
