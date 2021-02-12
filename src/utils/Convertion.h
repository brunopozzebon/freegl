//
// Created by bruno on 06/02/2021.
//

#pragma once

#include "imgui/imgui.h"
#include "../basics/Color.h"

#ifndef FREEGL_CONVERTION_H
#define FREEGL_CONVERTION_H

#endif //FREEGL_CONVERTION_H

class Convertion{
public:
    static int charHexToInt(char c){
        int v = -1;
        if ((c >= '0') && (c <= '9'))
            v = (c - '0');
        else if ((c >= 'A') && (c <= 'F'))
            v = (c - 'A' + 10);
        else if ((c >= 'a') && (c <= 'f'))
            v = (c - 'a' + 10);
        return v;
    }

    static ImVec4 toImguiColor(Color color){
        return ImVec4(color.getR(), color.getG(), color.getB(), color.getA());
    }
};