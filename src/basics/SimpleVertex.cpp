//
// Created by bruno on 07/02/2021.
//

#include "SimpleVertex.h"

SimpleVertex::SimpleVertex() {
    this->position=Position(0,0,0);
    this->color=Color(255,255,255);
}

SimpleVertex::SimpleVertex(Position position1, Color color1) {
    this->position=position1;
    this->color=color1;
}