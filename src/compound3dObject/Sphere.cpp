//
// Created by bruno on 07/02/2021.
//

#include "Sphere.h"

Sphere::Sphere(Position position, Color color, float radius, int sections, int stacks) : radius(radius),
                                                                                         sections(sections),
                                                                                         stacks(stacks),
                                                                                         Mesh(position, color) {
    const float PI = glm::pi<float>();
    const float lengthInv = 1.0f;

    float sectorStep = 2 * PI / sections;
    float stackStep = PI / stacks;
    float sectorAngle, stackAngle;

    vector<Vertex> v = {};

    for (int i = 0; i <= stacks; ++i) {
        stackAngle = PI / 2 - i * stackStep;
        float xy = radius * cosf(stackAngle);
        float z = radius * sinf(stackAngle);

        for (int j = 0; j <= sections; ++j) {
            sectorAngle = j * sectorStep;
            float x = xy * cosf(sectorAngle);
            float y = xy * sinf(sectorAngle);

            float nx = x * lengthInv;
            float ny = y * lengthInv;
            float nz = z * lengthInv;

            float s = (float) j / sections;
            float t = (float) i / stacks;

            float initialXPosition = position.getX();
            float initialYPosition = position.getY();
            float initialZPosition = position.getZ();

            v.push_back(
                    Vertex(
                            Position(x+initialXPosition, y+initialYPosition, z+initialZPosition),
                            color,
                            TextureCoord(s, t),
                            Normal(nx, ny, nz))
            );
        }
    }

    setVertices(v);

    vector<unsigned int> indices = {};

    unsigned int k1, k2;

    for (int i = 0; i < stacks; ++i) {
        k1 = i * (sections + 1);
        k2 = k1 + sections + 1;

        for (int j = 0; j < sections; ++j, ++k1, ++k2) {

            if (i != 0) {
                indices.push_back(k1);
                indices.push_back(k2);
                indices.push_back(k1 + 1);
            }

            if (i != (stacks - 1)) {
                indices.push_back(k1 + 1);
                indices.push_back(k2);
                indices.push_back(k2 + 1);
            }
        }
    }

    setIndices(indices);

    init();
}
