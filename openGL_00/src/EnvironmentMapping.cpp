//
//  EnvironmentMapping.cpp
//  openGL_00
//
//  Created by João Fonseca on 26/06/15.
//
//

#include "EnvironmentMapping.h"


//--------------------------------------------------------------
EnvironmentMapping::EnvironmentMapping(){
    
    title = "EnvironmentMapping";
    ofDisableArbTex();
    
    shader.load("shaders/"+title);
    texture[0].load("textures/equirectangular_texture_1.png");
   
    
    sphere.set(100,80);
    sphere.enableNormals();
    
    //now we load our model
    model.loadModel("models/suzanne.obj",true);
    model.enableNormals();
    
    //model.setPosition(ofGetWidth()*.5, ofGetHeight() * 0.75, 0);
    
    cam.setDistance(250);
    
    
    gui.setup(title,"gui/"+title+".xml");
    gui.add(lightPos.set("lightPosition", ofVec3f(0,0,0), ofVec3f(-800,-800,-800), ofVec3f(800,800,800)));
    gui.add(baseColor.set("baseColor", ofVec3f(10,90,0), ofVec3f(0,0,0), ofVec3f(255,255,255)));
    gui.add(mixRatio.set("mixRatio", 0.5,0.0,1.0));

    gui.loadFromFile("gui/"+title+".xml");
    
    
//    glEnable(GL_DEPTH_TEST);
//    glShadeModel(GL_SMOOTH);

//    glGenVertexArrays(1,&vertex_array_object);
  //  glBindVertexArray(vertex_array_object);
    
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    
}

//--------------------------------------------------------------
void EnvironmentMapping::setup(){
    
}

//--------------------------------------------------------------
void EnvironmentMapping::update(){
    //sphere.pan(-0.1);
    
}

//--------------------------------------------------------------
void EnvironmentMapping::draw(){
    ofBackgroundGradient(ofColor(50), ofColor(255));
    
    ofEnableDepthTest();
 
    cam.begin();
    //texture[0].getTexture().bind();
    shader.begin();
    shader.setUniformMatrix3f("normalMatrix", mat4ToMat3(ofGetCurrentNormalMatrix()));
    shader.setUniformTexture("EnvMap", texture[0].getTexture(), 0);
    shader.setUniform3f("BaseColor",baseColor->x/255,baseColor->y/255,baseColor->z/255);
    shader.setUniform1f("MixRatio", mixRatio);

    shader.setUniform3f("LightPosition",lightPos->x,lightPos->y,lightPos->z);
    
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
void EnvironmentMapping::reloadShader(){
    
    shader.load("shaders/"+title);
    
}

ofMatrix3x3 EnvironmentMapping::mat4ToMat3(ofMatrix4x4 mat4)
{
    return ofMatrix3x3(mat4._mat[0][0], mat4._mat[0][1], mat4._mat[0][2], mat4._mat[1][0], mat4._mat[1][1], mat4._mat[1][2], mat4._mat[2][0], mat4._mat[2][1], mat4._mat[2][2]);
}

