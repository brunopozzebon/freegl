//
// Created by Bruno Pozzebon on 31/01/2021.
//

#include "Cube.h"

Cube::Cube(Position position, Color color, int width, int height, int depth) : Mesh(position, color) {
    float xPosition = position.getX();
    float yPosition = position.getY();
    float zPosition = position.getZ();

    float halfWidth = width / 2;
    float halfHeight = height / 2;
    float halfDepth = depth / 2;

    float xMinusHalfWidth = xPosition - halfWidth;
    float xPlusHalfWidth = xPosition + halfWidth;

    float yMinusHalfHeight = yPosition - halfHeight;
    float yPlusHalfHeight = yPosition + halfHeight;

    float zMinusHalfDepth = zPosition - halfDepth;
    float zPlusHalfDepth = zPosition + halfDepth;

    vector<Vertex> v = {
            //Plane A
            Vertex(Position(xMinusHalfWidth, yMinusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord(0.0f, 0.0f)
            ),
            Vertex(Position(xMinusHalfWidth, yPlusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord(0.0f, 1.0f)
            ),
            Vertex(Position(xPlusHalfWidth, yPlusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord(1.0f, 1.0f)
            ),
            Vertex(Position(xPlusHalfWidth, yMinusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord(1.0f, 0.0f)
            ),

            //Plane B
            Vertex(Position(xMinusHalfWidth, yMinusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord(0.0f, 0.0f)
            ),
            Vertex(Position(xMinusHalfWidth, yPlusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord(0.0f, 1.0f)
            ),
            Vertex(Position(xPlusHalfWidth, yPlusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord(1.0f, 1.0f)
            ),
            Vertex(Position(xPlusHalfWidth, yMinusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord(1.0f, 0.0f)
            ),

            //Plane C
            Vertex(Position(xPlusHalfWidth, yPlusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord(0.0f, 0.0f)
            ),
            Vertex(Position(xMinusHalfWidth, yPlusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord(0.0f, 1.0f)
            ),
            Vertex(Position(xMinusHalfWidth, yPlusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord(1.0f, 1.0f)
            ),
            Vertex(Position(xPlusHalfWidth, yPlusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord(1.0f, 0.0f)
            ),

            //Plane D
            Vertex(Position(xMinusHalfWidth, yMinusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord(0.0f, 0.0f)
            ),
            Vertex(Position(xPlusHalfWidth, yMinusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord(0.0f, 1.0f)
            ),
            Vertex(Position(xPlusHalfWidth, yMinusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord(1.0f, 1.0f)
            ),
            Vertex(Position(xMinusHalfWidth, yMinusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord(1.0f, 0.0f)
            ),

            //Plane E
            Vertex(Position(xPlusHalfWidth, yPlusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord(0.0f, 0.0f)
            ),
            Vertex(Position(xPlusHalfWidth, yMinusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord(0.0f, 1.0f)
            ),
            Vertex(Position(xPlusHalfWidth, yMinusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord(1.0f, 1.0f)
            ),
            Vertex(Position(xPlusHalfWidth, yPlusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord(1.0f, 0.0f)
            ),

            //Plane F
            Vertex(Position(xMinusHalfWidth, yMinusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord(0.0f, 0.0f)
            ),
            Vertex(Position(xMinusHalfWidth, yPlusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord(0.0f, 1.0f)
            ),
            Vertex(Position(xMinusHalfWidth, yPlusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord(1.0f, 1.0f)
            ),
            Vertex(Position(xMinusHalfWidth, yMinusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord(1.0f, 0.0f)
            ),

    };

    setVertices(v);

    vector<unsigned int> i = {
            //Plane A
            0, 1, 2,
            2, 3, 0,

            //Place B
            4, 5, 6,
            6, 7, 4,

            //Place C
            8, 9, 10,
            10, 11, 8,

            //Place D
            12, 13, 14,
            14, 15, 12,

            //Place E
            16, 17, 18,
            18, 19, 16,

            //Place F
            20, 21, 22,
            22, 23, 20
    };

    setIndices(i);

    init();
}
