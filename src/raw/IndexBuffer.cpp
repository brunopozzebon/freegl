//
// Created by Bruno Pozzebon on 24/01/2021.
//
#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(vector<unsigned int> indices) {
    this->size = indices.size();
    glGenBuffers(1, &id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &id);
}

void IndexBuffer::bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void IndexBuffer::unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

int IndexBuffer::getSize() {
    return size;
}

IndexBuffer::IndexBuffer() {}

