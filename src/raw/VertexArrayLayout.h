//
// Created by Bruno Pozzebon on 24/01/2021.
//
#pragma once
#include "vector"

#ifndef UNTITLED_VERTEXARRAYLAYOUT_H
#define UNTITLED_VERTEXARRAYLAYOUT_H

using namespace  std;

class VertexArrayLayout {
private:
    vector<int> elements;
    unsigned int stride;
public:
    VertexArrayLayout();
    void push(int count);

    vector<int> getElements();
    unsigned int getStride();
};


#endif //UNTITLED_VERTEXARRAYLAYOUT_H
