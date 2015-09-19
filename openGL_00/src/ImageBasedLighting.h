//
//  ImageBasedLighting.h
//  openGL_00
//
//  Created by João Fonseca on 28/06/15.
//
//

#pragma once 

#include "Scene.h"
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxAssimpModelLoader.h"

class ImageBasedLighting : public Scene {
    
    
public:
    
    ImageBasedLighting();
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
    
    ofParameter<ofVec3f> LightPosition;
    ofParameter<ofColor> SkyColor;
    ofParameter<ofColor> GroundColor;
    
    ofxPanel gui;
    
};