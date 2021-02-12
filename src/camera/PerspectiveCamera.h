//
// Created by bruno on 07/02/2021.
//

#ifndef FREEGL_PERSPECTIVECAMERA_H
#define FREEGL_PERSPECTIVECAMERA_H

#pragma once
#include "Camera.h"

class PerspectiveCamera : public Camera {

public:
    PerspectiveCamera(Window window);

    static void updateTheta(float delta) {
        theta -=delta;
    }

    static void updatePhi(float delta) {
        float newValue = phi-delta;
        if(newValue > 0 && newValue<130){
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
};


#endif //FREEGL_PERSPECTIVECAMERA_H
