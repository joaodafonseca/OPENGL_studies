#version 150

in vec3       DiffuseColor;
out vec4      FragColor;

void main() {
    
    FragColor = vec4(DiffuseColor, 1.0);
}
