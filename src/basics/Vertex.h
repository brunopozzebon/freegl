//
// Created by bruno on 03/02/2021.
//

#ifndef UNTITLED_VERTEX_H
#define UNTITLED_VERTEX_H

#pragma once
#include "Color.h"
#include "TextureCoord.h"
#include "Position.h"

class Vertex {
private:
    Position position;
    Color color;
    TextureCoord textureCoord;

public:
    Vertex(Position p, Color c);
    Vertex(Position p, Color c, TextureCoord tc);
};


#endif //UNTITLED_VERTEX_H
