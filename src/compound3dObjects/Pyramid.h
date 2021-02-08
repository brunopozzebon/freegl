//
// Created by bruno on 07/02/2021.
//

#ifndef FREEGL_PYRAMID_H
#define FREEGL_PYRAMID_H


#include "Prism.h"

class Pyramid : public Prism {
public:
    Pyramid(Position position, Color color, float base, float height, float numOfSides);

};


#endif //FREEGL_PYRAMID_H
