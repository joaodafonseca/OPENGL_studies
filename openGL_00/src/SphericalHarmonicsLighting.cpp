//
//  ImageBasedLighting.cpp
//  openGL_00
//
//  Created by João Fonseca on 28/06/15.
//
//

#include "SphericalHarmonicsLighting.h"


//--------------------------------------------------------------
SphericalHarmonicsLighting::SphericalHarmonicsLighting(){
    
    title = "SphericalHarmonicsLighting";
    ofDisableArbTex();
    
    shader.load("shaders/"+title);
    
    
    sphere.set(100, 5);
    sphere.enableNormals();
    
    //now we load our model
    model.loadModel("models/suzanne.obj",true);
    model.enableNormals();
    
    //model.setPosition(ofGetWidth()*.5, ofGetHeight() * 0.75, 0);
    //cube.mapTexCoordsFromTexture(texture[0].getTexture());
    cam.setDistance(250);
    
    
    gui.setup(title,"gui/"+title+".xml");
    
    gui.add(ScaleFactor.set("ScaleFactor", 0.5, 0.0, 1.0));
    
    gui.loadFromFile("gui/"+title+".xml");
    
    
    ofParameter<ofColor> SurfaceColor;
    ofParameter<float> Threshold;
    ofParameter<float> Scale;
    
    
    
}

//--------------------------------------------------------------
void SphericalHarmonicsLighting::setup(){
    
}

//--------------------------------------------------------------
void SphericalHarmonicsLighting::update(){
    sphere.rotate(1, ofVec3f(1,1,1));
    
}

//--------------------------------------------------------------
void SphericalHarmonicsLighting::draw(){
    ofBackgroundGradient(ofColor(50), ofColor(255));
    
    ofEnableDepthTest();
    
    cam.begin();
    //texture[0].getTexture().bind();
    shader.begin();
    
    shader.setUniformMatrix3f("normalMatrix", mat4ToMat3(ofGetCurrentNormalMatrix()));
    shader.setUniformMatrix3f("EyePosition",mat4ToMat3(cam.getModelViewMatrix()));

    
    shader.setUniform1f("ScaleFactor",ScaleFactor);
    

    sphere.draw();
   // model.drawFaces();
    
    shader.end();
    //texture[0].getTexture().unbind();
    cam.end();
    
    ofDisableDepthTest();
    gui.draw();
    
}

//--------------------------------------------------------------
void SphericalHarmonicsLighting::reloadShader(){
    
    shader.load("shaders/"+title);
    
}

ofMatrix3x3 SphericalHarmonicsLighting::mat4ToMat3(ofMatrix4x4 mat4)
{
    return ofMatrix3x3(mat4._mat[0][0], mat4._mat[0][1], mat4._mat[0][2], mat4._mat[1][0], mat4._mat[1][1], mat4._mat[1][2], mat4._mat[2][0], mat4._mat[2][1], mat4._mat[2][2]);
}


