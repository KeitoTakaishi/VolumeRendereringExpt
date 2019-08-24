//texture3D preview
#version 120

//#define _Intensity 0.2
uniform float _Intensity;
uniform float _Threshould;
uniform float _BlendRate;
uniform int _Iteration;
uniform vec3 _OffSet;

uniform sampler3D volume_tex;
uniform float u_time;
uniform mat4 invModel;

varying vec3 localPos;
varying vec3 worldPos;
varying vec3 cameraPosition;

/*
void main()
{
    vec3 tex = gl_TexCoord[0].xyz;
    tex += vec3(1.0/255.0, 1.0/255.0, 1.0/255.0);
    //tex.z = mod(tex.z + u_time, 1.0);

    vec4 col = texture3D(volume_tex, tex + vec3(0.0, 0.0, u_time));
    vec3 dir = tex - cameraPosition/1000.0;
    if (length(col.rgb) < 0.1){
        discard;
    }
    gl_FragColor = col;
}
*/
void main(){
  vec3 wdir = worldPos - cameraPosition;
  vec3 ldir = normalize(invModel * vec4(vec3(wdir), 1.0)).xyz;
  vec3 lstep = ldir / _Iteration;
  vec3 lpos = localPos;
  float oColor = 0.0;
  float accumulationAlpha = 0.0;
  float isCol = 0.0;




  for (int i = 0; i < _Iteration; ++i)
    {
        //累積不透明度

        vec3 l = vec3(lpos.x,1.0*lpos.y,lpos.z);
        //l.xyz = clamp(l.xyz , 0.0, 1.0); //多分肝になる
        float a = texture3D(volume_tex,  fract(l+vec3(0.5, u_time/2.0, 0.5)+_OffSet) ).g;

        if(i == 0){
          accumulationAlpha = a;
        }else{
            accumulationAlpha = (1.0- a)*accumulationAlpha;
        }
        oColor += (1 - oColor) * a * _Intensity;

        lpos += lstep;

        if(oColor >= 1.0)break;

        if(abs(lpos.x) >= 1.0){
          break;
        }else if(abs(lpos.y) >= 1.0){
          break;
        }else if(abs(lpos.z) >= 1.0){
          break;
        }else if(accumulationAlpha > 1.0){
          isCol = 1.0;
          break;
        }
    }


    if(length(oColor) <  _Threshould){
      gl_FragColor = vec4(vec3(oColor * vec3(0.0, 0.0, 0.0)), 0.0) + vec4(0.2);
    }else{
      gl_FragColor = vec4(vec3(oColor)*vec3(1.0, 1.0, pow(1.2, oColor*2.0)), 1.0)+vec4(0.2);
    }

  //gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0) + vec4(texture3D(volume_tex, lpos ));

}
