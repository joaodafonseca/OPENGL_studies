//
//  ProceduralStripes.h
//  openGL_00
//
//  Created by João Fonseca on 27/06/15.
//
//

#pragma once

#include "Scene.h"
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxAssimpModelLoader.h"

class ProceduralStripes : public Scene {
    
    
public:
    
    ProceduralStripes();
    void setup();
    void update();
    void draw();
    
    void reloadShader();
    
    string title;
    
    ofMatrix3x3 mat4ToMat3(ofMatrix4x4 mat4);
    
    ofShader shader;
    ofCylinderPrimitive cylinder;
    //this is our model we'll draw
    ofxAssimpModelLoader model;
    
    ofEasyCam cam;
    
    ofImage texture[3];
    
    ofParameter<ofVec3f> LightPosition;
    ofParameter<ofColor> LightColor;
    ofParameter<ofColor> Specular;
    ofParameter<ofColor> Ambient;
    ofParameter<float> Kd;
    ofParameter<ofColor> StripeColor;
    ofParameter<ofColor> BackColor;
    ofParameter<float> Width;
    ofParameter<float> Fuzz;
    ofParameter<float> Scale;
    
    
    ofxPanel gui;
    
};