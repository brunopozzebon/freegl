//
// Created by bruno on 07/02/2021.
//

#ifndef FREEGL_CAMERA_H
#define FREEGL_CAMERA_H

#include "../raw/Window.h"
#include "../utils/glm/vec3.hpp"
#include "../utils/glm/ext.hpp"

using namespace glm;

static float theta, phi, ray = 0.0f;

class Camera {
protected:
    mat4 projection, view;
    Window window;
    vec3 position, lookat;
public:

    Camera(Window window):window(window){}

    inline vec3 getPosition(){return this->position;}
    inline mat4 getView(){return this->view;}
    inline mat4 getProjection(){return this->projection;}

};


#endif //FREEGL_CAMERA_H
