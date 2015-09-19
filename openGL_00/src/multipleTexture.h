//
//  simpleTexture.h
//  openGL_00
//
//  Created by João Fonseca on 21/06/15.
//
//

#pragma once

#include "Scene.h"
#include "ofMain.h"
#include "ofxGui.h"

class multipleTexture : public Scene {
    
    
public:
    
    multipleTexture();
    void setup();
    void update();
    void draw();
    
    void reloadShader();
    ofMatrix3x3 mat4ToMat3(ofMatrix4x4 mat4);
    
    ofShader shader;
    ofSpherePrimitive sphere;
    ofSpherePrimitive moon;
    ofEasyCam cam;
    
    ofImage texture[4];
    
    ofParameter<ofVec3f> lightPos;
    
    
    vector<ofPoint>stars;
    
    ofxPanel gui;
    
};