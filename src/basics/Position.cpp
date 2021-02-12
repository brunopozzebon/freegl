//
// Created by bruno on 03/02/2021.
//

#include "Position.h"

Position::Position(float x, float y, float z) {
    this->x=x;
    this->y=y;
    this->z=z;
}

glm::vec3 Position::toVec3() {
    return glm::vec3(this->x, this->y, this->z);
}
