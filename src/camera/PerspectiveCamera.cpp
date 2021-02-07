//
// Created by bruno on 07/02/2021.
//

#include "PerspectiveCamera.h"

void mouse_callback(GLFWwindow *window, double xpos, double ypos) {
    static float lastMousePosx = 0.0f;
    static float lastMousePosy = 0.0f;

    float dx, dy;

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
        dx = xpos - lastMousePosx;

        if (fabs(dx) > 10.0f) {
            dx = 10.0f;
        }

        lastMousePosx = xpos;
        PerspectiveCamera::updateTheta(dx);

        dy = ypos - lastMousePosy;
        if (fabs(dy) > 10.0f) {
            dy = 10.0f;
        }

        lastMousePosy = ypos;
        PerspectiveCamera::updatePhi(dy);
    }
}

void mouseScrool(GLFWwindow *window, double xpos, double ypos) {
    PerspectiveCamera::scrool(ypos);
}


void listenInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        PerspectiveCamera::moveFront();
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        PerspectiveCamera::moveBack();
}

PerspectiveCamera::PerspectiveCamera(Window window) : window(window) {

    glfwSetCursorPosCallback(window.getWindow(), mouse_callback);
    glfwSetScrollCallback(window.getWindow(), mouseScrool);

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
    listenInput(window.getWindow());

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



