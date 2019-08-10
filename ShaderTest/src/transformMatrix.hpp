//
//  transformMatrix.hpp
//  ShaderTest
//
//  Created by takaishi keito on 2019/08/10.
//

#ifndef transformMatrix_hpp
#define transformMatrix_hpp

#include <stdio.h>
#include "ofMain.h"

class transformMatrix{
    transformMatrix();
    ofMatrix4x4* getViewMatrix(ofVec3f eye, ofVec3f target, ofVec3f up);
    
};
#endif /* transformMatrix_hpp */
