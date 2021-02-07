//
// Created by bruno on 03/02/2021.
//

#include "Vertex.h"

Vertex::Vertex(Position p, Color c) {
    this->position = p;
    this->color=c;
    this->textureCoord = TextureCoord(0.0f, 0.0f);
}

Vertex::Vertex(Position p, Color c, TextureCoord tc) {
    this->position = p;
    this->color=c;
    this->textureCoord = tc;
}

Vertex::Vertex(Position p, Color c, TextureCoord tc, Normal normal) {
    this->position = p;
    this->color=c;
    this->textureCoord = tc;
    this->normal= normal;
}