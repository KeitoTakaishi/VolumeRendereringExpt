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

struct Ray
{
    vec3 from;
    vec3 dir;
    float tmin;
    float tmax;
};

bool intersection(inout Ray ray)
{
    vec3 invDir = 1.0 / ray.dir;
    vec3 t1 = (-0.5 - ray.from) * invDir;
    vec3 t2 = (+0.5 - ray.from) * invDir;

    //input
    vec3 tmin3 = min(t1, t2);
    vec2 tmin2 = max(tmin3.xx, tmin3.yz);
    ray.tmin = max(tmin2.x, tmin2.y);

    //out
    vec3 tmax3 = max(t1, t2);
    vec2 tmax2 = min(tmax3.xx, tmax3.yz);
    ray.tmax = min(tmax2.x, tmax2.y);

    return ray.tmax >= ray.tmin;
}

void main(){
  vec3 worldDir = worldPos - cameraPosition;
  vec3 localDir = normalize(invModel * vec4(vec3(worldDir), 1.0)).xyz;

  Ray ray;
  ray.from = localPos;
  ray.dir = localDir;
  intersection(ray);

  vec3 localStep = localDir * ray.tmax / _Iteration;
  vec3 localPos = localPos;
  vec4 outColor = vec4(0.0);


  for (int i = 0; i < _Iteration; ++i)
    {
        if(outColor.a > 1.0)break;
        outColor += (1.0 - outColor.a) * texture3D(volume_tex, vec3(localPos + 0.5) + vec3(0.0, 0.0, u_time*0.5)) * _Intensity;
        localPos += localStep;
    }
    if(length(outColor.r) < _Threshould){
      discard;
    }else{
      gl_FragColor = outColor*vec4(0.0, 1.0, 1.0, 1.0);
    }
}
