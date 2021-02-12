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
    Prism(Position p, float baseRadius, float topRadius, float height, float sides , float slices, Material material = Material::Default);
};


#endif //FREEGL_PRISM_H
