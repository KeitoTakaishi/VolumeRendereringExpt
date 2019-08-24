//#extension GL_ARB_texture_rectangle : enable
#version 120
#define RAYMARCH_ITERATIONS 3.0
#define DENSITY_INTENSITY 2.0

uniform sampler3D volume_tex;
uniform float u_time;
uniform vec3 cameraPos;
uniform vec3 BOUNDING_BOX_SIZE;


vec3 cameraDir(vec3 ro, vec3 ta, vec2 st) {
    vec3 z = normalize(ta - ro);
    vec3 up = vec3(0.0, 1.0, 0.0);
    vec3 x = normalize(cross(z, up));
    vec3 y = normalize(cross(x, z));
    vec3 rd = normalize(x * st.x + y * st.y + z * 1.75);
    return rd;
}


bool IntersectBox(vec3 ro,vec3 rd, vec3 c0, vec3 c1, out float t0, out float t1)
{
    vec3 tbot = (c0-ro) / normalize(rd);//aabbの近い面へのベクトル係数
    vec3 ttop = (c1-ro) / normalize(rd);//aabbの遠い面へのベクトル係数
    
    vec3 tmin = min(ttop, tbot);
    vec3 tmax = max(ttop, tbot);

    vec2 t = max(tmin.xx, tmin.yz);
    //output : t0, input : t1
    t0 = max(t.x, t.y);
    t = min(tmax.xx, tmax.yz);
    t1 = min(t.x, t.y);
    return t0 <= t1;
}

float sdSphere(vec3 p, float r) {
    return length(p) - r;
}

float sampleDensity(vec3 p) {
    float d= sdSphere(p, 3.0);
    return d;
}
vec4 raymarch(vec3 rayOrigin, vec3 rayDirection, float tmin, float tmax) {
    float raymarchSize = sqrt(2.0) * BOUNDING_BOX_SIZE.x / float(RAYMARCH_ITERATIONS);
    float densityScale = DENSITY_INTENSITY * raymarchSize;
    vec3 rayStep = rayDirection * raymarchSize;
    vec3 color = vec3(0.0);
    float transmittance = 1.0;
    vec3 position = rayOrigin + tmin * rayDirection;
    for (int ri = 0; ri < RAYMARCH_ITERATIONS; ri++) {
        float density = sampleDensity(position);
        if (density > 0.001) { // 密度が一定以下の場合、効率化するために計算を省略する
            density = clamp(density * densityScale, 0.0, 1.0);
            transmittance *= 1.0 - density;
        }
        if (transmittance < 0.001) { // 透明度が0に近づいたら終了する
            break;
        }
        position += rayStep; // レイを進める
    }
    return vec4(color, 1.0 - transmittance);
}

void main()
{
    vec2 resolution = vec2(1024,768);
    vec2 st = (2.0 * gl_FragCoord.xy - resolution) / min(resolution.x, resolution.y);
    vec3 ta = vec3(0.0);
    vec3 ro = cameraPos; //camera position original
    vec3 rd = cameraDir(ro, ta, st);
    
    vec3 corner0 = vec3(0.0);
    vec3 corner1 = vec3(BOUNDING_BOX_SIZE);
    float tmin = 0.0;
    float tmax = 1e6;
    
   
    //vec3 rd = gl_TexCoord[0].xyz - ro;// ray dir
    
    if (IntersectBox(ro, rd, corner0, corner1, tmin, tmax)) {
        //vec4 res = raymarch(ro, rd, tmin, tmax);
        //vec4 position = r0 + tmin * rd;
        //gl_FragColor = res;
        //gl_FragColor = vec4(vec3(gl_TexCoord[0].xyz), 1.0);
        vec3 tex = gl_TexCoord[0].xyz;
        tex -= vec3(1.0/256.0, 1.0/256.0, 1.0/256.0);
        gl_FragColor = texture3D(volume_tex, tex+vec3(u_time, 0.0, 0.0));
        //gl_FragColor = vec4(gl_FragCoord.xy, 1.0, 1.0);
    }else{
        gl_FragColor = vec4(1.0, 1.0, 1.0, 0.4);
    }
    gl_FragColor = vec4(st, 0.0, 1.0);
    
//    vec3 tex = gl_TexCoord[0].xyz;
//    tex += vec3(1.0/255.0, 1.0/255.0, 1.0/255.0);
//    //  tex = vec3(min(tex.x, 1.0), min(tex.y, 1.0), min(tex.z, 1.0));
//    vec4 col = texture3D(volume_tex, tex);
//    gl_FragColor = col;
    
    
}
