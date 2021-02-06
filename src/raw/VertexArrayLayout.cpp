//
// Created by Bruno Pozzebon on 24/01/2021.
//

#include "VertexArrayLayout.h"

VertexArrayLayout::VertexArrayLayout() {
    stride=0;
    elements = vector<int>();
}

void VertexArrayLayout::push(int count) {
    elements.push_back(count);
    stride+=count;
}

vector<int> VertexArrayLayout::getElements(){
    return elements;
}

unsigned int VertexArrayLayout::getStride() {
    return stride;
}
