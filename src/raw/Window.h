//
// Created by Bruno Pozzebon on 24/01/2021.
//

#define GLEW_STATIC

#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "string"
#include <iostream>
#ifndef UNTITLED_WINDOW_H
#define UNTITLED_WINDOW_H


class Window {
private:
    GLFWwindow *window;
    int width;
    int height;
public:
    Window(int width, int height, const char* name);
    bool isOpen();
    void update();
    void close();

    inline int getWidth(){ return width;}
    inline int getHeight(){ return height;}
    inline GLFWwindow* getWindow(){return window;};

};


#endif //UNTITLED_WINDOW_H
