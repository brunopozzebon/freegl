//
// Created by Bruno Pozzebon on 31/01/2021.
//

#include "Plane.h"

Plane::Plane(Position position, Color color, int width, int height) : position(position), width(width), height(height), Mesh(position, color){

    float xMinusHalfWidth = position.getX() - width/2;
    float xPlusHalfWidth = position.getX() + width/2;
    float yMinusHalfHeight = position.getY() - height/2;
    float yPlusHalfHeight = position.getY() + height/2;

    vector<Vertex> v = {
            Vertex(Position(xMinusHalfWidth, yMinusHalfHeight),color),
            Vertex(Position(xMinusHalfWidth, yPlusHalfHeight),color),
            Vertex(Position(xPlusHalfWidth, yMinusHalfHeight),color),
            Vertex(Position(xPlusHalfWidth, yPlusHalfHeight),color),
    };

    setVertices(v);

    vector<unsigned int> i = {
            0, 1, 2,
            2, 3, 0
    };

    setIndices(i);

    init();
}