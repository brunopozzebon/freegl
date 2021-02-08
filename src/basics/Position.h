//
// Created by bruno on 03/02/2021.
//

#ifndef UNTITLED_POSITION_H
#define UNTITLED_POSITION_H

#pragma once

#include <string>

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

    inline std::string toString() {
        return "\n\tx: "+ std::to_string(x) + "y: "+ std::to_string(y) + "z: "+ std::to_string(z);
    }

};


#endif //UNTITLED_POSITION_H
