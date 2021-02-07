//
// Created by Bruno Pozzebon on 31/01/2021.
//

#pragma once

#ifndef UNTITLED_MESH_H
#define UNTITLED_MESH_H

#include "../basics/Vertex.h"
#include "../basics/Position.h"
#include "../basics/Color.h"
#include "../basics/TextureCoord.h"

#include "../../../../CLionProjects/freegl/src/raw/Texture.h"
#include "vector"
#include "../../../../CLionProjects/freegl/src/raw/VertexArrayLayout.h"
#include "../../../../CLionProjects/freegl/src/raw/VertexArray.h"
#include "../../../../CLionProjects/freegl/src/raw/IndexBuffer.h"
#include "../raw/Shader.h"

using namespace std;

class Mesh {
private:
    vector<Vertex> vertices;
    vector<unsigned int> indices;
    Texture* texture;
    IndexBuffer* indexBuffer;
    VertexArray* vertexArray;
    VertexBuffer* vertexBuffer;
    Position position;
    Color color;
public:

    Mesh(Position mesh, Color color);

    inline vector<Vertex> getVertices(){return vertices;}
    inline vector<unsigned int> getIndices(){return indices;}
    inline void setVertices(vector<Vertex> vertices){this->vertices = vertices;};
    inline void setIndices(vector<unsigned int> indices){ this->indices = indices;};

    inline glm::mat4 getTransformations(){
        return  glm::rotate(glm::mat4(1.0f), glm::radians(0.1f), glm::vec3(0.0f, 1.0f, 0.0f));
    }

    void init();

    void draw();
};


#endif //UNTITLED_MESH_H
