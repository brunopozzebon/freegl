//
// Created by bruno on 07/02/2021.
//

#include "OrthographicCamera.h"
#include "Camera.h"


void mouse_callback1(GLFWwindow *window, double xpos, double ypos){
    static float lastMousePosx = 0.0f;
    static float lastMousePosy = 0.0f;

    float dx, dy;

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
        dx = xpos - lastMousePosx;

        if (fabs(dx) > 10.0f) {
            dx = 10.0f;
        }

        lastMousePosx = xpos;
        OrthographicCamera::updateTheta(dx);

        dy = ypos - lastMousePosy;
        if (fabs(dy) > 10.0f) {
            dy = 10.0f;
        }

        lastMousePosy = ypos;
        OrthographicCamera::updatePhi(dy);
    }
}

void mouseScrool1(GLFWwindow *window, double xpos, double ypos) {
    OrthographicCamera::scrool(ypos);
}


void listenInput1(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        OrthographicCamera::moveFront();
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        OrthographicCamera::moveBack();
}

OrthographicCamera::OrthographicCamera(Window window) : Camera(window) {

    glfwSetCursorPosCallback(window.getWindow(), mouse_callback1);
    glfwSetScrollCallback(window.getWindow(), mouseScrool1);

    projection = ortho(-window.getWidth()/2, window.getWidth()/2,
                       -window.getHeight()/2, window.getHeight()/2,
                       -1000, 1000);
    view = mat4(1.0f);
    position = vec3(1.0f);
    lookat = vec3(0.0f, 0.0f, 0.0f);

    phi= 45.0f;
    theta= 0.0f;
    ray = 100.0f;
}

void OrthographicCamera::update() {
    listenInput1(window.getWindow());

    float aux = ray * sin(radians(phi));
    float x = aux * sin(radians(theta));
    float y = ray * cos(radians(phi));
    float z = aux * cos(radians(theta));

    position = vec3(x,y,z);
    lookat = position * (-1.0f);

    projection = ortho(-window.getWidth()/2, window.getWidth()/2,
                       -window.getHeight()/2, window.getHeight()/2,
                       -1000, 1000);
    view = lookAt(position, lookat, vec3(0.0f, 1.0f, 0.0f));
}



