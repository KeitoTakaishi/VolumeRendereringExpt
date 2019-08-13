#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofImage img;
    img.load(".");
    ofSetFrameRate(60);
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    /*
    imageSequence.init("volumes/head/cthead-8bit",3,".tif", 1);
    volWidth = imageSequence.getWidth();
    volHeight = imageSequence.getHeight();
    volDepth = imageSequence.getSequenceLength();
    
    cout << "setting up volume data buffer at " << volWidth << "x" << volHeight << "x" << volDepth <<"\n";
    
    //initでfileをopenして何枚画像データがあるか確認
    volumeData = new unsigned char[volWidth*volHeight*volDepth*4];
    
    
    //1フレームロードしてピクセルデータを取得
    for(int z=0; z<volDepth; z++)
    {
        imageSequence.loadFrame(z);
        for(int x=0; x<volWidth; x++)
        {
            for(int y=0; y<volHeight; y++)
            {
                // convert from greyscale to RGBA, false color
                int i4 = ((x+volWidth*y)+z*volWidth*volHeight)*4;//index
                int sample = imageSequence.getPixels()[x+y*volWidth];//輝度値
                ofColor c;
                c.setHsb(sample, 255-sample, sample);
                volumeData[i4] = c.r;
                volumeData[i4+1] = c.g;
                volumeData[i4+2] = c.b;
                volumeData[i4+3] = sample;
            }
        }
    }
    
    myVolume.setup(volWidth, volHeight, volDepth, ofVec3f(1,1,2),false);
    //texture allocate
    myVolume.updateVolumeData(volumeData,volWidth,volHeight,volDepth,0,0,0);
    //texture(load)
    
    myVolume.setRenderSettings(1.0, 0.75, 0.75, 0.1);
    
    */
    
    
    cam.setDistance(1000);
    cam.enableMouseInput();
    
    ofVec3f size = ofVec3f(256.0);
    boundingBox = new BoundingBox(size);
    shader.load("Shaders/shader.vert", "Shaders/shader1.frag");
    
    
    
    gui.setup("Bounding-Box");
    gui.add(aabb_size.setup("Boundgin Size", ofVec3f(256,256,256), ofVec3f(0, 0, 0), ofVec3f(3000,3000,3000)));
    gui.add(wrapMode.setup("WRAP_MODE", 0, 0, 2));
    gui.add(minFilterMode.setup("MAG_FILTER_MODE", 0, 0, 1));
    gui.add(magFilterMode.setup("MIN_FILTER_MODE", 0, 0, 1));
    
    //boundingBox->createTexture3D(ofVec3f(255,255,10));
    boundingBox->fileLoader("tex.jpg");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(50);
    boundingBox->setSize(ofVec3f(aabb_size->x, aabb_size->y, aabb_size->z));
    ofEnableDepthTest();
    glEnable(GL_TEXTURE_3D);
    

    
    cam.begin();
    ofDrawAxis(2000.0);
    shader.begin();
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_3D , *(boundingBox->getTexID()));
    
    if(wrapMode==0){
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_MIRRORED_REPEAT);
    }else if(wrapMode == 1){
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    }else if(wrapMode == 2){
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_REPEAT);
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
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key)
    {
        case ' ':
            shader.load("Shaders/shader.vert", "Shaders/shader1.frag");
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
