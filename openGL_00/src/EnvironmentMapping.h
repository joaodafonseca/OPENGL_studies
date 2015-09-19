//
//  EnvironmentMapping.h
//  openGL_00
//
//  Created by João Fonseca on 26/06/15.
//
//

#pragma once

#include "Scene.h"
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxAssimpModelLoader.h"

class EnvironmentMapping : public Scene {
    
    
public:
    
    EnvironmentMapping();
    void setup();
    void update();
    void draw();
    
    void reloadShader();
    
    string title;
    
    ofMatrix3x3 mat4ToMat3(ofMatrix4x4 mat4);
    
    ofShader shader;
    ofSpherePrimitive sphere;
    //this is our model we'll draw
    ofxAssimpModelLoader model;
    
    ofEasyCam cam;
    
    ofImage texture[3];
    
    ofParameter<ofVec3f> lightPos;
    ofParameter<ofVec3f> baseColor;
    ofParameter<float> mixRatio;
    
    
    
    ofxPanel gui;
    
};