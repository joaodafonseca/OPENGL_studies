//
//  ImageBasedLighting.cpp
//  openGL_00
//
//  Created by João Fonseca on 28/06/15.
//
//

#include "ImageBasedLighting.h"


//--------------------------------------------------------------
ImageBasedLighting::ImageBasedLighting(){
    
    title = "ImageBasedLighting";
    ofDisableArbTex();
    
    shader.load("shaders/"+title);
    
    
    sphere.set(100, 50);
    sphere.enableNormals();
    
    //now we load our model
    model.loadModel("models/suzanne.obj",true);
    model.enableNormals();
    
    //model.setPosition(ofGetWidth()*.5, ofGetHeight() * 0.75, 0);
    //cube.mapTexCoordsFromTexture(texture[0].getTexture());
    cam.setDistance(250);
    
    
    gui.setup(title,"gui/"+title+".xml");
    
    gui.add(LightPosition.set("LightPosition", ofVec3f(0,0,0), ofVec3f(-800,-800,-800), ofVec3f(800,800,800)));
    gui.add(SkyColor.set("SkyColor", ofColor(20,0,0,255), ofColor(0,0,0,0), ofColor(255,255,255,255)));
    gui.add(GroundColor.set("GroundColor", ofColor(20,0,0,255), ofColor(0,0,0,0), ofColor(255,255,255,255)));
    
    gui.loadFromFile("gui/"+title+".xml");
    
    
    ofParameter<ofColor> SurfaceColor;
    ofParameter<float> Threshold;
    ofParameter<float> Scale;
    
    
    
}

//--------------------------------------------------------------
void ImageBasedLighting::setup(){
    
}

//--------------------------------------------------------------
void ImageBasedLighting::update(){
    //cylinder.pan(-0.1);
    
}

//--------------------------------------------------------------
void ImageBasedLighting::draw(){
    ofBackgroundGradient(ofColor(50), ofColor(255));
    
    ofEnableDepthTest();
    
    cam.begin();
    //texture[0].getTexture().bind();
    shader.begin();
    
    shader.setUniformMatrix3f("normalMatrix", mat4ToMat3(ofGetCurrentNormalMatrix()));
    shader.setUniformMatrix3f("EyePosition",mat4ToMat3(cam.getModelViewMatrix()));
    
    
    shader.setUniform3f("LightPosition",LightPosition->x,LightPosition->y,LightPosition->z);
    shader.setUniform3f("SkyColor",SkyColor->r/255.0f,SkyColor->g/255.0f,SkyColor->b/255.0f);
    shader.setUniform3f("GroundColor",GroundColor->r/255.0f,GroundColor->g/255.0f,GroundColor->b/255.0f);
    
    //cout<<ofGetCurrentNormalMatrix()<<endl;
    //model.drawFaces();
    sphere.draw();
    shader.end();
    //texture[0].getTexture().unbind();
    cam.end();
    
    ofDisableDepthTest();
    gui.draw();
    
}

//--------------------------------------------------------------
void ImageBasedLighting::reloadShader(){
    
    shader.load("shaders/"+title);
    
}

ofMatrix3x3 ImageBasedLighting::mat4ToMat3(ofMatrix4x4 mat4)
{
    return ofMatrix3x3(mat4._mat[0][0], mat4._mat[0][1], mat4._mat[0][2], mat4._mat[1][0], mat4._mat[1][1], mat4._mat[1][2], mat4._mat[2][0], mat4._mat[2][1], mat4._mat[2][2]);
}


