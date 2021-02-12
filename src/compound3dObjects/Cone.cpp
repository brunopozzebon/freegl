//
// Created by bruno on 07/02/2021.
//

#include "Cone.h"

Cone::Cone(Position position, float baseRay, float height, float lateralFaces, Material material) :
        Prism(position, baseRay*2, 0, height, lateralFaces, 1, material) {

}
