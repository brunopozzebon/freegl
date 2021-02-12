//
// Created by bruno on 07/02/2021.
//

#ifndef FREEGL_CONE_H
#define FREEGL_CONE_H

#pragma once
#include "Prism.h"

class Cone : public Prism{
public:
    Cone(Position position, float baseRay, float height, float lateralFaces=40, Material material = Material::Default);
};


#endif //FREEGL_CONE_H
