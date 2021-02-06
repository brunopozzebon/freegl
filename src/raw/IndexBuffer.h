//
// Created by Bruno Pozzebon on 24/01/2021.
//
#pragma once

#include "GL/glew.h"
#include "vector"


#ifndef UNTITLED_INDEXBUFFER_H
#define UNTITLED_INDEXBUFFER_H

using namespace std;

class IndexBuffer {
private:
    unsigned int id;
    unsigned int size;
public:
    IndexBuffer(vector<unsigned int> indices);

    IndexBuffer();

    ~IndexBuffer();

    void bind();
    void unbind();

    int getSize();
};


#endif //UNTITLED_INDEXBUFFER_H
