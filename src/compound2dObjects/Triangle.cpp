//
// Created by bruno on 07/02/2021.
//

#include "Triangle.h"

Triangle::Triangle(Position vertexA, Position vertexB, Position vertexC, Color color) : vertexA(vertexA),
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
                                                                                                        3), color) {
    vector<Vertex> vertices = {
            Vertex(vertexA, color, TextureCoord::TopRight, Normal::Top),
            Vertex(vertexB, color, TextureCoord::BottomRight, Normal::Top),
            Vertex(vertexC, color, TextureCoord::BottomLeft, Normal::Top),
    };

    setVertices(vertices);

    vector<unsigned int> indices = {
            0,1,2,
    };

    setIndices(indices);

    init();

}
