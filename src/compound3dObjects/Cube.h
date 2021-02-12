//
// Created by Bruno Pozzebon on 31/01/2021.
//

#ifndef UNTITLED_CUBE_H
#define UNTITLED_CUBE_H


#include "../models/Mesh.h"

class Cube : public Mesh{

public:
    Cube(Position position, int width, int height, int depth, Material material = Material::Default);

};


#endif //UNTITLED_CUBE_H
