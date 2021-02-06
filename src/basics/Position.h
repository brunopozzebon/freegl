//
// Created by bruno on 03/02/2021.
//

#ifndef UNTITLED_POSITION_H
#define UNTITLED_POSITION_H

#pragma once

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

};


#endif //UNTITLED_POSITION_H
