#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetFrameRate(60);
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    cam.setDistance(1000);
    cam.enableMouseInput();
    
    
    boundingBox = new BoundingBox(boundingBoxSize);
    //shader.load("Shaders/_shader");
    shader.load("Shaders/_shader.vert", "Shaders/shader1.frag");
    
    gui.setup("VolumeRender-Expt");
    gui.add(aabb_size.setup("Boundgin Size", ofVec3f(256,256,256), ofVec3f(0, 0, 0), ofVec3f(3000,3000,3000)));
    gui.add(wrapMode.setup("WRAP_MODE", 0, 0, 2));
    gui.add(minFilterMode.setup("MAG_FILTER_MODE", 0, 0, 1));
    gui.add(magFilterMode.setup("MIN_FILTER_MODE", 0, 0, 1));
    gui.add(_intencity.setup("_Intencity", 0.5, 0.0, 1.0));
    //gui.add(_threshould.setup("_Threshould", 0.2, 0.0, 1.0));
    gui.add(_threshould.setup("_Threshould", 0.08, 0.0, 0.2));
    gui.add(_brendRate.setup("_BrendRate", 0.5, 0.0, 1.0));
    gui.add(_iterration.setup("_Iteration", 5, 1, 30));
    gui.add(_offSet.setup("_OffSet", ofVec3f(0.0, 0.0, 0.0), ofVec3f(0.0, 0.0, 0.0), ofVec3f(1.0, 1.0, 1.0)));
    gui.add(_imageSize.setup("_ImageSize", ofVec3f(256.0, 256.0, 256.0), ofVec3f(0.0, 0.0, 0.0), ofVec3f(256.0, 256.0, 256.0)));
    
    
    //boundingBox->createTexture3D(ofVec3f(255,255,10));
    boundingBox->fileLoader("volumes/head", "cthead-8bit", ".tif", 99);
    
    cam.setPosition(0.0/2.0, 0.0/2.0, 1000.0);
}

