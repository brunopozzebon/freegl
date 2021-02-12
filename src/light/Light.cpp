//
// Created by bruno on 11/02/2021.
//

#include "Light.h"


Light::Light(Color c, Position p) {
    this->color = c.toVec3();
    this->position = p.toVec3();
}
