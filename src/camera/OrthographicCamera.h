//
// Created by Bruno Pozzebon on 31/01/2021.
//

#pragma once

#ifndef UNTITLED_ORTHOGRAPHICCAMERA_H
#define UNTITLED_ORTHOGRAPHICCAMERA_H


#include "../utils/glm/ext.hpp"
#include "../../../../CLionProjects/freegl/src/raw/Window.h"
#include "Camera.h"


class OrthographicCamera : public Camera{
public:
    OrthographicCamera(Window window);

    static void updateTheta(float delta) {
        theta -= delta;
    }

    static void updatePhi(float delta) {
        float newValue = phi - delta;
        if (newValue > 0 && newValue < 130) {
            phi = newValue;
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
        float difference = ray - yoffset;
        setRay(difference);
    }

    static void setRay(float r) {
        if (r < 1.0f || r > 800.0f) {
            return;
        }
        ray = r;
    }

    void update();
};


#endif //UNTITLED_ORTHOGRAPHICCAMERA_H
