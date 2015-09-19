//
//  ProceduralStripes.cpp
//  openGL_00
//
//  Created by João Fonseca on 27/06/15.
//
//

#include "ProceduralStripes.h"



//--------------------------------------------------------------
ProceduralStripes::ProceduralStripes(){
    
    title = "ProceduralStripes";
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
    gui.add(StripeColor.set("StripeColor", ofColor(90,0,0,255), ofColor(0,0,0,0), ofColor(255,255,255,255)));
    gui.add(BackColor.set("BackColor", ofColor(67,0,0,255), ofColor(0,0,0,0), ofColor(255,255,255,255)));
    gui.add(Width.set("Width", 0.75,0.0,1.0));
    gui.add(Fuzz.set("Fuzz", 1.0,0.0,1.0));
    gui.add(Scale.set("Scale", 1.0,0.0,10.0));

    
    gui.loadFromFile("gui/"+title+".xml");
    
    
    
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    
}

//--------------------------------------------------------------
void ProceduralStripes::setup(){
    
}

//--------------------------------------------------------------
void ProceduralStripes::update(){
   //cylinder.pan(-0.1);
    
}

//--------------------------------------------------------------
void ProceduralStripes::draw(){
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
    shader.setUniform3f("StripeColor",StripeColor->r/255.0f,StripeColor->g/255.0f,StripeColor->b/255.0f);
    shader.setUniform3f("BackColor",BackColor->r/255.0f,BackColor->g/255.0f,BackColor->b/255.0f);
    shader.setUniform1f("Width", Width);
    shader.setUniform1f("Fuzz", Fuzz);
    shader.setUniform1f("Scale", Scale);

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
void ProceduralStripes::reloadShader(){
    
    shader.load("shaders/"+title);
    
}

ofMatrix3x3 ProceduralStripes::mat4ToMat3(ofMatrix4x4 mat4)
{
    return ofMatrix3x3(mat4._mat[0][0], mat4._mat[0][1], mat4._mat[0][2], mat4._mat[1][0], mat4._mat[1][1], mat4._mat[1][2], mat4._mat[2][0], mat4._mat[2][1], mat4._mat[2][2]);
}

