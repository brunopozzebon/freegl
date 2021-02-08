//
// Created by bruno on 07/02/2021.
//

#ifndef FREEGL_GRIDSYSTEM_H
#define FREEGL_GRIDSYSTEM_H

#pragma once
#include "../models/Line.h"

class GridSystem {
private:
    Line linex;
    Line liney;
    Line linez;
    Shader shader;
public:
    GridSystem();
    void draw();

    void setVP(glm::mat4 vp);

};


#endif //FREEGL_GRIDSYSTEM_H
