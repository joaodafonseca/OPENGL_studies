//
//  GlyphBombing.h
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

class GlyphBombing : public Scene {
    
    
public:
    
    GlyphBombing();
    void setup();
    void update();
    void draw();
    
    void reloadShader();
    
    string title;
    
    ofMatrix3x3 mat4ToMat3(ofMatrix4x4 mat4);
    
    ofShader shader;
    ofBoxPrimitive cube;
    //this is our model we'll draw
    ofxAssimpModelLoader model;
    
    ofEasyCam cam;
    
    ofImage texture[3];
    
    ofParameter<float> specularContribution;
    ofParameter<ofVec3f> lightPos;
    ofParameter<float> scaleFactor;
    ofParameter<ofColor> modelColor;
    ofParameter<float> percentage;
    ofParameter<float> colAjust;
    ofParameter<float> samplePerCell;
    ofParameter<float> R01;
    ofParameter<bool> randomScale;
    ofParameter<bool> randomRotate;
      
    ofxPanel gui;
    
};