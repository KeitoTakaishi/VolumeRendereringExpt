#version 120
varying vec3 cameraPosition;
void main()
{
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
    gl_TexCoord[0] = gl_MultiTexCoord0; //poop
    cameraPosition = (gl_ModelViewMatrixInverse * vec4(0.,0.,0.,1.)).xyz;
}
