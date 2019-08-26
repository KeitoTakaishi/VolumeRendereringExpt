//
//  BoundingBox.cpp
//  TextureTest03
//
//  Created by takaishi keito on 2019/08/13.
//

#include "BoundingBox.hpp"

BoundingBox::BoundingBox(){
    
}

BoundingBox::BoundingBox(ofVec3f size){
    float texVert = 1.0;
    /* Front side */
    volVerts[0] = ofVec3f(size.x, size.y, size.z);
    volVerts[1] = ofVec3f(0.0, size.y, size.z);
    volVerts[2] = ofVec3f(0.0, 0.0, size.z);
    volVerts[3] = ofVec3f(size.x, 0.0, size.z);
    
    texVerts[0] = ofVec3f(texVert, texVert, texVert);
    texVerts[1] = ofVec3f(0.0, texVert, texVert);
    texVerts[2] = ofVec3f(0.0, 0.0, texVert);
    texVerts[3] = ofVec3f(texVert, 0.0, texVert);
    
    
    /* Right side */
    volVerts[4] = ofVec3f(size.x, size.y, size.z);
    volVerts[5] = ofVec3f(size.x, 0.0, size.z);
    volVerts[6] = ofVec3f(size.x, 0.0, 0.0);
    volVerts[7] = ofVec3f(size.x, size.y, 0.0);
    
    texVerts[4] = ofVec3f(texVert, texVert, texVert);
    texVerts[5] = ofVec3f(texVert, 0.0, texVert);
    texVerts[6] = ofVec3f(texVert, 0.0, 0.0);
    texVerts[7] = ofVec3f(texVert, texVert, 0.0);
    
    /* Top side */
    volVerts[8] = ofVec3f(size.x, size.y, size.z);
    volVerts[9] = ofVec3f(size.x, size.y, 0.0);
    volVerts[10] = ofVec3f(0.0, size.y, 0.0);
    volVerts[11] = ofVec3f(0.0, size.y, size.z);
    
    texVerts[8] = ofVec3f(texVert, texVert, texVert);
    texVerts[9] = ofVec3f(texVert, texVert, 0.0);
    texVerts[10] = ofVec3f(0.0, texVert, 0.0);
    texVerts[11] = ofVec3f(0.0, texVert, texVert);
    
    /* Left side */
    volVerts[12] = ofVec3f(0.0, size.y, size.z);
    volVerts[13] = ofVec3f(0.0, size.y, 0.0);
    volVerts[14] = ofVec3f(0.0, 0.0, 0.0);
    volVerts[15] = ofVec3f(0.0, 0.0, size.z);
    
    texVerts[12] = ofVec3f(0.0, texVert, texVert);
    texVerts[13] = ofVec3f(0.0, texVert, 0.0);
    texVerts[14] = ofVec3f(0.0, 0.0, 0.0);
    texVerts[15] = ofVec3f(0.0, 0.0, texVert);
    
    /* Bottom side */
    volVerts[16] = ofVec3f(0.0, 0.0, 0.0);
    volVerts[17] = ofVec3f(size.x, 0.0, 0.0);
    volVerts[18] = ofVec3f(size.x, 0.0, size.z);
    volVerts[19] = ofVec3f(0.0, 0.0, size.z);
    
    texVerts[16] = ofVec3f(0.0, 0.0, 0.0);
    texVerts[17] = ofVec3f(texVert, 0.0, 0.0);
    texVerts[18] = ofVec3f(texVert, 0.0, texVert);
    texVerts[19] = ofVec3f(0.0, 0.0, texVert);
    
    
    /* Back side */
    volVerts[20] = ofVec3f(size.x, 0.0, 0.0);
    volVerts[21] = ofVec3f(0.0, 0.0, 0.0);
    volVerts[22] = ofVec3f(0.0, size.y, 0.0);
    volVerts[23] = ofVec3f(size.x, size.y, 0.0);
    
    texVerts[20] = ofVec3f(texVert, 0.0, 0.0);
    texVerts[21] = ofVec3f(0.0, 0.0, 0.0);
    texVerts[22] = ofVec3f(0.0, texVert, 0.0);
    texVerts[23] = ofVec3f(texVert, texVert, 0.0);
}

