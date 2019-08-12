#version 120
//uniform sampler2DRect tex0;
uniform sampler2D tex0;
varying vec2 texCoordVarying;

void main()
{
    //gl_FragColor = vec4(1.0);
    gl_FragColor = texture2DRect(tex0, texCoordVarying);
}

