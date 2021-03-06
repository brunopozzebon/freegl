//
// Created by bruno on 07/02/2021.
//

#include "Prism.h"

std::vector<float> Prism::getSideNormals() {
    const float PI = acos(-1);
    float sectorStep = 2 * PI / sides;
    float sectorAngle;  // radian

    float zAngle = atan2(baseRadius - topRadius, height);
    float x0 = cos(zAngle);
    float y0 = 0;
    float z0 = sin(zAngle);

    std::vector<float> normals;
    for (int i = 0; i <= sides; ++i) {
        sectorAngle = i * sectorStep;
        normals.push_back(cos(sectorAngle) * x0 - sin(sectorAngle) * y0);   // nx
        normals.push_back(z0);
        normals.push_back(sin(sectorAngle) * x0 + cos(sectorAngle) * y0);   // ny
    }
    return normals;
}

Prism::Prism(Position p, float baseRadius, float topRadius, float height, float sides, float slices, Material material)
        : baseRadius(baseRadius),
          topRadius(topRadius), height(height), sides(sides), slices(slices), Mesh(p, material) {

    const float PI = acos(-1);
    float sectorStep = 2 * PI / this->sides;
    float sectorAngle;

    std::vector<float> unitCircleVertices = {};

    for (int i = 0; i <= this->sides; ++i) {
        sectorAngle = i * sectorStep;
        unitCircleVertices.push_back(cos(sectorAngle));
        unitCircleVertices.push_back(sin(sectorAngle));
        unitCircleVertices.push_back(0);
    }

    float radius, z, x, y;

    vector<Vertex> v = {};
    vector<unsigned int>{};

    std::vector<float> sideNormals = getSideNormals();

    for (int i = 0; i <= slices; ++i) {
        y = -(height * 0.5f) + (float) i / slices * height;
        radius = baseRadius + (float) i / slices * (topRadius - baseRadius);     // lerp
        float t = 1.0f - (float) i / slices;   // top-to-bottom

        for (int j = 0, k = 0; j <= sides; ++j, k += 3) {
            x = unitCircleVertices[k];
            z = unitCircleVertices[k + 1];
            v.push_back(
                    Vertex(inPosition(x * radius, y, z * radius),
                           TextureCoord((float) j / sides, t),
                           Normal(sideNormals[k], sideNormals[k + 1], sideNormals[k + 2]))
            );
        }
    }

    unsigned int baseVertexIndex = (unsigned int) v.size() + 1;

    y = -height * 0.5f;
    v.push_back(
            Vertex(inPosition(0, y, 0), TextureCoord(0.5f, 0.5f), Normal(0, 0, -1))
    );

    for (int i = 0, j = 0; i < sides; ++i, j += 3) {
        x = unitCircleVertices[j];
        z = unitCircleVertices[j + 1];

        v.push_back(
                Vertex(inPosition(x * baseRadius, y, z * baseRadius),
                       TextureCoord(-x * 0.5f + 0.5f, -z * 0.5f + 0.5f), Normal(0, 0, -1))
        );
    }

    unsigned int topVertexIndex = (unsigned int) v.size() + 1;
    y = height * 0.5f;

    v.push_back(
            Vertex(inPosition(0, y, 0), TextureCoord(0.5f, 0.5f), Normal(0, 0, 1))
    );

    for (int i = 0, j = 0; i < sides; ++i, j += 3) {
        x = unitCircleVertices[j];
        z = unitCircleVertices[j + 1];
        v.push_back(
                Vertex(inPosition(x * topRadius, y, z * topRadius),
                       TextureCoord(x * 0.5f + 0.5f, -z * 0.5f + 0.5f), Normal(0, 0, 1))
        );
    }

    vector<unsigned int> indices = {};

    unsigned int k1, k2;

    for (int i = 0; i < slices; ++i) {
        k1 = i * (sides + 1);
        k2 = k1 + sides + 1;

        for (int j = 0; j < sides; ++j, ++k1, ++k2) {
            indices.push_back(k1);
            indices.push_back(k1 + 1);
            indices.push_back(k2);

            indices.push_back(k2);
            indices.push_back(k1 + 1);
            indices.push_back(k2 + 1);
        }
    }

    for (int i = 0, k = baseVertexIndex; i < sides; ++i, ++k) {
        if (i < (sides - 1)) {
            indices.push_back(baseVertexIndex);
            indices.push_back(k + 1);
            indices.push_back(k);
        }
    }

    for (int i = 0, k = topVertexIndex; i < sides; ++i, ++k) {
        if (i < (sides - 1)) {
            indices.push_back(topVertexIndex);
            indices.push_back(k);
            indices.push_back(k + 1);
        }
    }

    setVertices(v);
    setIndices(indices);
    init();
}

Position Prism::inPosition(float x, float y, float z) {
    return Position(x + origin.getX(), y + origin.getY(), z + origin.getZ());
}