void BoundingBox::setSize(ofVec3f size, ofVec3f texRes){
    //ofVec3f texScale = ofVec3f(size.x/texRes.x, size.y/texRes.y, size.z/texRes.z);
    ofVec3f texScale = ofVec3f(1.0, 1.0, 1.0);
    cout << size << endl;
    
    /* Front side */
    volVerts[0] = ofVec3f(size.x, size.y, size.z);
    volVerts[1] = ofVec3f(0.0, size.y, size.z);
    volVerts[2] = ofVec3f(0.0, 0.0, size.z);
    volVerts[3] = ofVec3f(size.x, 0.0, size.z);
    
    texVerts[0] = ofVec3f(texScale.x, texScale.y, texScale.z);
    texVerts[1] = ofVec3f(0.0, texScale.y, texScale.z);
    texVerts[2] = ofVec3f(0.0, 0.0, texScale.z);
    texVerts[3] = ofVec3f(texScale.x, 0.0, texScale.z);
    
    
    /* Right side */
    volVerts[4] = ofVec3f(size.x, size.y, size.z);
    volVerts[5] = ofVec3f(size.x, 0.0, size.z);
    volVerts[6] = ofVec3f(size.x, 0.0, 0.0);
    volVerts[7] = ofVec3f(size.x, size.y, 0.0);
    
    texVerts[4] = ofVec3f(texScale.x, texScale.y, texScale.z);
    texVerts[5] = ofVec3f(texScale.x, 0.0, texScale.z);
    texVerts[6] = ofVec3f(texScale.x, 0.0, 0.0);
    texVerts[7] = ofVec3f(texScale.x, texScale.y, 0.0);
    
    
    
    /* Top side */
    volVerts[8] = ofVec3f(size.x, size.y, size.z);
    volVerts[9] = ofVec3f(size.x, size.y, 0.0);
    volVerts[10] = ofVec3f(0.0, size.y, 0.0);
    volVerts[11] = ofVec3f(0.0, size.y, size.z);
    
    texVerts[8] = ofVec3f(texScale.x, texScale.y, texScale.z);
    texVerts[9] = ofVec3f(texScale.x, texScale.y, 0.0);
    texVerts[10] = ofVec3f(0.0, texScale.y, 0.0);
    texVerts[11] = ofVec3f(0.0, texScale.y, texScale.z);
    
    /* Left side */
    volVerts[12] = ofVec3f(0.0, size.y, size.z);
    volVerts[13] = ofVec3f(0.0, size.y, 0.0);
    volVerts[14] = ofVec3f(0.0, 0.0, 0.0);
    volVerts[15] = ofVec3f(0.0, 0.0, size.z);
    
    texVerts[12] = ofVec3f(0.0, texScale.y, texScale.z);
    texVerts[13] = ofVec3f(0.0, texScale.y, 0.0);
    texVerts[14] = ofVec3f(0.0, 0.0, 0.0);
    texVerts[15] = ofVec3f(0.0, 0.0, texScale.z);
    
    
    /* Bottom side */
    volVerts[16] = ofVec3f(0.0, 0.0, 0.0);
    volVerts[17] = ofVec3f(size.x, 0.0, 0.0);
    volVerts[18] = ofVec3f(size.x, 0.0, size.z);
    volVerts[19] = ofVec3f(0.0, 0.0, size.z);
    
    texVerts[16] = ofVec3f(0.0, 0.0, 0.0);
    texVerts[17] = ofVec3f(texScale.x, 0.0, 0.0);
    texVerts[18] = ofVec3f(texScale.x, 0.0, texScale.z);
    texVerts[19] = ofVec3f(0.0, 0.0, texScale.z);
    
    /* Back side */
    volVerts[20] = ofVec3f(size.x, 0.0, 0.0);
    volVerts[21] = ofVec3f(0.0, 0.0, 0.0);
    volVerts[22] = ofVec3f(0.0, size.y, 0.0);
    volVerts[23] = ofVec3f(size.x, size.y, 0.0);
    
    texVerts[20] = ofVec3f(texScale.x, 0.0, 0.0);
    texVerts[21] = ofVec3f(0.0, 0.0, 0.0);
    texVerts[22] = ofVec3f(0.0, texScale.y, 0.0);
    texVerts[23] = ofVec3f(texScale.x, texScale.y, 0.0);
    
}

