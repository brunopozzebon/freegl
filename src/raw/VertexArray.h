//
// Created by Bruno Pozzebon on 24/01/2021.
//
#pragma once
#include "GL/glew.h"
#include <iostream>
#include "./VertexBuffer.h"
#include "./VertexArrayLayout.h"

#ifndef UNTITLED_VERTEXARRAY_H
#define UNTITLED_VERTEXARRAY_H

class VertexArray {
private:
    unsigned int id;

public:
 VertexArray();
 ~VertexArray();

 void bind();
 void unbind();
 void addBuffer(VertexBuffer* vb, VertexArrayLayout* layout);
};


#endif //UNTITLED_VERTEXARRAY_H
