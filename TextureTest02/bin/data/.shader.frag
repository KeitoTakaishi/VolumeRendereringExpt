#version 120
uniform sampler2D tex0;
void main(void)
{
    // テクスチャ
    vec3 color_tex0 = texture2D(tex0, gl_TexCoord[0].st).xyz;
    gl_FragColor.rgb = color_tex0;
    gl_FragColor.a = 1.0;
}
