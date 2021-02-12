//
// Created by bruno on 07/02/2021.
//

#ifndef FREEGL_CYLINDER_H
#define FREEGL_CYLINDER_H

#pragma once
#include "Prism.h"

class Cylinder : public Prism{
public:
    Cylinder(Position position, float ray, float height, float lateralFaces=40, Material material = Material::Default);
};


#endif //FREEGL_CYLINDER_H
