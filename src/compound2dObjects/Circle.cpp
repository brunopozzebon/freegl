//
// Created by bruno on 07/02/2021.
//

#include "Circle.h"

Circle::Circle(Position p, Color c, float radius, float numOfSides) : numOfSides(numOfSides), radius(radius), Mesh(p, c) {

    const float PI = acos(-1);
    float sectorStep = 2 * PI / this->numOfSides;
    float sectorAngle;

    std::vector<float> unitCircleVertices = {};

    for (int i = 0; i <= this->numOfSides; ++i) {
        sectorAngle = i * sectorStep;
        unitCircleVertices.push_back(cos(sectorAngle));
        unitCircleVertices.push_back(sin(sectorAngle));
        unitCircleVertices.push_back(0);
    }

    vector<Vertex> vertices = {};

    vertices.push_back(
            Vertex(
                    inPosition(0, 0, 0),
                    c,
                    TextureCoord(0.5f, 0.5f),
                    Normal::Top)
    );

    for (int i = 0, j = 0; i < numOfSides; ++i, j += 3) {
        float x = unitCircleVertices[j];
        float z = unitCircleVertices[j + 1];

        Vertex vertex =  Vertex(
                inPosition(x * radius, 0, z * radius),
                c,
                TextureCoord(-x * 0.5f + 0.5f, -z * 0.5f + 0.5f),
                Normal::Top
                );

        vertices.push_back(
               vertex
        );
    }

    vector<unsigned int> indices = {};

    for (int i = 0, k = 1; i < numOfSides; ++i, ++k) {
        if (i < (numOfSides - 1)) {
            indices.push_back(1);
            indices.push_back(k + 1);
            indices.push_back(k);
        }
    }

    setVertices(vertices);
    setIndices(indices);
    init();
}



Position Circle::inPosition(float x, float y, float z) {
    return Position(origin.getX() + x, origin.getY()+y, origin.getZ()+z);
}
