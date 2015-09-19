//
//  ToyBall.h
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

class ToyBall : public Scene {
    
    
public:
    
    ToyBall();
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
    
    ofParameter<float> StripeWidth;
    ofParameter<float> InOrOutInit;
    ofParameter<float> FWidth;
    ofParameter<ofColor> StarColor;
    ofParameter<ofColor> StripeColor;
    ofParameter<ofColor> BaseColor;
    ofParameter<ofVec4f> LightDir;
    ofParameter<ofVec4f> HVector;
    ofParameter<ofColor> SpecularColor;
    ofParameter<float> SpecularExponent;
    ofParameter<float> Ka;
    ofParameter<float> Kd;
    ofParameter<float> Ks;
    
    
    
    ofxPanel gui;
    
};