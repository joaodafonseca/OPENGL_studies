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

out vec3  Normal;
out vec3  EyeDir;
out float LightIntensity;


void main() {

    
    //vec3 ecPosition = vec3(modelViewMatrix * position);
    Normal          = normalize(normalMatrix * normal.xyz).xyz;
    vec4 pos        = modelViewMatrix * position;
    EyeDir          = pos.xyz;
    vec3 lightDir   = normalize(LightPosition -EyeDir);
    LightIntensity  = max(dot(lightDir,Normal),0.0);
    
    gl_Position = modelViewProjectionMatrix * position;
    
}