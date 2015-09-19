#version 150

// these are from the programmable pipeline system
uniform mat4 projectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 modelViewProjectionMatrix;


in vec4 position;
in vec2 texcoord;

void main(){
    
    gl_Position=projectionMatrix * modelViewMatrix * position;
}