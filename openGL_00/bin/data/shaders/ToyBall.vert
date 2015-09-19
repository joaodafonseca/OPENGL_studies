#version 150

in vec4 position;
in vec4 normal;
in vec2 texcoord;

const vec4 MCBallCenter = vec4(0.0, 0.0, 0.0, 1.0);

uniform mat4 modelViewMatrix;
uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;

out vec3 OCPosition;
out vec4 ECPosition;
flat out vec4 ECBallCenter;

void main() {

    OCPosition = position.xyz;
    ECPosition = modelViewMatrix * position;
    ECBallCenter = modelViewMatrix * MCBallCenter;
    
    gl_Position = modelViewProjectionMatrix * position;
    
}