//
// Created by Bruno Pozzebon on 24/01/2021.
//
#define STB_IMAGE_IMPLEMENTATION
#include "Texture.h"


Texture::Texture(string path): width(0), height(0), bpp(0), buffer(nullptr), id(0), path(path) {
    stbi_set_flip_vertically_on_load(true);
    buffer = stbi_load(path.c_str(), &width, &height, &bpp, 4);
    glGenTextures(1, &id);

    glBindTexture(GL_TEXTURE_2D, id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);

    glBindTexture(GL_TEXTURE_2D, 0);

    if(buffer){
        stbi_image_free(buffer);
    }

}



Texture::~Texture() {
    glDeleteTextures(1, &id);
}

void Texture::bind(unsigned int slot) {
    glActiveTexture(GL_TEXTURE0+slot);
    glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::Texture() {}
