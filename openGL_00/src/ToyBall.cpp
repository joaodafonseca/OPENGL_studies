//
//  ToyBall.cpp
//  openGL_00
//
//  Created by João Fonseca on 27/06/15.
//
//

#include "ToyBall.h"




//--------------------------------------------------------------
ToyBall::ToyBall(){
    
    title = "ToyBall";
    ofDisableArbTex();
  
    shader.load("shaders/"+title);
    texture[0].load("textures/glyphTexture.jpg");
    texture[1].load("textures/randomTexture.png");
    
    
    sphere.set(100, 50);
    sphere.enableNormals();
    
    //now we load our model
    model.loadModel("models/suzanne.obj",true);
    model.enableNormals();
    
    //model.setPosition(ofGetWidth()*.5, ofGetHeight() * 0.75, 0);
    //cube.mapTexCoordsFromTexture(texture[0].getTexture());
    cam.setDistance(250);
    
    
    gui.setup(title,"gui/"+title+".xml");
    
    gui.add(StripeWidth.set("StripeWidth", 0.3,0.0,1.0));
    gui.add(InOrOutInit.set("InOrOutInit", -3,-10,10.0));
    gui.add(FWidth.set("FWidth", 0.005,0.0,1.0));
    gui.add(StarColor.set("StarColor", ofColor(90,0,0,255), ofColor(0,0,0,0), ofColor(255,255,255,255)));
    gui.add(StripeColor.set("StripeColor", ofColor(90,0,0,255), ofColor(0,0,0,0), ofColor(255,255,255,255)));
    gui.add(BaseColor.set("BaseColor", ofColor(90,0,0,255), ofColor(0,0,0,0), ofColor(255,255,255,255)));
    gui.add(LightDir.set("LightDir", ofVec4f(0.5), ofVec4f(0), ofVec4f(1)));
    gui.add(HVector.set("HVector", ofVec4f(0.3,0.3,0.5,0), ofVec4f(0), ofVec4f(1)));
    gui.add(SpecularColor.set("SpecularColor", ofColor(90,0,0,255), ofColor(0,0,0,0), ofColor(255,255,255,255)));
    gui.add(SpecularExponent.set("SpecularExponent", 20.0,0.0,500.0));
    gui.add(Ka.set("Ka", 0.3,0.0,1.0));
    gui.add(Kd.set("kd", 0.7,0.0,1.0));
    gui.add(Ks.set("Ks", 0.4,0.0,1.0));
    
    gui.loadFromFile("gui/"+title+".xml");
    
    
    
}

//--------------------------------------------------------------
void ToyBall::setup(){
    
}

//--------------------------------------------------------------
void ToyBall::update(){
    //sphere(-0.1);
    
}

//--------------------------------------------------------------
void ToyBall::draw(){
    ofBackgroundGradient(ofColor(50), ofColor(255));
    
    ofEnableDepthTest();
    
    glDisable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    
    cam.begin();
    //texture[0].getTexture().bind();
    shader.begin();
    
    shader.setUniformMatrix3f("normalMatrix", mat4ToMat3(ofGetCurrentNormalMatrix()));
  
    
       shader.setUniform1f("StripeWidth", StripeWidth);
       shader.setUniform1f("InOrOutInit", InOrOutInit);
       shader.setUniform1f("FWidth", FWidth);
       shader.setUniform4f("StarColor",StarColor->r/255.0f,StarColor->g/255.0f,StarColor->b/255.0f,StarColor->a/255.0f);
       shader.setUniform4f("StripeColor",StripeColor->r/255.0f,StripeColor->g/255.0f,StripeColor->b/255.0f,StripeColor->a/255.0f);
       shader.setUniform4f("BaseColor",BaseColor->r/255.0f,BaseColor->g/255.0f,BaseColor->b/255.0f,BaseColor->a/255.0f);
       shader.setUniform4f("LightDir",LightDir->x, LightDir->y, LightDir->z, LightDir->w);
       shader.setUniform4f("HVector",HVector->x, HVector->y, HVector->z, HVector->w);
       shader.setUniform4f("SpecularColor",SpecularColor->r/255.0f,SpecularColor->g/255.0f,SpecularColor->b/255.0f,SpecularColor->a/255.0f);
       shader.setUniform1f("SpecularExponent", SpecularExponent);
       shader.setUniform1f("Ka", Ka);
       shader.setUniform1f("Kd", Kd);
       shader.setUniform1f("Ks", Ks);
    
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
void ToyBall::reloadShader(){
    
    shader.load("shaders/"+title);
    
}

ofMatrix3x3 ToyBall::mat4ToMat3(ofMatrix4x4 mat4)
{
    return ofMatrix3x3(mat4._mat[0][0], mat4._mat[0][1], mat4._mat[0][2], mat4._mat[1][0], mat4._mat[1][1], mat4._mat[1][2], mat4._mat[2][0], mat4._mat[2][1], mat4._mat[2][2]);
}

