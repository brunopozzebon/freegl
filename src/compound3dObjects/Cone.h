//
// Created by bruno on 07/02/2021.
//

#ifndef FREEGL_CONE_H
#define FREEGL_CONE_H

#pragma once
#include "Prism.h"

class Cone : public Prism{
public:
    Cone(Position position, Color color, float baseRay, float height, float lateralFaces=40);
};


#endif //FREEGL_CONE_H
