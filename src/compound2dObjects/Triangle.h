//
// Created by bruno on 07/02/2021.
//

#ifndef FREEGL_TRIANGLE_H
#define FREEGL_TRIANGLE_H


#include "../models/Mesh.h"

class Triangle : public Mesh{
private:
    Position vertexA;
    Position vertexB;
    Position vertexC;

public:
    Triangle(Position vertexA, Position vertexB, Position vertexC, Color color);
};


#endif //FREEGL_TRIANGLE_H
