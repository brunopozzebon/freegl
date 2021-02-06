#include <GL/glew.h>
#include "src/raw/Window.h"
#include "src/models/Plane.h"
#include "src/raw/Shader.h"
#include "src/camera/OrthographicCamera.h"
#include "src/raw/Renderer.h"
#include "src/compound3dObject/Cube.h"
#include "src/raw/Interface.h"

OrthographicCamera *camera;

void mouse_callback(GLFWwindow *window, double xpos, double ypos) {
    camera->mouseMove(xpos, ypos);
}

void mouseScrool(GLFWwindow *window, double xpos, double ypos) {
    camera->setFov(ypos);
}

void listenInput(GLFWwindow *window) {

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera->moveFront();
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera->moveBack();
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera->moveLeft();
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera->moveRight();
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        camera->moveUp();
    if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
        camera->moveDown();
}

int main(void) {

    Window window(800, 600, "Hello World");
    Renderer renderer;

    glfwSetCursorPosCallback(window.getWindow(), mouse_callback);
    glfwSetScrollCallback(window.getWindow(), mouseScrool);

    vector<Mesh *> meshes;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            Cube *cube = new Cube(Position(i * 30, j * 30, 0), Color::Yellow,20, 20, 20);
            meshes.push_back(cube);
        }
    }

    Shader shader("../src/resources/shaders/vertexShader.glsl",
                  "../src/resources/shaders/fragmentShader.glsl");
    shader.bind();
    shader.setUniform1i("u_texture", 0);

    camera = new OrthographicCamera(window);

    Interface interface(window);


    while (window.isOpen()) {
        interface.newFrame();
        ImGui::Text("Application average %.3f ms/frame)", 1000.0f);

        shader.setUniform4Mat("u_MVP", camera->getView());

        listenInput(window.getWindow());

        renderer.clear();
        renderer.draw(meshes);

        interface.render();

        window.update();
    }

    window.close();
    return 0;
}