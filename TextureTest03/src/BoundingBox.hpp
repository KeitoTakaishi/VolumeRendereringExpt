//
//  BoundingBox.hpp
//  TextureTest03
//
//  Created by takaishi keito on 2019/08/13.
//

#ifndef BoundingBox_hpp
#define BoundingBox_hpp

#include <ofMain.h>

class BoundingBox{
public:
    BoundingBox();
    BoundingBox(ofVec3f size);
    
    ofVec3f volVerts[24];
    ofVec3f texVerts[24];
    void setSize(ofVec3f size);
    void drawCube();
};

#endif /* BoundingBox_hpp */
