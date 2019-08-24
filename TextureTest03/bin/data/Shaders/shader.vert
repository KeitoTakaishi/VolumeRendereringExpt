#version 120
varying vec3 cameraPosition;
uniform mat4 modelViewInv;

void Rotate(){
  
}

void main()
{
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
    gl_TexCoord[0] = gl_MultiTexCoord0; //poop
    cameraPosition = (modelViewInv * vec4(0.,0.,0.,1.)).xyz;
    cameraPosition.xyz *= -1.0;
}
