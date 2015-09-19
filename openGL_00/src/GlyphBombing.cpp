//
//  GlyphBombing.cpp
//  openGL_00
//
//  Created by João Fonseca on 26/06/15.
//
//

#include "GlyphBombing.h"


//--------------------------------------------------------------
GlyphBombing::GlyphBombing(){
    
    title = "GlyphBombing";
    ofDisableArbTex();
    
    shader.load("shaders/"+title);
    texture[0].load("textures/glyphTexture.jpg");
    texture[1].load("textures/randomTexture.png");
    
    
    cube.set(100, 100, 100);
    cube.enableNormals();
    
    //now we load our model
    model.loadModel("models/suzanne.obj",true);
    model.enableNormals();
    
    //model.setPosition(ofGetWidth()*.5, ofGetHeight() * 0.75, 0);
    //cube.mapTexCoordsFromTexture(texture[0].getTexture());
    cam.setDistance(250);
    
    
    gui.setup(title,"gui/"+title+".xml");
    gui.add(specularContribution.set("specularContribution", 0.2,0.0,1.0));
    gui.add(lightPos.set("lightPosition", ofVec3f(0,0,0), ofVec3f(-800,-800,-800), ofVec3f(800,800,800)));
    gui.add(scaleFactor.set("scaleFactor", 10,0.0,20.0));
    gui.add(modelColor.set("modelColor", ofColor(255,0,0,255), ofColor(0,0,0,0), ofColor(255,255,255,255)));
    gui.add(colAjust.set("colAjust", 0.75,0.0,1.0));
    gui.add(percentage.set("percentage", 1.0,0.0,1.0));
    gui.add(samplePerCell.set("samplePerCell", 1.0,0.0,10.0));
    gui.add(R01.set("R01", 0.29,0.0,1.0));
    gui.add(randomScale.set("randomScale",false));
    gui.add(randomRotate.set("randomRotate",false));
    
    gui.loadFromFile("gui/"+title+".xml");
    
    
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    
}

//--------------------------------------------------------------
void GlyphBombing::setup(){
    
}

//--------------------------------------------------------------
void GlyphBombing::update(){
    //sphere.pan(-0.1);
    
}

//--------------------------------------------------------------
void GlyphBombing::draw(){
    ofBackgroundGradient(ofColor(50), ofColor(255));
    
    ofEnableDepthTest();
    
    cam.begin();
    //texture[0].getTexture().bind();
    shader.begin();
  
    shader.setUniformMatrix3f("normalMatrix", mat4ToMat3(ofGetCurrentNormalMatrix()));
    shader.setUniformTexture("GlyphTex", texture[0].getTexture(), 0);
    shader.setUniformTexture("RandomTex", texture[1].getTexture(), 1);
    
    shader.setUniform1f("SpecularContribution", specularContribution);
    shader.setUniform3f("LightPosition",lightPos->x,lightPos->y,lightPos->z);
    //shader.setUniform4f("BaseColor",baseColor->r/255.0f,baseColor->g/255.0f,baseColor->b/255.0f,baseColor->a/255.0f);
    shader.setUniform1f("ScaleFactor", scaleFactor);
    shader.setUniform4f("ModelColor",modelColor->r/255.0f,modelColor->g/255.0f,modelColor->b/255.0f,modelColor->a/255.0f);
    shader.setUniform1f("ColAdjust", colAjust);
    shader.setUniform1f("Percentage", percentage);
    shader.setUniform1f("SamplesPerCell", samplePerCell);
    shader.setUniform1f("RO1", R01);
    
    shader.setUniform1i("RandomScale", randomScale);
    shader.setUniform1i("RandomRotate", randomRotate);
    
    
    //cout<<ofGetCurrentNormalMatrix()<<endl;
    //model.drawFaces();
    cube.draw();
    shader.end();
    //texture[0].getTexture().unbind();
    cam.end();
    
    ofDisableDepthTest();
    gui.draw();
    
    }

//--------------------------------------------------------------
void GlyphBombing::reloadShader(){
    
    shader.load("shaders/"+title);
    
}

ofMatrix3x3 GlyphBombing::mat4ToMat3(ofMatrix4x4 mat4)
{
    return ofMatrix3x3(mat4._mat[0][0], mat4._mat[0][1], mat4._mat[0][2], mat4._mat[1][0], mat4._mat[1][1], mat4._mat[1][2], mat4._mat[2][0], mat4._mat[2][1], mat4._mat[2][2]);
}