//--------------------------------------------------------------
void ofApp::update(){
    boundingBox->setSizeCenter(ofVec3f(aabb_size->x, aabb_size->y, aabb_size->z));
    ofSetWindowTitle(to_string(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(30);
    cam.begin();
    ofEnableDepthTest();

    //ray viewe
    ofSetLineWidth(3.0);
    ofSetColor(0.0, 200.0, 180.0);
    //ofDrawLine(ofVec3f(cam.getPosition()+ofVec3f(-300)), ofVec3f(aabb_size));
    //ofDrawLine(co.x*0.5, co.y*0.5, co.z*0.5, 0.0, 0.0, 0.0);
    
    
    //ofDrawAxis(2000.0);
    
    shader.begin();
    glEnable(GL_TEXTURE_3D);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_3D , *(boundingBox->getTexID()));
    if(wrapMode==0){
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_REPEAT);
    }else if(wrapMode == 1){
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP);
    }else if(wrapMode == 2){
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_MIRRORED_REPEAT);
    }
    if(minFilterMode == 0){
        glTexParameteri(GL_TEXTURE_3D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    }else{
        glTexParameteri(GL_TEXTURE_3D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    }
    
    if(magFilterMode == 0){
        glTexParameteri(GL_TEXTURE_3D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    }else{
        glTexParameteri(GL_TEXTURE_3D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    }
    
    
    shader.setUniform1f("volume_tex", 0);
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    shader.setUniform3f("cameraPos", cam.getPosition());
    shader.setUniform3f("boundingSize", ofVec3f(aabb_size));
    
    shader.setUniform1f("_Intensity", _intencity);
    shader.setUniform1f("_Threshould", _threshould);
    shader.setUniform1f("_BlendRate", _brendRate);
    shader.setUniform1i("_Iteration", _iterration);
    shader.setUniform3f("_OffSet", _offSet);
    shader.setUniform3f("_ImageSize", _imageSize);
    
    
    ofMatrix4x4 modelMatrix;
    //modelMatrix.rotate(ofGetFrameNum()*0.4, 1.0, 1.0, 1.0);
    
    shader.setUniformMatrix4f("model", modelMatrix);
    shader.setUniformMatrix4f("invModel", modelMatrix.getInverse());
    ofMatrix4x4 viewMatrix;
    viewMatrix = ofGetCurrentViewMatrix();
    //cout << "---------"<< endl;
    //cout << viewMatrix << endl;
    shader.setUniformMatrix4f("view", viewMatrix);
    ofMatrix4x4 modeViewInvMatrix;
    modeViewInvMatrix = modelMatrix;
    modeViewInvMatrix.postMult(viewMatrix);
    shader.setUniformMatrix4f("modelViewInv", modeViewInvMatrix);
    ofMatrix4x4 projectionMatrix;
    projectionMatrix = cam.getProjectionMatrix();
    shader.setUniformMatrix4f("projection", projectionMatrix);
    
    boundingBox->drawCube();
    shader.end();
    
    //myVolume.drawVolume(0,0,0, ofGetHeight(), 0);
    
    cam.end();
    
    /*
    ofSetColor(0,0,0,255);
    ofDrawRectangle(0,0,270,90);
    ofSetColor(255,255,255,255);
    
    ofDrawBitmapString("volume dimensions: " + ofToString(myVolume.getVolumeWidth()) + "x" + ofToString(myVolume.getVolumeHeight()) + "x" + ofToString(myVolume.getVolumeDepth()) + "\n" +
                       "FBO quality (q/Q): " + ofToString(myVolume.getRenderWidth()) + "x" + ofToString(myVolume.getRenderHeight()) + "\n" +
                       "Z quality (z/Z):   " + ofToString(myVolume.getZQuality()) + "\n" +
                       "Threshold (t/T):   " + ofToString(myVolume.getThreshold()) + "\n" +
                       "Density (d/D):     " + ofToString(myVolume.getDensity()) + "\n" +
                       "Filter mode (l/n): " + (linearFilter?"linear":"nearest"),20,20);
    */
    
    ofDisableDepthTest();
    glDisable(GL_TEXTURE_3D);
    gui.draw();
    ofSetColor(255);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key)
    {
        case ' ':
            //shader.load("Shaders/_shader");
            shader.load("Shaders/_shader.vert", "Shaders/shader1.frag");
            break;
        case 's':
            shader.load("Shaders/_shader.vert", "Shaders/shader_AABB.frag");
            break;
        case 't':
            myVolume.setThreshold(myVolume.getThreshold()-0.01);
            break;
        case 'T':
            myVolume.setThreshold(myVolume.getThreshold()+0.01);
            break;
        case 'd':
            myVolume.setDensity(myVolume.getDensity()-0.01);
            break;
        case 'D':
            myVolume.setDensity(myVolume.getDensity()+0.01);
            break;
        case 'q':
            myVolume.setXyQuality(myVolume.getXyQuality()-0.01);
            break;
        case 'Q':
            myVolume.setXyQuality(myVolume.getXyQuality()+0.01);
            break;
        case 'z':
            myVolume.setZQuality(myVolume.getZQuality()-0.01);
            break;
        case 'Z':
            myVolume.setZQuality(myVolume.getZQuality()+0.01);
            break;
        case 'l':
            myVolume.setVolumeTextureFilterMode(GL_LINEAR);
            linearFilter = true;
            break;
        case 'n':
            myVolume.setVolumeTextureFilterMode(GL_NEAREST);
            linearFilter = false;
            break;
            //        case OF_KEY_UP:
            //            cam.getTarget().boom(-5);
            //            break;
            //        case OF_KEY_DOWN:
            //            cam.getTarget().boom(5);
            //            break;
            //        case OF_KEY_LEFT:
            //            cam.getTarget().truck(-5);
            //            break;
            //        case OF_KEY_RIGHT:
            //            cam.getTarget().truck(5);
            //            break;
    }

}

//--------------------------------------------------------------
