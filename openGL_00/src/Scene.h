//
//  Scene.h
//  openGL_00
//
//  Created by João Fonseca on 21/06/15.
//
//

#pragma once

class Scene {
public:
    Scene();
    virtual void setup();
    virtual void update();
    virtual void draw();
    virtual void reloadShader();
};