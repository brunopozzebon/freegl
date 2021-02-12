//
// Created by Bruno Pozzebon on 31/01/2021.
//

#include "Plane.h"

Plane::Plane(Position position, int width, int height, Material material) :
position(position), width(width), height(height), Mesh(position, material){

    float xMinusHalfWidth = position.getX() - width/2;
    float xPlusHalfWidth = position.getX() + width/2;
    float yMinusHalfHeight = position.getY() - height/2;
    float yPlusHalfHeight = position.getY() + height/2;

    vector<Vertex> v = {
            Vertex(Position(xMinusHalfWidth, 0,yMinusHalfHeight), TextureCoord::BottomLeft, Normal::Top),
            Vertex(Position(xMinusHalfWidth, 0,yPlusHalfHeight), TextureCoord::TopLeft,Normal::Top),
            Vertex(Position(xPlusHalfWidth, 0,yPlusHalfHeight),TextureCoord::TopRight,Normal::Top),
            Vertex(Position(xPlusHalfWidth, 0,yMinusHalfHeight), TextureCoord::BottomRight,Normal::Top),
    };

    setVertices(v);

    vector<unsigned int> i = {
            0, 1, 2,
            2, 3, 0
    };

    setIndices(i);

    init();
}