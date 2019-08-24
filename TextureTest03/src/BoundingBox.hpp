//
//  BoundingBox.hpp
//  TextureTest03
//
//  Created by takaishi keito on 2019/08/13.
//

//texture3d viewer

#ifndef BoundingBox_hpp
#define BoundingBox_hpp

#include <ofMain.h>
#include <dirent.h>

class BoundingBox{
public:
    BoundingBox();
    BoundingBox(ofVec3f size);
    
    void fileLoader(string path, string prefix, string extensionm, int fileNum);
    void createTexture3D(ofVec3f texSize);
    
    ofVec3f volVerts[24];
    ofVec3f texVerts[24];
    void setSize(ofVec3f size);
    void setSizeCenter(ofVec3f size);
    void drawCube();
    
    GLuint* getTexID();
private:
    unsigned char *pixels;
    ofImage img;
    GLuint texID;
};

#endif /* BoundingBox_hpp */
