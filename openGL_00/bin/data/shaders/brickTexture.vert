#version 150

in vec4 position;
in vec4 normal;

uniform mat4 modelViewMatrix;
uniform mat4 modelViewProjectionMatrix;
uniform mat3 normalMatrix;

uniform vec3 LightPosition;

const float SpecularContribution = 0.3;
const float DiffuseContribution  = 1.0 - SpecularContribution;

out float    LightIntensity;
out vec2     MCposition;


void main() {
    
    vec3 ecPosition = vec3(modelViewMatrix * position);
    vec3 tnorm      = normalize(-modelViewMatrix * normal).xyz;
    vec3 lightVec   = normalize(LightPosition - ecPosition);
    vec3 reflectVec = reflect(-lightVec, tnorm.xyz);
    vec3 viewVec    = normalize(-ecPosition);
    
    float diffuse = max(dot(lightVec, tnorm.xyz), 0.0);
    
    float spec = 0.0;
    if (diffuse > 0.0)
    {
        spec = max(dot(reflectVec, viewVec), 0.0);
        spec = pow(spec, 16.0);
    }
    
    LightIntensity = DiffuseContribution * diffuse +
    SpecularContribution * spec;
    
    MCposition = position.xy;
    
    gl_Position     = modelViewProjectionMatrix * position;
    
}