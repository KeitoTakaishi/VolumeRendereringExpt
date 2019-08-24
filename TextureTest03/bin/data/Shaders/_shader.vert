#version 120

uniform vec3 cameraPos;
uniform mat4 model;
uniform mat4 projection;
uniform mat4 view;
uniform vec3 boundingSize;
uniform vec3 _ImageSize;


varying vec3 localPos;
varying vec3 worldPos;
varying vec3 cameraPosition;

void main()
{
    localPos = gl_Vertex.xyz / (_ImageSize+vec3(100.0, 100.0 ,100.0));
    worldPos = (model * gl_Vertex).xyz;
    cameraPosition = (gl_ModelViewMatrixInverse * vec4(0.,0.,0.,1.)).xyz;
    gl_TexCoord[0] = gl_MultiTexCoord0;
    gl_Position = projection * view * model * gl_Vertex;
}
