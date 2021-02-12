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
#include "string"

using namespace std;

class Mesh {
private:
    vector<Vertex> vertices;
    vector<unsigned int> indices;
    Texture* texture;
    string texturePath;

    IndexBuffer* indexBuffer;
    VertexArray* vertexArray;
    VertexBuffer* vertexBuffer;
    Color color;
    glm::mat4 transformationMatrix;

    void goToCenter();
    void goToOrigin();


protected:
    Position origin;
public:

    Mesh(Position origin, Color color);
    Mesh(Position origin, Color color, string texturePath);

    void setImage(string path);

    inline vector<Vertex> getVertices(){return vertices;}
    inline vector<unsigned int> getIndices(){return indices;}
    inline void setVertices(vector<Vertex> vertices){this->vertices = vertices;};
    inline void setIndices(vector<unsigned int> indices){ this->indices = indices;};

    inline glm::mat4 getTransformations(){
        return  transformationMatrix;
    }

    void rotateX(float degres = 1.0f);
    void rotateY(float degres = 1.0f);
    void rotateZ(float degres = 1.0f);

    void rotate(float degreesX, float degreesY, float degreesZ);

    void translateX(float delta = 1.0f);
    void translateY(float delta = 1.0f);
    void translateZ(float delta = 1.0f);

    void translate(float deltaX, float deltaY, float deltaZ);

    void scaleX(float factor = 1.01f);
    void scaleY(float factor = 1.01f);
    void scaleZ(float factor = 1.01f);

    void scale(float factorX, float factorY, float factorZ);

    void init();

    void draw();
};


#endif //UNTITLED_MESH_H
