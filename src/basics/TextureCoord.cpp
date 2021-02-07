//
// Created by bruno on 03/02/2021.
//

#include "TextureCoord.h"

TextureCoord::TextureCoord(float s, float t) {
    this->s =s;
    this->t=t;
}

TextureCoord TextureCoord::BottomLeft = TextureCoord(0.0f, 0.0f);
TextureCoord TextureCoord::BottomRight = TextureCoord(1.0f, 0.0f);
TextureCoord TextureCoord::TopLeft = TextureCoord(0.0f, 1.0f);
TextureCoord TextureCoord::TopRight = TextureCoord(1.0f, 1.0f);
