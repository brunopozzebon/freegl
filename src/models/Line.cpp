//
// Created by bruno on 07/02/2021.
//

#include "Line.h"

Line::Line(Position start, Position end, Color color) {
    this->vertices = {
            SimpleVertex(start, color),
            SimpleVertex(end, color)
    };
    this->color=color;

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(SimpleVertex), &vertices[0], GL_STATIC_DRAW);

    VertexArrayLayout vertexArrayLayout;
    vertexArrayLayout.push(3);
    vertexArrayLayout.push(4);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    vector<int> elements = vertexArrayLayout.getElements();

    unsigned int offset = 0;

    for(int i=0; i < elements.size(); i ++){
        unsigned int element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i,element,GL_FLOAT, GL_FALSE, sizeof(float)* vertexArrayLayout.getStride(),
                              (void*)( offset * sizeof(float)) );
        offset+=element;
    }

}


void Line::draw() {
    glBindVertexArray(VAO);
    glDrawArrays(GL_LINES, 0, 2);
}