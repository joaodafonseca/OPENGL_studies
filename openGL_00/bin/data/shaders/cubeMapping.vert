#version 150

in vec4 position;
in vec4 normal;
in vec2 texcoord;

uniform mat4 modelViewMatrix;
uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;

uniform vec3 LightPosition;

const float SpecularContribution = 0.3;
const float DiffuseContribution  = 1.0 - SpecularContribution;

out float LightIntensity;
out vec3  ReflectDir;


void main() {

    
    //vec3 ecPosition = vec3(modelViewMatrix * position);
    vec3 tnorm      = normalize(normalMatrix * normal.xyz).xyz;
    vec4 pos        = modelViewMatrix * position;
    vec3 eyeDir     = pos.xyz;
    ReflectDir      = reflect(eyeDir, tnorm);
    vec3 lightDir   = normalize(LightPosition -eyeDir);
    LightIntensity  = max(dot(lightDir,tnorm),0.0);
    
    gl_Position = modelViewProjectionMatrix * position;
    
}