//
// Created by bruno on 03/02/2021.
//

#ifndef UNTITLED_VERTEX_H
#define UNTITLED_VERTEX_H

#pragma once
#include "TextureCoord.h"
#include "Position.h"
#include "Normal.h"

class Vertex {
private:
    Position position;
    TextureCoord textureCoord;
    Normal normal;

public:
    Vertex(Position p);
    Vertex(Position p, TextureCoord tc);
    Vertex(Position p, TextureCoord tc, Normal n);

    inline string toString(){
        return position.toString() + " " + normal.toString();
    }

};


#endif //UNTITLED_VERTEX_H
