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

static float theta, phi, ray = 0.0f;

class PerspectiveCamera {

private:
    mat4 projection, view;
    Window window;
    vec3 position, lookat;

public:
    PerspectiveCamera(Window window);

    static void updateTheta(float delta) {
        theta -=delta;
    }

    static void updatePhi(float delta) {
        float newValue = phi-delta;
        if(newValue > 0 && newValue<90){
            phi =newValue;
        }
    }

    static void moveFront() {
        float difference = ray - 1.3f;
        setRay(difference);
    }

    static void moveBack() {
        float difference = ray + 1.3f;
        setRay(difference);
    }

    static void scrool(float yoffset) {
        float difference = ray-yoffset;
        setRay(difference);
    }

    static void setRay(float r) {
        if (r < 1.0f || r > 800.0f){
            return;
        }
        ray = r;
    }

    void update();

    inline vec3 getPosition(){return this->position;}
    inline mat4 getView(){return this->view;}
    inline mat4 getProjection(){return this->projection;}
};


#endif //FREEGL_PERSPECTIVECAMERA_H
