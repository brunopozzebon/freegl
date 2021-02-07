//
// Created by Bruno Pozzebon on 31/01/2021.
//

#include "Mesh.h"


Mesh::Mesh(Position position, Color color) : position(position), color(color){}

void Mesh::init(){

    vertexBuffer=  new VertexBuffer(vertices);

    VertexArrayLayout vertexArrayLayout;
    vertexArrayLayout.push(3);
    vertexArrayLayout.push(4);
    vertexArrayLayout.push(2);

    vertexArrayLayout.push(3);

    vertexArray = new VertexArray();
    vertexArray->addBuffer(vertexBuffer, &vertexArrayLayout);

    indexBuffer = new IndexBuffer(indices);

    string path = "../src/resources/images/image.png";
    texture = new Texture(path);

    texture->bind();
}

void Mesh::draw() {
    vertexArray->bind();
    indexBuffer->bind();
    texture->bind();
    glDrawElements(GL_TRIANGLES, indexBuffer->getSize(), GL_UNSIGNED_INT, nullptr);
}
