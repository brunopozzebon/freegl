//
// Created by bruno on 07/02/2021.
//

#ifndef FREEGL_PERSPECTIVECAMERA_H
#define FREEGL_PERSPECTIVECAMERA_H


#include "../raw/Window.h"
#include "../utils/glm/vec3.hpp"
#include "../utils/glm/ext.hpp"

const float cameraSpeed = 3.0f;

using namespace glm;

class PerspectiveCamera {

private:
    mat4 projection, view;
    Window window;
    vec3 position, lookat;
    float theta, phi, ray;

public:
    PerspectiveCamera(Window window);

    void moveFront();
    void moveBack();

    void updateTheta(float delta);
    void updatePhi(float delta);
    void scrool(float yoffset);

    void setRay(float ray);

    void update();

    inline vec3 getPosition(){return this->position;}
    inline mat4 getView(){return this->view;}
    inline mat4 getProjection(){return this->projection;}
};


#endif //FREEGL_PERSPECTIVECAMERA_H
