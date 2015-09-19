#version 150

in vec4 position;
in vec4 normal;
in vec2 texcoord;

uniform mat4 modelViewMatrix;
uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;

uniform vec3 LightPosition;
uniform vec3 SkyColor;
uniform vec3 GroundColor;

out vec3 Color;

void main() {
    
    vec3 ecPosition = vec3(modelViewMatrix * normal);
    vec3 tnorm = normalize(normalMatrix * normal.xyz);
    vec3 lightVec = normalize(LightPosition - ecPosition);
    
    float costheta = dot(tnorm, lightVec);
    float a = costheta * 0.5 + 0.5;
    
    Color = mix(GroundColor, SkyColor, a);
    
    gl_Position = modelViewProjectionMatrix * position;
    
}