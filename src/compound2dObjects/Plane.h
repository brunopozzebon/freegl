//
// Created by Bruno Pozzebon on 31/01/2021.
//


#ifndef UNTITLED_PLANE_H
#define UNTITLED_PLANE_H

#pragma once
#include "../models/Mesh.h"

class Plane: public Mesh{
private:
    Position position;
    int width;
    int height;
public:
    Plane(Position position,int width, int height, Material material = Material::Default);

};


#endif //UNTITLED_PLANE_H
