//
// Created by bruno on 07/02/2021.
//

#include "PerspectiveCamera.h"


PerspectiveCamera::PerspectiveCamera(Window window) : window(window) {

    projection = perspective(radians(ray), (float) window.getWidth() /
                                                     (float) window.getHeight(), 0.1f, 1000.0f);
    view = mat4(1.0f);
    position = vec3(1.0f);
    lookat = vec3(0.0f, 0.0f, 0.0f);

    phi= 45.0f;
    theta= 0.0f;
    ray = 100.0f;
}

void PerspectiveCamera::update() {

    float aux = ray * sin(radians(phi));
    float x = aux * sin(radians(theta));
    float y = ray * cos(radians(phi));
    float z = aux * cos(radians(theta));

    position = vec3(x,y,z);
    lookat = position * (-1.0f);

    projection = perspective(radians(ray), (float) window.getWidth() /
                                                     (float) window.getHeight(), 0.1f, 1000.0f);
    view = lookAt(position, lookat, vec3(0.0f, 1.0f, 0.0f));
}



void PerspectiveCamera::moveFront() {
    float difference = ray - 1.3f;
    setRay(difference);
}

void PerspectiveCamera::moveBack() {
    float difference = ray + 1.3f;
    setRay(difference);
}

void PerspectiveCamera::setRay(float r) {
    if (r < 1.0f || r > 800.0f){
        return;
    }
    this->ray = r;
}

void PerspectiveCamera::scrool(float yoffset) {
    float difference = ray-yoffset;
    setRay(difference);
}

void PerspectiveCamera::updateTheta(float delta) {
    theta -=delta;
}

void PerspectiveCamera::updatePhi(float delta) {
    float newValue = phi-delta;
    if(newValue > 0 && newValue<90){
        phi =newValue;
    }
}
