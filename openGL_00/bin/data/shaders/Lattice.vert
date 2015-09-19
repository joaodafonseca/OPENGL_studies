#version 150

in vec4 position;
in vec4 normal;
in vec2 texcoord;

uniform mat4 modelViewMatrix;
uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;

out vec3  DiffuseColor;
out vec3  SpecularColor;
out vec2 TexCoord;

uniform vec3  LightPosition;
uniform vec3  LightColor;
uniform vec3  EyePosition;
uniform vec3  Specular;
uniform vec3  Ambient;
uniform float Kd;

void main() {
    
    
    vec3  ecPosition = vec3(modelViewMatrix * position);
    vec3  tnorm      = normalize(normalMatrix * normal.xyz);
    vec3  lightVec   = normalize(LightPosition - ecPosition);
    vec3  viewVec    = normalize(EyePosition - ecPosition);
    vec3 hvec        = normalize(viewVec + lightVec);
    

    float spec = clamp(dot(hvec, tnorm), 0.0, 1.0);
    spec = pow(spec, 16.0);
    
    DiffuseColor  = LightColor * vec3(Kd * dot(lightVec, tnorm));
    DiffuseColor  = clamp(Ambient + DiffuseColor, 0.0, 1.0);
    SpecularColor = clamp((LightColor * Specular * spec), 0.0, 1.0);
    
    TexCoord  = texcoord;
    
    gl_Position = modelViewProjectionMatrix * position;
    
    
    
}