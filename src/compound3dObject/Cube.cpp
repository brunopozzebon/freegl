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
            //Plane A Frente
            Vertex(Position(xMinusHalfWidth, yMinusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord::BottomLeft, Normal::Front),
            Vertex(Position(xMinusHalfWidth, yPlusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord::TopLeft, Normal::Front),
            Vertex(Position(xPlusHalfWidth, yPlusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord::TopRight, Normal::Front),
            Vertex(Position(xPlusHalfWidth, yMinusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord::BottomRight, Normal::Front),

            //Plane B Tras
            Vertex(Position(xMinusHalfWidth, yMinusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord::BottomLeft, Normal::Back),
            Vertex(Position(xMinusHalfWidth, yPlusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord::TopLeft, Normal::Back),
            Vertex(Position(xPlusHalfWidth, yPlusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord::TopRight, Normal::Back),
            Vertex(Position(xPlusHalfWidth, yMinusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord::BottomRight, Normal::Back),

            //Plane C Topo
            Vertex(Position(xPlusHalfWidth, yPlusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord::BottomLeft, Normal::Top),
            Vertex(Position(xMinusHalfWidth, yPlusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord::TopLeft, Normal::Top),
            Vertex(Position(xMinusHalfWidth, yPlusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord::TopRight, Normal::Top),
            Vertex(Position(xPlusHalfWidth, yPlusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord::BottomRight, Normal::Top),

            //Plane D Base
            Vertex(Position(xMinusHalfWidth, yMinusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord::BottomLeft, Normal::Bottom),
            Vertex(Position(xPlusHalfWidth, yMinusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord::TopLeft, Normal::Bottom),
            Vertex(Position(xPlusHalfWidth, yMinusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord::TopRight,Normal::Bottom),
            Vertex(Position(xMinusHalfWidth, yMinusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord::BottomRight, Normal::Bottom),

            //Plane E Right
            Vertex(Position(xPlusHalfWidth, yPlusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord::BottomLeft, Normal::Right),
            Vertex(Position(xPlusHalfWidth, yMinusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord::TopLeft, Normal::Right),
            Vertex(Position(xPlusHalfWidth, yMinusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord::TopRight, Normal::Right),
            Vertex(Position(xPlusHalfWidth, yPlusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord::BottomRight, Normal::Right),

            //Plane F Left
            Vertex(Position(xMinusHalfWidth, yMinusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord::BottomLeft, Normal::Left),
            Vertex(Position(xMinusHalfWidth, yPlusHalfHeight, zPlusHalfDepth),
                   color, TextureCoord::TopLeft, Normal::Left),
            Vertex(Position(xMinusHalfWidth, yPlusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord::TopRight, Normal::Left),
            Vertex(Position(xMinusHalfWidth, yMinusHalfHeight, zMinusHalfDepth),
                   color, TextureCoord::BottomRight, Normal::Left),
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
