//
//  simpleTexture.cpp
//  openGL_00
//
//  Created by João Fonseca on 21/06/15.
//
//

#include "simpleTexture.h"



//--------------------------------------------------------------
simpleTexture::simpleTexture(){
    
    shader.load("shaders/simpleTexture");
    texture.load("textures/earth.png");

    sphere.set(100,80);
     sphere.mapTexCoordsFromTexture(texture.getTexture());

    cam.setDistance(250);
    
    
    gui.setup("simpleTexture","gui/simpleTextureSettings.xml");
    gui.add(lightPos.set("lightPosition", ofVec3f(0,0,0), ofVec3f(-800,-800,-800), ofVec3f(800,800,800)));
    gui.loadFromFile("gui/simpleTextureSettings.xml");
    
}

//--------------------------------------------------------------
void simpleTexture::setup(){
    
}

//--------------------------------------------------------------
void simpleTexture::update(){
    
}

//--------------------------------------------------------------
void simpleTexture::draw(){
    
    ofBackgroundGradient(ofColor(50), ofColor(255));
    ofEnableDepthTest();
    
    cam.begin();
    //texture.getTexture().bind();
    shader.begin();
    shader.setUniformMatrix3f("normalMatrix", mat4ToMat3(ofGetCurrentNormalMatrix()));
    shader.setUniform3f("LightPosition",lightPos->x,lightPos->y,lightPos->z);
    shader.setUniformTexture("EarthTexture", texture.getTexture(), 0);
    sphere.draw();
    shader.end();
    //texture.getTexture().unbind();
    cam.end();
    
    ofDisableDepthTest();
    gui.draw();
    

}

//--------------------------------------------------------------
void simpleTexture::reloadShader(){
    
    shader.load("shaders/simpleTexture");
    
}

ofMatrix3x3 simpleTexture::mat4ToMat3(ofMatrix4x4 mat4)
{
    return ofMatrix3x3(mat4._mat[0][0], mat4._mat[0][1], mat4._mat[0][2], mat4._mat[1][0], mat4._mat[1][1], mat4._mat[1][2], mat4._mat[2][0], mat4._mat[2][1], mat4._mat[2][2]);
}

