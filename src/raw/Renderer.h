//
// Created by Bruno Pozzebon on 24/01/2021.
//
#pragma once
#include "GL/glew.h"
#include "vector"
#include "../models/Mesh.h"

#include "../camera/PerspectiveCamera.h"

#ifndef UNTITLED_RENDERER_H
#define UNTITLED_RENDERER_H

using namespace std;

class Renderer {
private:
    Shader shader;
public:
    Renderer(Color color);
    void draw(vector<Mesh*> meshes, PerspectiveCamera * camera);
    void clear();
};


#endif //UNTITLED_RENDERER_H
