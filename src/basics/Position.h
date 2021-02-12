//
// Created by bruno on 03/02/2021.
//

#ifndef UNTITLED_POSITION_H
#define UNTITLED_POSITION_H

#pragma once

#include <string>
#include "Color.h"

class Position {

private:
    float x;
    float y;
    float z;

public:
    Position(float x=0, float y=0, float z=0);

    inline float getX(){return this->x;}
    inline float getY(){return this->y;}
    inline float getZ(){return this->z;}

    inline void setX(float x){this->x = x;}
    inline void setY(float y){this->y = y;}
    inline void setZ(float z){this->z = z;}

    inline void translate(float deltax, float deltay, float deltaz){
        this->x=x+deltax;
        this->y=y+deltay;
        this->z=z+deltaz;
    }

    inline std::string toString() {
        return "\n\tx: "+ std::to_string(x) + "y: "+ std::to_string(y) + "z: "+ std::to_string(z);
    }

    glm::vec3 toVec3();
};


#endif //UNTITLED_POSITION_H
