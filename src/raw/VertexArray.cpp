//
// Created by Bruno Pozzebon on 24/01/2021.
//

#include "VertexArray.h"

VertexArray::VertexArray() {
    glGenVertexArrays(1, &id);
    glBindVertexArray(id);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &id);
}

void VertexArray::bind() {
    glBindVertexArray(id);
}

void VertexArray::unbind() {
    glBindVertexArray(0);
}

void VertexArray::addBuffer(VertexBuffer* vb, VertexArrayLayout* layout) {
    bind();
    vb->bind();
    vector<int> elements = layout->getElements();

    unsigned int offset = 0;

    for(int i=0; i < elements.size(); i ++){
        unsigned int element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i,element,GL_FLOAT, GL_FALSE, sizeof(float)* layout->getStride(),
                              (void*)( offset * sizeof(float)) );
        offset+=element;
    }
}



