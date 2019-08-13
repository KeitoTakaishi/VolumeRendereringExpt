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

void BoundingBox::setSize(ofVec3f size){
    ofVec3f texScale = ofVec3f(1.0*size.x/255.0, 1.0*size.y/255.0, 1.0*size.z/255.0);
   
    
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


void BoundingBox::fileLoader(string path){
//    int startFrame = 0;
//    int curFrame = 0;
    //ofDisableArbTex();
    img.load(path);
    ofVec3f size = ofVec3f(img.getWidth(), img.getHeight(), 1);
    cout << "image size : " << size << endl;
    int num = size.x*size.y*size.z*4;
    pixels = new unsigned char[num];
    for(int z = 0; z < size.z; z++){
        for(int y = 0; y < size.y; y++){
            for(int x = 0; x < size.x; x++){
                int index = (x+y*size.x+z*size.x*size.y)*4;
                pixels[index] = img.getPixels()[x+y*size.x];
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
    
    glDisable(GL_TEXTURE_3D);
    
    
}


void BoundingBox::createTexture3D(ofVec3f texSize){
    int num = texSize.x*texSize.y*texSize.z*4;
    pixels = new unsigned char[num];
    ofVec3f size = texSize;
    for(int z = 0; z < size.z; z++){
        for(int y = 0; y < size.y; y++){
            for(int x = 0; x < size.x; x++){
                int index = (x+y*size.x+z*size.x*size.y)*4;
                pixels[index] = x;
                pixels[index+1] = y;
                pixels[index+2] = z*255.0/10.0;
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
    
    glDisable(GL_TEXTURE_3D);
}
void BoundingBox::drawCube(){
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
