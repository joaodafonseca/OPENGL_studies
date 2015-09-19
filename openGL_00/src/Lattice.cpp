//
//  Lattice.cpp
//  openGL_00
//
//  Created by João Fonseca on 28/06/15.
//
//

#include "Lattice.h"

//--------------------------------------------------------------
Lattice::Lattice(){
    
    title = "Lattice";
    ofDisableArbTex();
    
    shader.load("shaders/"+title);
        
    
    cylinder.set(50, 50, 50, 50);
    cylinder.enableNormals();
    
    //now we load our model
    model.loadModel("models/suzanne.obj",true);
    model.enableNormals();
    
    //model.setPosition(ofGetWidth()*.5, ofGetHeight() * 0.75, 0);
    //cube.mapTexCoordsFromTexture(texture[0].getTexture());
    cam.setDistance(250);
    
    
    gui.setup(title,"gui/"+title+".xml");
    
    gui.add(LightPosition.set("LightPosition", ofVec3f(0,0,0), ofVec3f(-800,-800,-800), ofVec3f(800,800,800)));
    gui.add(LightColor.set("LightColor", ofColor(20,0,0,255), ofColor(0,0,0,0), ofColor(255,255,255,255)));
    gui.add(Specular.set("Specular", ofColor(20,0,0,255), ofColor(0,0,0,0), ofColor(255,255,255,255)));
    gui.add(Ambient.set("Ambient", ofColor(0.2,0,0,1), ofColor(0,0,0,0), ofColor(255,255,255,255)));
    gui.add(Kd.set("Kd", 10,0.0,20.0));
    gui.add(SurfaceColor.set("SurfaceColor", ofColor(90,0,0,255), ofColor(0,0,0,0), ofColor(255,255,255,255)));
  
    gui.add(Threshold.set("Threshold", ofVec2f(0,0),ofVec2f(0,0),ofVec2f(1,1)));
    gui.add(Scale.set("Scale", ofVec2f(0,0),ofVec2f(0,0),ofVec2f(1,1)));

    
    
    gui.loadFromFile("gui/"+title+".xml");
    
    
    ofParameter<ofColor> SurfaceColor;
    ofParameter<float> Threshold;
    ofParameter<float> Scale;
    
   
    
}

//--------------------------------------------------------------
void Lattice::setup(){
    
}

//--------------------------------------------------------------
void Lattice::update(){
    //cylinder.pan(-0.1);
    
}

//--------------------------------------------------------------
void Lattice::draw(){
    ofBackgroundGradient(ofColor(50), ofColor(255));
    
    ofEnableDepthTest();
    
    cam.begin();
    //texture[0].getTexture().bind();
    shader.begin();
    
    shader.setUniformMatrix3f("normalMatrix", mat4ToMat3(ofGetCurrentNormalMatrix()));
    shader.setUniformMatrix3f("EyePosition",mat4ToMat3(cam.getModelViewMatrix()));
    
    
    shader.setUniform3f("LightPosition",LightPosition->x,LightPosition->y,LightPosition->z);
    shader.setUniform3f("LightColor",LightColor->r/255.0f,LightColor->g/255.0f,LightColor->b/255.0f);
    shader.setUniform3f("Specular",Specular->r/255.0f,Specular->g/255.0f,Specular->b/255.0f);
    shader.setUniform3f("Ambient",Ambient->r/255.0f,Ambient->g/255.0f,Ambient->b/255.0f);
    shader.setUniform1f("Kd", Kd);
    shader.setUniform4f("Ambient",Ambient->r/255.0f,Ambient->g/255.0f,Ambient->b/255.0f,Ambient->a/255.0f);
    shader.setUniform3f("SurfaceColor",SurfaceColor->r/255.0f,SurfaceColor->g/255.0f,SurfaceColor->b/255.0f);

    shader.setUniform2f("Threshold", Threshold->x, Threshold->y);
    shader.setUniform2f("Scale", Scale->x, Scale->y);
    
    
    
    //cout<<ofGetCurrentNormalMatrix()<<endl;
    //model.drawFaces();
    cylinder.draw();
    shader.end();
    //texture[0].getTexture().unbind();
    cam.end();
    
    ofDisableDepthTest();
    gui.draw();
    
}

//--------------------------------------------------------------
void Lattice::reloadShader(){
    
    shader.load("shaders/"+title);
    
}

ofMatrix3x3 Lattice::mat4ToMat3(ofMatrix4x4 mat4)
{
    return ofMatrix3x3(mat4._mat[0][0], mat4._mat[0][1], mat4._mat[0][2], mat4._mat[1][0], mat4._mat[1][1], mat4._mat[1][2], mat4._mat[2][0], mat4._mat[2][1], mat4._mat[2][2]);
}


