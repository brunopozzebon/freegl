//
// Created by bruno on 03/02/2021.
//

#include "Vertex.h"

Vertex::Vertex(Position p) {
    this->position = p;
    this->textureCoord = TextureCoord(0.0f, 0.0f);
}

Vertex::Vertex(Position p, TextureCoord tc) {
    this->position = p;
    this->textureCoord = tc;
}

Vertex::Vertex(Position p, TextureCoord tc, Normal normal) {
    this->position = p;
    this->textureCoord = tc;
    this->normal= normal;
}
