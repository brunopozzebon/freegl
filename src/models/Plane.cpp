//
// Created by Bruno Pozzebon on 31/01/2021.
//

#include "Plane.h"

Plane::Plane(Position position, Color color, int width, int height) : position(position), width(width), height(height), Mesh(position, color){

    vector<Vertex> v = {
            //x     y           z      r        g       b       s         t
            Vertex(Position(position.getX() - width/2, position.getY() - height/2),color),
            Vertex(Position(position.getX() - width/2, position.getY() + height/2),color),
            Vertex(Position(position.getX() + width/2, position.getY() + height/2),color),
            Vertex(Position(position.getX() + width/2, position.getY() - height/2),color),

    };

    setVertices(v);

    vector<unsigned int> i = {
            0, 1, 2,
            2, 3, 0
    };

    setIndices(i);

    init();
}