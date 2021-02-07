//
// Created by bruno on 07/02/2021.
//

#ifndef FREEGL_LINE_H
#define FREEGL_LINE_H

#include "../raw/VertexBuffer.h"
#include "../raw/VertexArray.h"
#include "../basics/SimpleVertex.h"
#include "../raw/Shader.h"

class Line {
private:
    vector<SimpleVertex> vertices;
    unsigned int VAO;
    unsigned int VBO;

    Color color;
public:
    Line(Position start, Position end, Color color);
    Line();

    void draw();

};


#endif //FREEGL_LINE_H
