//
// Created by bruno on 03/02/2021.
//

#ifndef UNTITLED_VERTEX_H
#define UNTITLED_VERTEX_H

#pragma once
#include "Color.h"
#include "TextureCoord.h"
#include "Position.h"
#include "Normal.h"

class Vertex {
private:
    Position position;
    Color color;
    TextureCoord textureCoord;
    Normal normal;

public:
    Vertex(Position p, Color c);
    Vertex(Position p, Color c, TextureCoord tc);
    Vertex(Position p, Color c, TextureCoord tc, Normal n);

    inline string toString(){
        return position.toString() + " " + color.toString() + " " + normal.toString();
    }

};


#endif //UNTITLED_VERTEX_H
