//
// Created by Bruno Pozzebon on 24/01/2021.
//

#include "Window.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

Window::Window(int width, int height, const char* name) : width(width), height(height) {

    if (!glfwInit())
        close();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, name, NULL, NULL);
    if (!window) {
        std::cout << "GLFW problem" << std::endl;
       close();
    }

    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if (GLEW_OK != err) {
        std::cout << "Glew problem" << std::endl;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

bool Window::isOpen() {
    return !glfwWindowShouldClose(window);
}

void Window::update() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::close(){
    glfwTerminate();
}


