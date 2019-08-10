#version 150

uniform mat4 modelViewProjectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 projMatrix;
uniform mat4 modelMatrix;
in vec4 position;
void main()
{
  vec4 p = projMatrix * viewMatrix * modelMatrix * position;
  //p.x = p.x * 2.0;
	//gl_Position = modelViewProjectionMatrix * p;
  gl_Position = p;
}
