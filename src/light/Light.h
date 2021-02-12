//
// Created by bruno on 11/02/2021.
//

#ifndef FREEGL_LIGHT_H
#define FREEGL_LIGHT_H

#pragma once

#include "../utils/glm/vec3.hpp"
#include "../basics/Color.h"
#include "../basics/Position.h"

class Light {
private:
    glm::vec3 color;
    glm::vec3 position;

public:
    Light(Color c, Position p);

    inline glm::vec3 getColor(){ return this->color;}
    inline glm::vec3 getPosition(){ return this->position;}

};


#endif //FREEGL_LIGHT_H
