//
//  multipleTexture.cpp
//  openGL_00
//
//  Created by João Fonseca on 22/06/15.
//
//

#include "multipleTexture.h"




//--------------------------------------------------------------
multipleTexture::multipleTexture(){
    
    shader.load("shaders/multipleTexture");
    texture[0].load("textures/earthDay.jpg");
    texture[1].load("textures/earthNight.jpg");
    texture[2].load("textures/earthGloss.jpg");
    
    texture[3].load("textures/moonmapTex.jpg");
    
    sphere.set(100,80);
    sphere.enableNormals();
    sphere.mapTexCoordsFromTexture(texture[0].getTexture());
    moon.mapTexCoordsFromTexture(texture[3].getTexture());
    
    moon.set(20,20);
    moon.setPosition(-150, 0, 0);
    
    cam.setDistance(250);
    
    gui.setup("multipleTexture","gui/multipleTextureSettings.xml");
    gui.add(lightPos.set("lightPosition", ofVec3f(0,0,0), ofVec3f(-800,-800,-800), ofVec3f(800,800,800)));
    gui.loadFromFile("gui/multipleTextureSettings.xml");
    
    
    for(int i = 0; i < 100; i++){
    
        stars.push_back(ofPoint(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()),0));
    
    }
    
}

//--------------------------------------------------------------
void multipleTexture::setup(){
    
}

//--------------------------------------------------------------
void multipleTexture::update(){
    sphere.pan(-0.1);

    moon.rotateAround(1, ofVec3f(0,1,0), sphere.getPosition() );
}

//--------------------------------------------------------------
void multipleTexture::draw(){
    
    ofBackground(0);
    
    for(int i = 0; i < 100; i++){
        ofSetColor(ofRandom(200,255));
        ofDrawEllipse(stars[i].x, stars[i].y, ofRandom(2,4), ofRandom(2,4));
        
    }
    
    ofEnableDepthTest();

    cam.begin();
    //texture.getTexture().bind();
    shader.begin();
    shader.setUniformMatrix3f("normalMatrix", mat4ToMat3(ofGetCurrentNormalMatrix()));
    shader.setUniformTexture("EarthDay", texture[0].getTexture(), 0);
    shader.setUniformTexture("EarthNight", texture[1].getTexture(), 1);
    shader.setUniformTexture("EarthGloss", texture[2].getTexture(), 2);
    shader.setUniform3f("LightPosition",lightPos->x,lightPos->y,lightPos->z);

    //cout<<ofGetCurrentNormalMatrix()<<endl;
    sphere.draw();
    
    shader.setUniformTexture("EarthDay", texture[3].getTexture(), 0);
   
    shader.setUniformTexture("EarthNight", *new ofTexture(), 1);
    shader.setUniformTexture("EarthGloss", *new ofTexture(), 2);
    moon.draw();
    shader.end();
    //texture.getTexture().unbind();
   
    cam.end();
    
    ofDisableDepthTest();
    gui.draw();
 
}

//--------------------------------------------------------------
void multipleTexture::reloadShader(){
    
    shader.load("shaders/multipleTexture");
    
}

ofMatrix3x3 multipleTexture::mat4ToMat3(ofMatrix4x4 mat4)
{
    return ofMatrix3x3(mat4._mat[0][0], mat4._mat[0][1], mat4._mat[0][2], mat4._mat[1][0], mat4._mat[1][1], mat4._mat[1][2], mat4._mat[2][0], mat4._mat[2][1], mat4._mat[2][2]);
}

