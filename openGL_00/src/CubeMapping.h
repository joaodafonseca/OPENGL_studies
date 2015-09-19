//
//  CubeMapping.h
//  openGL_00
//
//  Created by João Fonseca on 21/06/15.
//
//

#pragma once

#include "Scene.h"
#include "ofMain.h"
#include "ofxGui.h"

class CubeMapping : public Scene {
    
    
public:
    
    CubeMapping();
    void setup();
    void update();
    void draw();
    
    void reloadShader();
    ofMatrix3x3 mat4ToMat3(ofMatrix4x4 mat4);
    
    string title;
    
    ofShader shader;
    ofBoxPrimitive cube;
    ofEasyCam cam;
    
    ofImage texture[6];
    
    ofParameter<ofVec3f> lightPos;
    ofParameter<ofVec3f> baseColor;
    ofParameter<float> mixRatio;
    
    ofxPanel gui;
    
    int size;
     unsigned int textureObjectID;
    vector<ofVec3f> cubemapVertices;
    vector<ofVec3f> cubemapTexCoords;
  
};