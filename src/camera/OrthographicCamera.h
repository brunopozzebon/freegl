//
// Created by Bruno Pozzebon on 31/01/2021.
//

#pragma once

#ifndef UNTITLED_ORTHOGRAPHICCAMERA_H
#define UNTITLED_ORTHOGRAPHICCAMERA_H


#include "../utils/glm/ext.hpp"
#include "../../../../CLionProjects/freegl/src/raw/Window.h"

const float cameraSpeed = 0.5f;

class OrthographicCamera {

private:

    glm::mat4 projection, view;
    Window window;
    glm::vec3 cameraPos, cameraFront, cameraUp, direction;
    bool firstMouse;

    float fov, yaw, pitch, lastX, lastY;

public:
    OrthographicCamera(Window window);
    inline glm::mat4 getProjection(){ return projection;}
    glm::mat4 getView();

   // void update();

    void moveFront();
    void moveBack();

    void moveRight();
    void moveLeft();

    void moveUp();
    void moveDown();

    void setFov(float yoffset);

    void mouseMove(double xpos, double ypos);

    inline glm::vec3 getPosition(){return this->cameraPos;}

};


#endif //UNTITLED_ORTHOGRAPHICCAMERA_H
