//
// Created by bruno on 07/02/2021.
//

#include "Cone.h"

Cone::Cone(Position position, Color color, float baseRay, float height, float lateralFaces) :
        Prism(position, color, baseRay*2, 0, height, lateralFaces, 1) {

}
