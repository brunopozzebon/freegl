//
// Created by Bruno Pozzebon on 24/01/2021.
//
#pragma once
#include "GL/glew.h"
#include "vector"
#include "../models/Mesh.h"


#ifndef UNTITLED_RENDERER_H
#define UNTITLED_RENDERER_H

using namespace std;

class Renderer {
public:
    Renderer();
    void draw(vector<Mesh*> meshes);
    void clear();
};


#endif //UNTITLED_RENDERER_H
