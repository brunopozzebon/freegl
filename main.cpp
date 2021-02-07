#include <GL/glew.h>
#include "src/raw/Window.h"
#include "src/models/Plane.h"
#include "src/raw/Shader.h"
#include "src/camera/PerspectiveCamera.h"
#include "src/raw/Renderer.h"
#include "src/compound3dObject/Cube.h"
#include "src/raw/Interface.h"
#include "src/models/Line.h"

PerspectiveCamera *camera;

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
        camera->updateTheta(dx);

        dy = ypos - lastMousePosy;
        if (fabs(dy) > 10.0f) {
            dy = 10.0f;
        }

        lastMousePosy = ypos;
        camera->updatePhi(dy);
    }
}

void mouseScrool(GLFWwindow *window, double xpos, double ypos) {
    camera->scrool(ypos);
}


void listenInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera->moveFront();
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera->moveBack();
}

int main(void) {

    Window window(800, 600, "Hello World");
    Renderer renderer(Color::Gray);

    glfwSetCursorPosCallback(window.getWindow(), mouse_callback);
    glfwSetScrollCallback(window.getWindow(), mouseScrool);

    vector<Mesh *> meshes;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Cube *cube = new Cube(Position(i * 30, j * 30, 0), Color::Yellow, 20, 20, 20);
            meshes.push_back(cube);
        }
    }
    Cube * plane= new Cube(Position(50,50,50), Color::Red, 10,10,10);
    meshes.push_back(plane);

    Shader shader("../src/resources/shaders/vertexShader.glsl",
                  "../src/resources/shaders/fragmentShader.glsl");
    shader.bind();
    shader.setUniform1i("u_texture", 0);
    shader.setUniform3Vec("u_light.color", glm::vec3(1.0f, 1.0f, 1.0f));
    shader.setUniform3Vec("u_light.position", glm::vec3(50.0f, 50.0f, 50.0f));

    camera = new PerspectiveCamera(window);
    Interface interface(window);

    glm::mat4 model = glm::rotate(glm::mat4(1.0), glm::radians(0.1f), glm::vec3(0.0f, 1.0f, 0.0f));


    Shader shaderLine("../src/resources/shaders/linevertexShader.glsl",
                      "../src/resources/shaders/lineFragmentShader.glsl");
    shaderLine.bind();

    Line lineX(Position(0.0f, 0.0f, 0.0f), Position(1000.0f, 0.0f, 0.0f), Color::Red);
    Line lineY(Position(0.0f, 0.0f, 0.0f), Position(0.0f, 1000.0f, 0.0f), Color::Yellow);
    Line lineZ(Position(0.0f, 0.0f, 0.0f), Position(0.0f, 0.0f, 1000.0f), Color::Green);

    while (window.isOpen()) {
        listenInput(window.getWindow());
        camera->update();

        interface.newFrame();
        ImGui::Text("Application average %.3f ms/frame)", 1000.0f);

        shader.bind();
        shader.setUniform4Mat("u_projection", camera->getProjection());
        shader.setUniform4Mat("u_view", camera->getView());

        model =  glm::rotate(model, glm::radians(0.1f), glm::vec3(0.0f, 1.0f, 0.0f));

        shader.setUniform4Mat("u_model", model);

        shader.setUniform3Vec("u_camera_position", camera->getPosition());

        shader.bind();
        renderer.clear();
        renderer.draw(meshes);

        shaderLine.bind();
        shaderLine.setUniform4Mat("u_VP", camera->getProjection() * camera->getView());
        lineX.draw();
        lineY.draw();
        lineZ.draw();

        interface.render();
        window.update();
    }

    window.close();
    return 0;
}