//
//  brickTexture.h
//  openGL_00
//
//  Created by João Fonseca on 21/06/15.
//
//

#pragma once
#include "Scene.h"
#include "ofMain.h"
#include "ofxGui.h"

class brickTexture : public Scene {
    
    
public:
    
    brickTexture();
    void setup();
    void update();
    void draw();
    
    void reloadShader();
    
    ofMatrix4x4 calculateNormalMatrix();
    ofMatrix3x3 mat4ToMat3(ofMatrix4x4 mat4);

    ofShader shader;
        
    ofParameter<ofVec3f> lightPos;
    ofParameter<ofVec2f> BrickSize;
    ofParameter<ofVec2f> BrickPct;
    ofParameter<ofColor> BrickColor;
    ofParameter<ofColor> MotarColor;
    
    ofxPanel gui;
    
};