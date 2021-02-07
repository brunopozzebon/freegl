//
// Created by bruno on 06/02/2021.
//

#include "Normal.h"

Normal::Normal(float x, float y, float z) {
    this->x=x;
    this->y=y;
    this->z=z;
}

Normal::Normal() {
    this->x=0.0f;
    this->y=0.0f;
    this->z=0.0f;
}

Normal Normal::Back = Normal(0.0f, 0.0f, -1.0f);
Normal Normal::Front = Normal(0.0f, 0.0f, 1.0f);
Normal Normal::Right = Normal(1.0f, 0.0f, 0.0f);
Normal Normal::Left = Normal(-1.0f, 0.0f, 0.0f);
Normal Normal::Top = Normal(0.0f, 1.0f, 0.0f);
Normal Normal::Bottom = Normal(0.0f, -1.0f, 0.0f);
