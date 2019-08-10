//
//  transformMatrix.cpp
//  ShaderTest
//
//  Created by takaishi keito on 2019/08/10.
//

#include "transformMatrix.hpp"

ofMatrix4x4* transformMatrix::getViewMatrix(ofVec3f eye, ofVec3f target, ofVec3f up){
    ofMatrix4x4 viewMatrix;
    float l;
    float m[16];
    //z vector (z = u - t)
    target.x = eye.x - target.x;
    target.y = eye.y - target.y;
    target.z = eye.z - target.z;
    l = sqrtf(pow(target.x, 2.0) + pow(target.y, 2.0) + pow(target.z, 2.0));
    m[ 2] = target.x / l;
    m[ 6] = target.y / l;
    m[10] = target.z / l;
    
    
    //x vector (x = u x z)
    target.x = up.y * m[10] - up.z * m[ 6];
    target.y = up.z * m[ 2] - up.x * m[10];
    target.z = up.x * m[ 6] - up.y * m[ 2];
    l = sqrtf(pow(target.x, 2.0) + pow(target.y, 2.0) + pow(target.z, 2.0));
    m[ 0] = target.x / l;
    m[ 4] = target.y / l;
    m[ 8] = target.z / l;
    
    //y vector(y = z x x)
    m[ 1] = m[ 6] * m[ 8] - m[10] * m[ 4];
    m[ 5] = m[10] * m[ 0] - m[ 2] * m[ 8];
    m[ 9] = m[ 2] * m[ 4] - m[ 6] * m[ 0];
    
    
    /* 平行移動 */
    m[12] = -(eye.x * m[ 0] + eye.y * m[ 4] + eye.z * m[ 8]);
    m[13] = -(eye.x * m[ 1] + eye.y * m[ 5] + eye.z * m[ 9]);
    m[14] = -(eye.x * m[ 2] + eye.y * m[ 6] + eye.z * m[10]);
    
    //other
    m[ 3] = m[ 7] = m[11] = 0.0f;
    m[15] = 1.0f;
    
    
    viewMatrix.set(m[0], m[1], m[2], m[3],
               m[4], m[5], m[6], m[7],
               m[8], m[9], m[10], m[11],
               m[12], m[13], m[14], m[15]);
    return viewMatrix;
}
