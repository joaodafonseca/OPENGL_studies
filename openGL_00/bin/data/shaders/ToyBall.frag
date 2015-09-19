#version 150



uniform float StripeWidth;
uniform float InOrOutInit;  // -3.0
uniform float FWidth;       // = 0.005
uniform vec4  StarColor;
uniform vec4  StripeColor;
uniform vec4  BaseColor;
uniform vec4  LightDir;     // light direction, should be normalized
uniform vec4  HVector;      // reflection vector for infinite light
uniform vec4  SpecularColor;
uniform float SpecularExponent;
uniform float Ka;
uniform float Kd;
uniform float Ks;

in vec4  ECPosition;   // surface position in eye coordinates
in vec3  OCPosition;   // surface position in object coordinates
flat in vec4  ECBallCenter; // ball center in eye coordinates
out vec4 FragColor;

//uniform vec4  HalfSpace[5]; // half-spaces used to define star pattern
const vec4 HalfSpace_0 = vec4(1.0, 0.0, 0.0, 0.2);
const vec4 HalfSpace_1 = vec4(0.309016994, 0.951056516, 0.0, 0.2);
const vec4 HalfSpace_2 = vec4(-0.809016994, 0.587785252, 0.0, 0.2);
const vec4 HalfSpace_3 = vec4(-0.809016994, -0.587785252, 0.0, 0.2);
const vec4 HalfSpace_4 = vec4(0.309016994, -0.951056516, 0.0, 0.2);



void main() {
    
    vec3  normal;           // Analytically computed normal
    vec4  pShade;           // Point in shader space
    vec4  surfColor;        // Computed color of the surface
    float intensity;        // Computed light intensity
    vec4  distance;         // Computed distance values
    float inorout;          // Counter for classifying star pattern
    
    
    pShade.xyz  = normalize(OCPosition.xyz);
    pShade.w    = 1.0;
    inorout     = InOrOutInit;     // initialize inorout to -3.0
    
    distance[0] = dot(pShade, HalfSpace_0);
    distance[1] = dot(pShade, HalfSpace_1);
    distance[2] = dot(pShade, HalfSpace_2);
    distance[3] = dot(pShade, HalfSpace_3);
    
    
    //float FWidth = fwidth(pShade);
    distance    = smoothstep(-FWidth, FWidth, distance);
    inorout     += dot(distance, vec4(1.0));
    distance.x  = dot(pShade, HalfSpace_4);
    distance.y  = StripeWidth - abs(pShade.z);
    distance.xy = smoothstep(-FWidth, FWidth, distance.xy);
    inorout     += distance.x;
    inorout     = clamp(inorout, 0.0, 1.0);
    surfColor   = mix(BaseColor, StarColor, inorout);
    surfColor   = mix(surfColor, StripeColor, distance.y);
    // Calculate analytic normal of a sphere
    normal      = normalize(ECPosition.xyz-ECBallCenter.xyz);
    
    
    // Per-fragment diffuse lighting
    intensity  = Ka; // ambient
    intensity += Kd * clamp(dot(LightDir.xyz, normal), 0.0, 1.0);
    surfColor *= intensity;
    // Per-fragment specular lighting
    intensity  = clamp(dot(HVector.xyz, normal), 0.0, 1.0);
    intensity  = Ks * pow(intensity, SpecularExponent);
    surfColor.rgb += SpecularColor.rgb * intensity;
    FragColor = surfColor;

 
 
}