void BoundingBox::setSizeCenter(ofVec3f size, ofVec3f texRes){
    ofVec3f texScale = ofVec3f(size.x/texRes.x, size.y/texRes.y, size.z/texRes.z);
    
    
    /* Front side */
    volVerts[0] = ofVec3f(size.x/2.0, size.y/2.0, size.z/2.0);
    volVerts[1] = ofVec3f(-size.x/2.0, size.y/2.0, size.z/2.0);
    volVerts[2] = ofVec3f(-size.x/2.0, -size.y/2.0, size.z/2.0);
    volVerts[3] = ofVec3f(size.x/2.0, -size.y/2.0, size.z/2.0);
    
    texVerts[0] = ofVec3f(texScale.x, texScale.y, texScale.z);
    texVerts[1] = ofVec3f(0.0, texScale.y, texScale.z);
    texVerts[2] = ofVec3f(0.0, 0.0, texScale.z);
    texVerts[3] = ofVec3f(texScale.x, 0.0, texScale.z);
    
    
    /* Right side */
    volVerts[4] = ofVec3f(size.x/2.0,   size.y/2.0,       size.z/2.0);
    volVerts[5] = ofVec3f(size.x/2.0,   -1.0*size.y/2.0,  size.z/2.0);
    volVerts[6] = ofVec3f(size.x/2.0,   -1.0*size.y/2.0,  -1.0*size.z/2.0);
    volVerts[7] = ofVec3f(size.x/2.0,   size.y/2.0,       -1.0*size.z/2.0);
    
    texVerts[4] = ofVec3f(texScale.x, texScale.y, texScale.z);
    texVerts[5] = ofVec3f(texScale.x, 0.0, texScale.z);
    texVerts[6] = ofVec3f(texScale.x, 0.0, 0.0);
    texVerts[7] = ofVec3f(texScale.x, texScale.y, 0.0);
    
    
    
    /* Top side */
    volVerts[8] = ofVec3f(size.x/2.0,       size.y/2.0, size.z/2.0);
    volVerts[9] = ofVec3f(size.x/2.0,       size.y/2.0, -1.0*size.z/2.0);
    volVerts[10] = ofVec3f(-1.0*size.x/2.0, size.y/2.0, -1.0*size.z/2.0);
    volVerts[11] = ofVec3f(-1.0*size.x/2.0, size.y/2.0, size.z/2.0);
    
    texVerts[8] = ofVec3f(texScale.x, texScale.y, texScale.z);
    texVerts[9] = ofVec3f(texScale.x, texScale.y, 0.0);
    texVerts[10] = ofVec3f(0.0, texScale.y, 0.0);
    texVerts[11] = ofVec3f(0.0, texScale.y, texScale.z);
    
    /* Left side */
    volVerts[12] = ofVec3f(-1.0*size.x/2.0, size.y/2.0,     size.z/2.0);
    volVerts[13] = ofVec3f(-1.0*size.x/2.0, size.y/2.0,     -1.0*size.z/2.0);
    volVerts[14] = ofVec3f(-1.0*size.x/2.0, -1.0*size.y/2.0, -1.0*size.z/2.0);
    volVerts[15] = ofVec3f(-1.0*size.x/2.0, -1.0*size.y/2.0, size.z/2.0);
    
    texVerts[12] = ofVec3f(0.0, texScale.y, texScale.z);
    texVerts[13] = ofVec3f(0.0, texScale.y, 0.0);
    texVerts[14] = ofVec3f(0.0, 0.0, 0.0);
    texVerts[15] = ofVec3f(0.0, 0.0, texScale.z);
    
    
    /* Bottom side */
    volVerts[16] = ofVec3f(-1.0*size.x/2.0, -1.0*size.y/2.0, -1.0*size.z/2.0);
    volVerts[17] = ofVec3f(size.x/2.0,      -1.0*size.y/2.0, -1.0*size.z/2.0);
    volVerts[18] = ofVec3f(size.x/2.0,      -1.0*size.y/2.0, size.z/2.0);
    volVerts[19] = ofVec3f(-1.0*size.x/2.0, -1.0*size.y/2.0, size.z/2.0);
    
    texVerts[16] = ofVec3f(0.0, 0.0, 0.0);
    texVerts[17] = ofVec3f(texScale.x, 0.0, 0.0);
    texVerts[18] = ofVec3f(texScale.x, 0.0, texScale.z);
    texVerts[19] = ofVec3f(0.0, 0.0, texScale.z);
    
    /* Back side */
    volVerts[20] = ofVec3f(size.x/2.0,          -1.0*size.y/2.0,    -1.0*size.z/2.0);
    volVerts[21] = ofVec3f(-1.0*size.x/2.0,     -1.0*size.y/2.0,    -1.0*size.z/2.0);
    volVerts[22] = ofVec3f(-1.0*size.x/2.0,     size.y/2.0,         -1.0*size.z/2.0);
    volVerts[23] = ofVec3f(size.x/2.0,          size.y/2.0,         -1.0*size.z/2.0);
    
    texVerts[20] = ofVec3f(texScale.x, 0.0, 0.0);
    texVerts[21] = ofVec3f(0.0, 0.0, 0.0);
    texVerts[22] = ofVec3f(0.0, texScale.y, 0.0);
    texVerts[23] = ofVec3f(texScale.x, texScale.y, 0.0);
    
}


