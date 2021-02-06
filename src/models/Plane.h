//
// Created by Bruno Pozzebon on 31/01/2021.
//


#ifndef UNTITLED_PLANE_H
#define UNTITLED_PLANE_H

#pragma once
#include "Mesh.h"

class Plane: public Mesh{
private:
    Position position;
    int width;
    int height;
public:
    Plane(Position position, Color color, int width, int height);

};


#endif //UNTITLED_PLANE_H
