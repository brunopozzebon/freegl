//
// Created by Bruno Pozzebon on 31/01/2021.
//

#include "Cube.h"

Cube::Cube(Position position, int width, int height, int depth, Material material) :
Mesh(position, material) {
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
                    TextureCoord::BottomLeft, Normal::Front),
            Vertex(Position(xMinusHalfWidth, yPlusHalfHeight, zPlusHalfDepth),
                    TextureCoord::TopLeft, Normal::Front),
            Vertex(Position(xPlusHalfWidth, yPlusHalfHeight, zPlusHalfDepth),
                    TextureCoord::TopRight, Normal::Front),
            Vertex(Position(xPlusHalfWidth, yMinusHalfHeight, zPlusHalfDepth),
                    TextureCoord::BottomRight, Normal::Front),

            //Plane B Tras
            Vertex(Position(xMinusHalfWidth, yMinusHalfHeight, zMinusHalfDepth),
                   TextureCoord::BottomLeft, Normal::Back),
            Vertex(Position(xMinusHalfWidth, yPlusHalfHeight, zMinusHalfDepth),
                    TextureCoord::TopLeft, Normal::Back),
            Vertex(Position(xPlusHalfWidth, yPlusHalfHeight, zMinusHalfDepth),
                    TextureCoord::TopRight, Normal::Back),
            Vertex(Position(xPlusHalfWidth, yMinusHalfHeight, zMinusHalfDepth),
                    TextureCoord::BottomRight, Normal::Back),

            //Plane C Topo
            Vertex(Position(xPlusHalfWidth, yPlusHalfHeight, zPlusHalfDepth),
                    TextureCoord::BottomLeft, Normal::Top),
            Vertex(Position(xMinusHalfWidth, yPlusHalfHeight, zPlusHalfDepth),
                    TextureCoord::TopLeft, Normal::Top),
            Vertex(Position(xMinusHalfWidth, yPlusHalfHeight, zMinusHalfDepth),
                    TextureCoord::TopRight, Normal::Top),
            Vertex(Position(xPlusHalfWidth, yPlusHalfHeight, zMinusHalfDepth),
                    TextureCoord::BottomRight, Normal::Top),

            //Plane D Base
            Vertex(Position(xMinusHalfWidth, yMinusHalfHeight, zPlusHalfDepth),
                    TextureCoord::BottomLeft, Normal::Bottom),
            Vertex(Position(xPlusHalfWidth, yMinusHalfHeight, zPlusHalfDepth),
                    TextureCoord::TopLeft, Normal::Bottom),
            Vertex(Position(xPlusHalfWidth, yMinusHalfHeight, zMinusHalfDepth),
                    TextureCoord::TopRight,Normal::Bottom),
            Vertex(Position(xMinusHalfWidth, yMinusHalfHeight, zMinusHalfDepth),
                    TextureCoord::BottomRight, Normal::Bottom),

            //Plane E Right
            Vertex(Position(xPlusHalfWidth, yPlusHalfHeight, zPlusHalfDepth),
                    TextureCoord::BottomLeft, Normal::Right),
            Vertex(Position(xPlusHalfWidth, yMinusHalfHeight, zPlusHalfDepth),
                    TextureCoord::TopLeft, Normal::Right),
            Vertex(Position(xPlusHalfWidth, yMinusHalfHeight, zMinusHalfDepth),
                    TextureCoord::TopRight, Normal::Right),
            Vertex(Position(xPlusHalfWidth, yPlusHalfHeight, zMinusHalfDepth),
                    TextureCoord::BottomRight, Normal::Right),

            //Plane F Left
            Vertex(Position(xMinusHalfWidth, yMinusHalfHeight, zPlusHalfDepth),
                    TextureCoord::BottomLeft, Normal::Left),
            Vertex(Position(xMinusHalfWidth, yPlusHalfHeight, zPlusHalfDepth),
                    TextureCoord::TopLeft, Normal::Left),
            Vertex(Position(xMinusHalfWidth, yPlusHalfHeight, zMinusHalfDepth),
                    TextureCoord::TopRight, Normal::Left),
            Vertex(Position(xMinusHalfWidth, yMinusHalfHeight, zMinusHalfDepth),
                    TextureCoord::BottomRight, Normal::Left),
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
