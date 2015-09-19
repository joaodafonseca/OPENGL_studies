#version 150

in vec4 position;
in vec4 normal;
in vec2 texcoord;

uniform mat4 modelViewMatrix;
uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;

out vec3  ReflectDir;
out vec3  Normal;

void main() {
    
    Normal = normalize(normalMatrix * normal.xyz);
    vec4 pos = modelViewMatrix * position;
    vec3 eyeDir = pos.xyz;
    ReflectDir = reflect(eyeDir, Normal);
    
    gl_Position = modelViewProjectionMatrix * position;
    
}