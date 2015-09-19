#version 150

in float LightIntensity;
in vec2  TexCoord;

out vec4 FragColor;
uniform sampler2DRect EarthTexture;

void main() {
    vec3 lightColor = vec3(texture(EarthTexture, TexCoord));
    FragColor    = vec4(lightColor * LightIntensity, 1.0);
    
}