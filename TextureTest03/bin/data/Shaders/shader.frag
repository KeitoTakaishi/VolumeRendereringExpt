//#extension GL_ARB_texture_rectangle : enable
#version 120
varying vec3 cameraPosition;

uniform sampler3D volume_tex;
uniform vec3 vol_d;
uniform vec3 vol_d_pot;
uniform vec2 bg_d;
uniform float zoffset;
uniform float quality;
uniform float threshold;
uniform float density;
uniform float t;

struct Ray {
    vec3 Origin;
    vec3 Dir;
};

struct BoundingBox {
    vec3 Min;
    vec3 Max;
};

bool IntersectBox(Ray r, BoundingBox box, out float t0, out float t1)
{
    //min = (min - p) / d
    //vec3 invR = 1.0 / normalize(r.Dir);
    //vec3 tbot = invR * (box.Min-r.Origin);
    //vec3 ttop = invR * (box.Max-r.Origin);
    
    vec3 tbot = (box.Min-r.Origin) / normalize(r.Dir);//aabbの近い面へのベクトル係数
    vec3 ttop = (box.Max-r.Origin) / normalize(r.Dir);//aabbの遠い面へのベクトル係数
    
    vec3 tmin = min(ttop, tbot);
    vec3 tmax = max(ttop, tbot);
//    tmin = tbot;
//    tmax = ttop;
    
    /*
     //vec2(max(x,y), max(x,z));
     vec2 t = vec2(max(tmin.x, tmin.y), max(tmin.x, tmin.z));
     */
    vec2 t = max(tmin.xx, tmin.yz);
    //output : t0, input : t1
    t0 = max(t.x, t.y);
    t = min(tmax.xx, tmax.yz);
    t1 = min(t.x, t.y);
    return t0 <= t1;
}

void main()
{

//    vec3 minv = vec3(0.)+1./vol_d_pot;
//    vec3 maxv = (vol_d/vol_d_pot)-1./vol_d_pot;
    vec3 minv = vec3(0.);
    vec3 maxv = vec3(1.0);
    vec3 vec;
    //(256, 256, 99)
    vec3 vold = (maxv-minv)*vol_d;
    float vol_l = length(vold);

    vec4 col_acc = vec4(0,0,0,0);
    vec3 zOffsetVec = vec3(0.0,0.0,zoffset/vol_d_pot.z);
    vec3 backPos = gl_TexCoord[0].xyz;
    vec3 lookVec = normalize(backPos - cameraPosition);


    Ray eye = Ray( cameraPosition, lookVec);
    BoundingBox box = BoundingBox(vec3(0.),vec3(1.));

    float tnear, tfar;
    //そもそもbounding boxと交差するか？
    IntersectBox(eye, box, tnear, tfar);
    if(tnear < 0.15) tnear = 0.15;
    if(tnear > tfar) discard;

    vec3 rayStart = (eye.Origin + eye.Dir * tnear)*(maxv-minv)+minv;//vol_d/vol_d_pot;
    vec3 rayStop = (eye.Origin + eye.Dir * tfar)*(maxv-minv)+minv;//vol_d/vol_d_pot;

    vec3 dir = rayStop - rayStart; // starting position of the ray

    vec = rayStart;
    float dl = length(dir);
    if(dl == clamp(dl,0.,vol_l)) {
       int steps = int(floor(length(vold * dir) * quality));
       vec3 delta_dir = dir/float(steps);
       vec4 color_sample;
       float aScale =  density/quality;
       
       float random = fract(sin(gl_FragCoord.x * 12.9898 + gl_FragCoord.y * 78.233) * 43758.5453);
       vec += delta_dir * random;
       
       //raycast
       for(int i = 0; i < steps; i++)
       {
           vec3 vecz = vec + zOffsetVec;
           //if(vecz.z > maxv.z) vecz.z-=maxv.z;
           color_sample = texture3D(volume_tex, vec3(vecz.x, vecz.y, mod(vecz.z-0.0, 1.0) ) );
           if(color_sample.a > threshold) {
               float oneMinusAlpha = 1. - col_acc.a;
               color_sample.a *= aScale;
               col_acc.rgb = mix(col_acc.rgb, color_sample.rgb * color_sample.a, oneMinusAlpha);
               col_acc.a += color_sample.a * oneMinusAlpha;
               col_acc.rgb /= col_acc.a;
               if(col_acc.a >= 1.0) {
                   break; // terminate if opacity > 1
               }
           }
           vec += delta_dir;
       }
    }
// export the rendered color
    gl_FragColor = vec4(col_acc.x*3.0, col_acc.y*1.0, col_acc.z*3.0, col_acc.w);
}
