//
// Created by bruno on 03/02/2021.
//

#ifndef UNTITLED_TEXTURECOORD_H
#define UNTITLED_TEXTURECOORD_H

#pragma once

class TextureCoord {
private:
    float s;
    float t;
public:
    TextureCoord(float s=0, float t=0);
    inline float getS(){return this->s;}
    inline float getT(){return this->t;}

};


#endif //UNTITLED_TEXTURECOORD_H
