//#extension GL_ARB_texture_rectangle : enable
#version 120
varying vec3 cameraPosition;
uniform sampler3D volume_tex;
uniform float u_time;
void main()
{
    
    vec3 tex = gl_TexCoord[0].xyz;
    //tex += vec3(1.0/255.0, 1.0/255.0, 1.0/255.0);
    tex = vec3(min(tex.x, 1.0), min(tex.y, 1.0), min(tex.z, 1.0));
    
    //vec3 tex = gl_TexCoord[0].xyz + vec3(-1.0/128.0, -1.0/128.0, 0.0);
    //tex.z = mod(tex.z + u_time, 1.0);
    
    vec4 col = texture3D(volume_tex, tex);
    gl_FragColor = col;
    
   
}
