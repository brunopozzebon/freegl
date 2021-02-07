//
// Created by bruno on 07/02/2021.
//

#ifndef FREEGL_SIMPLEVERTEX_H
#define FREEGL_SIMPLEVERTEX_H


#pragma once
#include "Position.h"
#include "Color.h"

class SimpleVertex {
private:
    Position position;
    Color color;
public:
    SimpleVertex(Position position1, Color color1);
    SimpleVertex();
};


#endif //FREEGL_SIMPLEVERTEX_H
