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
    Circle(Position p, float radius, float numOfSides=36, Material material = Material::Default);

    Position inPosition(float x, float y, float z);
};


#endif //FREEGL_CIRCLE_H
