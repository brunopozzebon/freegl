//
// Created by Bruno Pozzebon on 24/01/2021.
//
#pragma once
#include "GL/glew.h"
#include "vector"
#include "../basics/Vertex.h"

using namespace std;

class VertexBuffer {
private:
    unsigned int id;
public:
    VertexBuffer(vector<Vertex> data);

    VertexBuffer();

    ~VertexBuffer();

    void bind();
    void unbind();
};

