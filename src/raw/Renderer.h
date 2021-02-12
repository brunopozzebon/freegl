//
// Created by Bruno Pozzebon on 24/01/2021.
//
#pragma once
#include "GL/glew.h"
#include "vector"
#include "../models/Mesh.h"

#include "../camera/Camera.h"
#include "../light/Light.h"

#ifndef UNTITLED_RENDERER_H
#define UNTITLED_RENDERER_H

using namespace std;

class Renderer {
private:
    Shader shader;
public:
    Renderer(Color color);
    void draw(vector<Mesh*> meshes, Camera * camera);
    void clear();
    void putLight(Light light);
};


#endif //UNTITLED_RENDERER_H
