//
// Created by bruno on 07/02/2021.
//

#include "Pyramid.h"


Pyramid::Pyramid(Position position, float base, float height, float numOfSides, Material material) :
        Prism(position, base, 0, height, numOfSides, 1, material) {

}
