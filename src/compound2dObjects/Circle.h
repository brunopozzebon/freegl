//
// Created by bruno on 07/02/2021.
//

#ifndef FREEGL_CIRCLE_H
#define FREEGL_CIRCLE_H

#pragma once
#include "../models/Mesh.h"

class Circle : public Mesh{
private:
    float radius;
    float numOfSides;
public:
    Circle(Position p, Color c, float radius, float numOfSides=36);

    Position inPosition(float x, float y, float z);
};


#endif //FREEGL_CIRCLE_H