void BoundingBox::fileLoader(string path, string prefix, string extension, int fileNum){
    //ofDisableArbTex();
    string filePath, indexStr;
    img.load("volumes/head/cthead-8bit001.tif");
    ofVec3f size = ofVec3f(img.getWidth(), img.getHeight(), fileNum);
    //cout << "image size : " << size << endl;
    int num = size.x*size.y*size.z*4;
    pixels = new unsigned char[num];
    for(int z = 0; z < size.z; z++){
        if(z < 9){
            indexStr = "00" + to_string(z+1);
        }else{
            indexStr = "0" + to_string(z+1);
        }
        filePath = path + "/" + prefix + indexStr + extension;
        //cout << "filePath : " << filePath << endl;
        bool isLoad = img.load(filePath);
        //cout << isLoad << endl;
        
        for(int y = 0; y < size.y; y++){
            for(int x = 0; x < size.x; x++){
                int index = (x + y*size.x + z*size.x*size.y )*4;
                pixels[index] = img.getPixels()[x+y*size.x];
                //cout << pixels[index] << endl;
                pixels[index+1] = img.getPixels()[x+y*size.x];
                pixels[index+2] = img.getPixels()[x+y*size.x];
                pixels[index+3] = 255.0;
            }
        }
    }
    
    glEnable(GL_TEXTURE_3D);
    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_3D , texID);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    glTexParameteri(GL_TEXTURE_3D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_3D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_MIRRORED_REPEAT);
    
    glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA, size.x, size.y, size.z,
                 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA, size.x, size.y, size.z,
                 0, GL_RGBA, GL_UNSIGNED_INT, pixels);
    
    glDisable(GL_TEXTURE_3D);
    
}

unsigned char* BoundingBox::binaryFileLoader(string path, ofVec3f texRes, int ch){
    std::ifstream fs(path.c_str(), std::ios::binary);
    if(fs.fail()){
        cout << "failed load file" << endl;
    }
    
    int pixleNum = texRes.x * texRes.y * texRes.z * ch;
    unsigned char *pixle = new unsigned char [pixleNum];
    fs.read((char*)pixle,sizeof(double)*pixleNum);
    cout << "-------Load Done--------" << endl;
    return pixle;
}

void BoundingBox::pixelStreamLoader(unsigned char *p, ofVec3f texSize, int ch){
    int num = texSize.x * texSize.y * texSize.z * 4;
    pixels = new unsigned char[num];
    
    for(int z = 0; z < texSize.z; z++){
        for(int y = 0; y < texSize.y; y++){
            for(int x = 0; x <texSize.x; x++){
                int index = (x+y*texSize.x+z*texSize.x*texSize.y);
                int _index = (x+y*texSize.x+z*texSize.x*texSize.y)*4;
                if(ch == 1){
                    pixels[_index] = p[index];
                    pixels[_index+1] = p[index];
                    pixels[_index+2] = p[index];
                    pixels[_index+3] = 255;
                }else if(ch == 3){
                    pixels[_index] = p[index];
                    pixels[_index+1] = p[index+1];
                    pixels[_index+2] = p[index+2];
                    pixels[_index+3] = 255;
                }else if(ch == 4){
                    pixels[_index] = p[index];
                    pixels[_index+1] = p[index+1];
                    pixels[_index+2] = p[index+2];
                    pixels[_index+3] = p[index+3];
                }
            }
        }
    }
    
    glEnable(GL_TEXTURE_3D);
    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_3D , texID);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    glTexParameteri(GL_TEXTURE_3D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_3D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    
    
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_MIRRORED_REPEAT);
    
    glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA, texSize.x, texSize.y, texSize.z,
                 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    
    glDisable(GL_TEXTURE_3D);
}

void BoundingBox::createTexture3D(ofVec3f texSize){
    int num = texSize.x*texSize.y*texSize.z*4;
    pixels = new unsigned char[num];
    ofVec3f res = texSize;
    for(int z = 0; z < res.z; z++){
        for(int y = 0; y < res.y; y++){
            for(int x = 0; x < res.x; x++){
                int index = (x+y*res.x+z*res.x*res.y)*4;
                pixels[index] = x*255.0/(texSize.x-1.0);
                //pixels[index+1] = 0.0;
                pixels[index+1] = y*255.0/(texSize.y-1.0);
                pixels[index+2] = z;
                pixels[index+3] = 255.0;
            }
        }
    }
    
    glEnable(GL_TEXTURE_3D);
    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_3D , texID);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    glTexParameteri(GL_TEXTURE_3D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_3D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    
    
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_REPEAT);
    
    glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA, texSize.x, texSize.y, texSize.z,
                 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    
    glDisable(GL_TEXTURE_3D);
}


void BoundingBox::drawCube(){
    glEnable(GL_DEPTH_TEST);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    //glEnableClientState(GL_COLOR_ARRAY);
    //stride？
    glVertexPointer(3, GL_FLOAT, sizeof(ofVec3f), volVerts);
    glTexCoordPointer(3, GL_FLOAT, sizeof(ofVec3f), texVerts);
    //glColorPointer(3,GL_FLOAT, sizeof(ofVec3f), volVerts);
    glDrawArrays(GL_QUADS, 0, 24);
    
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    //glDisableClientState(GL_COLOR_ARRAY);
};


GLuint* BoundingBox::getTexID(){
    return &(this->texID);
}

