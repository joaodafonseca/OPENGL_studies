#version 150


const vec3 Xunitvec = vec3(1.0, 0.0, 0.0);
const vec3 Yunitvec = vec3(0.0, 1.0, 0.0);


in vec3  Normal;
in vec3  EyeDir;
in float LightIntensity;


uniform vec3  BaseColor;
uniform float MixRatio;
uniform sampler2D EnvMap;  // = 4

out vec4 FragColor;

void main() {
   
    // Compute reflection vector
    vec3 reflectDir = reflect(EyeDir, Normal);
    // Compute altitude and azimuth angles
    vec2 index;
    index.t = dot(normalize(reflectDir), Yunitvec);
    reflectDir.y = 0.0;
    index.s = dot(normalize(reflectDir), Xunitvec) * 0.5;
    // Calculate gradiants before discontinuous changes to index
    vec2 dPdx = dFdx( index );
    vec2 dPdy = dFdy( index );
    // Translate index values into proper range
    if (reflectDir.z >= 0.0)
        index = (index + 1.0) * 0.5;
    else {
        index.t = (index.t + 1.0) * 0.5;
        index.s = (-index.s) * 0.5 + 1.0;
    }
    // if reflectDir.z >= 0.0, s will go from 0.25 to 0.75
    // if reflectDir.z <  0.0, s will go from 0.75 to 1.25, and
    // that's OK, because we've set the texture to wrap.
    // Do a lookup into the environment map.
    
    vec3 envColor = vec3(textureGrad(EnvMap, index, dPdx, dPdy));
    
    // Add lighting to base color and mix
    vec3 base = LightIntensity * BaseColor;
    envColor = mix(envColor, base, MixRatio);
    FragColor = vec4(envColor, 1.0);


}