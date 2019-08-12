#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    GLint num_tex_units;
    glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &num_tex_units);
    cout << "Max texture units = " << num_tex_units << endl;
    
    ofBackground(0);
    shader.load("Shaders/shader");
    
    //texture1---------------
    int res = 256;
    for(int i = 0; i < res; i++){
        for(int j = 0; j < res; j++){
            int index = (j+i*res)*4;
            pixels[index] = i;
            pixels[index+1] = j;
            pixels[index+2] = (i+j)*0.5;
            pixels[index+3] = 255.0;
        }
    }

    glEnable(GL_TEXTURE_2D);
    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &texID);//テクスチャ生成
    cout << "texID : " << texID << endl;
    glBindTexture(GL_TEXTURE_2D , texID);//idを指定してバインド
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);//テクスチャデータの区切りを設定
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(
                 GL_TEXTURE_2D , 0 , GL_RGBA , 256 , 256,
                 0 , GL_RGBA , GL_UNSIGNED_BYTE , pixels
                 );
    ///glDeleteTextures(1 , &texID);
    //texture2---------------
    for(int i = 0; i < res; i++){
        for(int j = 0; j < res; j++){
            int index = (j+i*res)*4;
            pixels2[index] = 120;
            pixels2[index+1] = 0;
            pixels2[index+2] = 0;
            pixels2[index+3] = 255.0;
        }
    }
    glEnable(GL_TEXTURE_2D);
    glActiveTexture(GL_TEXTURE1);
    glGenTextures(1, &texID2);//テクスチャ生成
    cout << "texID2 : " << texID2 << endl;
    glBindTexture(GL_TEXTURE_2D , texID2);//idを指定してバインド
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);//テクスチャデータの区切りを設定
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexImage2D(
                 GL_TEXTURE_2D , 0 , GL_RGBA , 256 , 256,
                 0 , GL_RGBA , GL_UNSIGNED_BYTE , pixels2
                 );
    //glDeleteTextures(1 , &texID2);
    //----------------------
    mesh.setMode(ofPrimitiveMode::OF_PRIMITIVE_TRIANGLE_FAN);
    float imgSize = res;
    imgSize = 1.0;


    mesh.addTexCoord(ofVec2f(0.0, 0.0));
    mesh.addVertex(ofVec3f(-res, res, 0.0));
    
    mesh.addTexCoord(ofVec2f(0, imgSize));
    mesh.addVertex(ofVec3f(-res, -res, 0.0));
    mesh.addTexCoord(ofVec2f(imgSize, imgSize));
    mesh.addVertex(ofVec3f(res, -res, 0.0));
    
    mesh.addTexCoord(ofVec2f(imgSize, 0.0));
    mesh.addVertex(ofVec3f(res, res, 0.0));
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //glEnable(GL_ALPHA_TEST);
    cam.begin();
    shader.begin();
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D , texID);
    shader.setUniform1i("texture", 0);
    
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D , texID2);
    shader.setUniform1i("texture2", 1);
    
    mesh.draw();
    shader.end();
    cam.end();
}

//--------------------------------------------------------------

