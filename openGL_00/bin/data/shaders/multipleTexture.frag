#version 150


in float Diffuse;
in vec3  Specular;
in vec2  TexCoord;

uniform sampler2DRect EarthDay;
uniform sampler2DRect EarthNight;
uniform sampler2DRect EarthGloss;

out vec4 FragColor;

void main() {
    
    // Monochrome cloud cover value will be in clouds.r
    // Gloss value will be in clouds.g
    // clouds.b will be unused
    vec2 clouds    = texture(EarthGloss, TexCoord).rg;
    vec3 daytime   = (texture(EarthDay, TexCoord).rgb * Diffuse + Specular * clouds.g) * Diffuse;
    vec3 nighttime = texture(EarthNight, TexCoord).rgb * 2.0;
    
    vec3 color = daytime;
    
    color = mix(nighttime, daytime, (Diffuse + 0.1));
    
    //FragColor = vec4(color, 1.0);
    FragColor = vec4(color, 1.0);
}