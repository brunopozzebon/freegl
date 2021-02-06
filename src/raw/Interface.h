//
// Created by Bruno Pozzebon on 27/01/2021.
//

#pragma once

#ifndef UNTITLED_INTERFACE_H
#define UNTITLED_INTERFACE_H

#include "../utils/imgui/imgui.h"
#include "../utils/imgui/imgui_impl_glfw.h"
#include "../utils/imgui/imgui_impl_opengl3.h"
#include "Window.h"

class Interface {

public:
    Interface(Window window);
    void newFrame();
    void render();
};


#endif //UNTITLED_INTERFACE_H
