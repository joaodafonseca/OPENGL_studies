//
//  CubeMapping.cpp
//  openGL_00
//
//  Created by João Fonseca on 26/06/15.
//
//

#include "CubeMapping.h"



//--------------------------------------------------------------
CubeMapping::CubeMapping(){
    
    title="CubeMapping";
    
    shader.load("shaders/"+title);
    texture[0].load("textures/cubeMap/right.png");
    texture[1].load("textures/cubeMap/top.png");
    texture[2].load("textures/cubeMap/back.png");
    texture[3].load("textures/cubeMap/left.png");
    texture[4].load("textures/cubeMap/bottom.png");
    texture[5].load("textures/cubeMap/front.png");
    
    cube.set(100, 100, 100);
    cube.enableNormals();
    //sphere.mapTexCoordsFromTexture(texture[0].getTexture());
    
    cam.setDistance(250);
    
    
    gui.setup(title,"gui/"+title+".xml");
    gui.add(lightPos.set("lightPosition", ofVec3f(0,0,0), ofVec3f(-800,-800,-800), ofVec3f(800,800,800)));
    gui.add(baseColor.set("baseColor", ofVec3f(10,90,0), ofVec3f(0,0,0), ofVec3f(255,255,255)));
    gui.add(mixRatio.set("mixRatio", 0.5,0.0,1.0));
    gui.loadFromFile("gui/"+title+".xml");
    
   
    textureObjectID=1;
 
    //_ofEnable( GL_TEXTURE_CUBE_MAP_SEAMLESS );
    
    //create a texture object
  
    glGenTextures(1, &textureObjectID);
    glBindTexture(GL_TEXTURE_CUBE_MAP, textureObjectID);
    
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
#ifndef TARGET_OPENGLES
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE); // GL_TEXTURE_WRAP_R is not in the ES2 header, hmm..
#endif
    
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    
    
    unsigned char * data_px, * data_nx, * data_py, * data_ny, * data_pz, * data_nz;
    
    size = texture[0].getWidth();
    
    //cout << "ofxCubeMap::loadFromOfImages, size: " << size << "  bpp: " << pos_x.bpp << endl;
    
    //	data_px = new unsigned char [size * size * 3];
    //	data_py = new unsigned char [size * size * 3];
    //	data_pz = new unsigned char [size * size * 3];
    
    //	data_nx = new unsigned char [size * size * 3];
    //	data_ny = new unsigned char [size * size * 3];
    //	data_nz = new unsigned char [size * size * 3];
    
    data_px =  texture[0].getPixels();
    data_py =  texture[1].getPixels();
    data_pz =  texture[2].getPixels();
    
    data_nx =  texture[3].getPixels();
    data_ny =  texture[4].getPixels();
    data_nz =  texture[5].getPixels();

    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGB, size, size, 0, GL_RGB, GL_UNSIGNED_BYTE, data_px); // positive x
    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGB, size, size, 0, GL_RGB, GL_UNSIGNED_BYTE, data_py); // positive y
    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGB, size, size, 0, GL_RGB, GL_UNSIGNED_BYTE, data_pz); // positive z
    
    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGB, size, size, 0, GL_RGB, GL_UNSIGNED_BYTE, data_nx); // negative x
    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGB, size, size, 0, GL_RGB, GL_UNSIGNED_BYTE, data_ny); // negative y
    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGB, size, size, 0, GL_RGB, GL_UNSIGNED_BYTE, data_nz); // negative z
    
    
    //ofScale( _size, _size, _size );
    //ofScale( _size / 2.0f, _size / 2.0f, _size / 2.0f );
    
    float fExtent = 1.0f / 2.0f;
    
    
    
}

//--------------------------------------------------------------
void CubeMapping::setup(){
    
}

//--------------------------------------------------------------
void CubeMapping::update(){
    //sphere.pan(-0.1);
    
}

//--------------------------------------------------------------
void CubeMapping::draw(){
    ofBackgroundGradient(ofColor(50), ofColor(255));
    
    int pos=800;
    int boundToTextureUnit=pos;
    glActiveTexture( GL_TEXTURE0 + pos );
    glEnable( GL_TEXTURE_CUBE_MAP );
    glBindTexture( GL_TEXTURE_CUBE_MAP, textureObjectID );
    
    ofEnableDepthTest();
    
    
    cam.begin();
    //texture[0].getTexture().bind();
    shader.begin();
    shader.setUniformMatrix3f("normalMatrix", mat4ToMat3(ofGetCurrentNormalMatrix()));

    shader.setUniform1i("EnvMap", 0);
    
    shader.setUniform3f("LightPosition",lightPos->x,lightPos->y,lightPos->z);
    shader.setUniform3f("BaseColor",baseColor->x/255,baseColor->y/255,baseColor->z/255);
    shader.setUniform1f("MixRatio", mixRatio);
    //cout<<ofGetCurrentNormalMatrix()<<endl;
    cube.draw();
    shader.end();
   
    glActiveTexture( GL_TEXTURE0 + boundToTextureUnit );
    
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0 );
    glDisable( GL_TEXTURE_CUBE_MAP );
    
    glActiveTexture( GL_TEXTURE0 );
    
    
    cam.end();
    
    ofDisableDepthTest();
    gui.draw();
    
    
}

//--------------------------------------------------------------
void CubeMapping::reloadShader(){
    
    shader.load("shaders/"+title);
    
}

ofMatrix3x3 CubeMapping::mat4ToMat3(ofMatrix4x4 mat4)
{
    return ofMatrix3x3(mat4._mat[0][0], mat4._mat[0][1], mat4._mat[0][2], mat4._mat[1][0], mat4._mat[1][1], mat4._mat[1][2], mat4._mat[2][0], mat4._mat[2][1], mat4._mat[2][2]);
}

