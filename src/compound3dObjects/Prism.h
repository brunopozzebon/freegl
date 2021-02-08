//
// Created by bruno on 07/02/2021.
//

#ifndef FREEGL_PRISM_H
#define FREEGL_PRISM_H

#pragma once

#include "../models/Mesh.h"

class Prism : public Mesh{
private:
    float baseRadius;
    float topRadius;
    float height;
    float sides; //sector
    float slices;

    vector<float> getSideNormals();
    Position inPosition(float x, float y, float z);
public:
    Prism(Position p, Color c, float baseRadius, float topRadius, float height, float sides = 3, float slices=10);
};


#endif //FREEGL_PRISM_H
