//
//  brickTexture.cpp
//  openGL_00
//
//  Created by João Fonseca on 21/06/15.
//
//

#include "brickTexture.h"



//--------------------------------------------------------------
brickTexture::brickTexture(){
    
    shader.load("shaders/brickTexture");
    
    gui.setup("brickTexture","gui/brickTextureSettings.xml");
    
    
    gui.add(lightPos.set("lightPosition", ofVec3f(0,0,0), ofVec3f(-800,-800,-800), ofVec3f(800,800,800)));
    gui.add(BrickSize.set("BrickSize", ofVec2f(0.5,0.5), ofVec3f(0,0), ofVec3f(1,1)));
    gui.add(BrickPct.set("BrickPct", ofVec2f(0.5,0.5), ofVec3f(0,0), ofVec3f(1,1)));
    gui.add(BrickColor.set("BrickColor", ofColor(255,0,0,255), ofColor(0,0,0,0), ofColor(255,255,255)));
    gui.add(MotarColor.set("MotarColor", ofColor(255,255,255,255),  ofColor(0,0,0,0), ofColor(255,255,255,255)));
 
    gui.loadFromFile("gui/brickTextureSettings.xml");
}

//--------------------------------------------------------------
void brickTexture::setup(){
    
}

//--------------------------------------------------------------
void brickTexture::update(){
    
}

//--------------------------------------------------------------
void brickTexture::draw(){
    
    shader.begin();
    shader.setUniformMatrix3f("normalMatrix", mat4ToMat3(ofGetCurrentNormalMatrix()));
  
    
    shader.setUniform3f("LightPosition",lightPos->x,lightPos->y,lightPos->z);
    shader.setUniform2f("BrickPct",BrickPct->x,BrickPct->y);
    shader.setUniform2f("BrickSize",BrickSize->x,BrickSize->y);
    shader.setUniform3f("BrickColor",BrickColor->r/255.0f,BrickColor->g/255.0f,BrickColor->b/255.0f);
    shader.setUniform3f("MortarColor",MotarColor->r/255.0f,MotarColor->g/255.0f,MotarColor->b/255.0f);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    shader.end();

    gui.draw();

    
}

//--------------------------------------------------------------
void brickTexture::reloadShader(){
    
    shader.load("shaders/brickTexture");
    
}

//--------------------------------------------------------------
ofMatrix3x3 brickTexture::mat4ToMat3(ofMatrix4x4 mat4)
{
    return ofMatrix3x3(mat4._mat[0][0], mat4._mat[0][1], mat4._mat[0][2], mat4._mat[1][0], mat4._mat[1][1], mat4._mat[1][2], mat4._mat[2][0], mat4._mat[2][1], mat4._mat[2][2]);
}