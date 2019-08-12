#version 120
uniform sampler2D texture;
uniform sampler2D texture2;
void main(void)
{
    vec3 color = texture2D(texture, gl_TexCoord[0].st).xyz;
    vec3 color2 = texture2D(texture2, gl_TexCoord[0].st).xyz;
    gl_FragColor.rgb = color.rgb + color2.rgb;
    gl_FragColor.a = 1.0;
}
