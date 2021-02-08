//
// Created by bruno on 07/02/2021.
//

#ifndef FREEGL_SPHERE_H
#define FREEGL_SPHERE_H


#pragma once
#include "../models/Mesh.h"

class Sphere : public Mesh{
private:
    float radius;
    int sections;
    int stacks;

public:
    Sphere(Position position, Color color, float radius, int sections=20, int stacks=20);
};


#endif //FREEGL_SPHERE_H
