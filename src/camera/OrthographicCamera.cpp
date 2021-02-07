//
// Created by Bruno Pozzebon on 31/01/2021.
//

#include "OrthographicCamera.h"

OrthographicCamera::OrthographicCamera(Window window) : window(window) {

    projection = glm::perspective(glm::radians(fov), (float) window.getWidth() /
                                                       (float) window.getHeight(), 0.1f, 1000.0f);
    view = glm::mat4(1.0f);
    cameraPos = glm::vec3(50.0f, 50.0f, 200.0f);
    cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    fov = 45.0f;
    firstMouse = true;
    yaw = -90.0f;    // yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
    pitch = 0.0f;
    lastX = 800.0f / 2.0;
    lastY = 600.0 / 2.0;
}

glm::mat4 OrthographicCamera::getView() {
    projection = glm::perspective(glm::radians(fov), (float) window.getWidth() /
                                                     (float) window.getHeight(), 0.1f, 1000.0f);
    view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    return projection * view;
}

void OrthographicCamera::moveFront() {
    cameraPos += cameraSpeed * cameraFront;
}

void OrthographicCamera::moveBack() {
    cameraPos -= cameraSpeed * cameraFront;
}

void OrthographicCamera::moveDown() {
    cameraPos -= cameraSpeed * cameraUp;
}

void OrthographicCamera::moveUp() {
    cameraPos += cameraSpeed * cameraUp;
}

void OrthographicCamera::moveRight() {
    cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) *
                 cameraSpeed;
}

void OrthographicCamera::moveLeft() {
    cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) *
                 cameraSpeed;
}

void OrthographicCamera::setFov(float yoffset) {
    fov -= (float) yoffset;
    if (fov < 1.0f)
        fov = 1.0f;
    if (fov > 45.0f)
        fov = 45.0f;
}

void OrthographicCamera::mouseMove(double xpos, double ypos) {
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;

    float sensitivity = 0.1f;

    yaw += xoffset * sensitivity;
    pitch += yoffset * sensitivity;

    lastX = xpos;
    lastY = ypos;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;


    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = -1.0f;
    // direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    cameraFront = glm::normalize(direction);
}
