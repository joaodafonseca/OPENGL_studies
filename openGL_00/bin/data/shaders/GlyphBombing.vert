#version 150

in vec4 position;
in vec4 normal;
in vec2 texcoord;

uniform mat4 modelViewMatrix;
uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;

out vec3  Normal;
out vec2  TexCoord;
out float LightIntensity;

uniform float  SpecularContribution;
uniform vec3   LightPosition;
uniform float  ScaleFactor;


void main() {

    vec3  ecPosition = vec3(modelViewMatrix * position);
    vec3  tnorm      = normalize(normalMatrix * normal.xyz);
    vec3  lightVec   = normalize(LightPosition - ecPosition);
    vec3  reflectVec = reflect(-lightVec, tnorm);
    vec3  viewVec    = normalize(-ecPosition);
    
    
    float diffuse    = max(dot(lightVec, tnorm), 0.0);
    float spec       = 0.0;
    if(diffuse > 0.0)
    {
        spec = max(dot(reflectVec, viewVec), 0.0);
        spec = pow(spec, 16.0);
    }
    float diffusecontribution  = 1.0 - SpecularContribution;
    LightIntensity = diffusecontribution * diffuse * 2.0 +
    SpecularContribution * spec;
    TexCoord = texcoord * ScaleFactor;
    
    
    gl_Position = modelViewProjectionMatrix * position;
    
    
    
}