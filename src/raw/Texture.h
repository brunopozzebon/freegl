//
// Created by Bruno Pozzebon on 24/01/2021.
//

#pragma once
#include "GL/glew.h"
#include "string"
#include "../utils/std_image/std_image.h"
#ifndef UNTITLED_TEXTURE_H
#define UNTITLED_TEXTURE_H


using namespace std;

class Texture {
private:
    unsigned int id;
    string path;
    unsigned char* buffer;
    int width, height, bpp;
public:
    Texture(string path);

    Texture();

    ~Texture();

    void bind(unsigned int slot = 0);
    void unbind();

    inline int getWidth () { return width;}
    inline int getHeight () { return height;}
};


#endif //UNTITLED_TEXTURE_H
