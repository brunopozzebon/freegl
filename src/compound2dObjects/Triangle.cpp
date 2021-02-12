//
// Created by bruno on 07/02/2021.
//

#include "Triangle.h"

Triangle::Triangle(Position vertexA, Position vertexB, Position vertexC,  Material material) : vertexA(vertexA),
                                                                                        vertexB(vertexB),
                                                                                        vertexC(vertexC),
                                                                                        Mesh(
                                                                                                Position(
                                                                                                        (vertexA.getX() +
                                                                                                         vertexB.getX() +
                                                                                                         vertexC.getX()) /
                                                                                                        3,
                                                                                                        0,
                                                                                                        (vertexA.getY() +
                                                                                                         vertexB.getY() +
                                                                                                         vertexC.getY()) /
                                                                                                        3), material) {
    vector<Vertex> vertices = {
            Vertex(vertexA, TextureCoord::TopRight, Normal::Top),
            Vertex(vertexB, TextureCoord::BottomRight, Normal::Top),
            Vertex(vertexC, TextureCoord::BottomLeft, Normal::Top),
    };

    setVertices(vertices);

    vector<unsigned int> indices = {
            0,1,2,
    };

    setIndices(indices);

    init();

}
