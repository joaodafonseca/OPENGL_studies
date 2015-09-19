#version 150

in vec4      position;
in vec4      normal;
in vec2 texcoord;

uniform mat4 modelViewMatrix;
uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;

uniform vec3 LightPosition;

const float SpecularContribution = 0.3;
const float DiffuseContribution  = 1.0 - SpecularContribution;

out float LightIntensity;
out vec2  TexCoord;


void main() {
    
    
    
    vec3 ecPosition = vec3(modelViewMatrix * position);
    vec3 tnorm      = normalize(normalMatrix * normal.xyz).xyz;
    vec3 lightVec   = normalize(LightPosition - ecPosition);
    vec3 reflectVec = reflect(-lightVec, tnorm);
    vec3 viewVec    = normalize(-ecPosition);
    
    float diffuse = max(dot(lightVec, tnorm.xyz), 0.0);
    
    float spec =  clamp(dot(reflectVec, viewVec), 0.0, 1.0);
    spec =  pow(spec, 16.0);
//    if (diffuse > 0.0)
//    {
//        spec = max(dot(reflectVec, viewVec), 0.0);
//        spec = pow(spec, 16.0);
//    }
    
    LightIntensity = DiffuseContribution * diffuse +
    SpecularContribution * spec;
    
    TexCoord = texcoord.st;
    
    gl_Position     = modelViewProjectionMatrix * position;
    
}