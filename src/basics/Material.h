//
// Created by bruno on 12/02/2021.
//

#pragma once

#ifndef FREEGL_MATERIAL_H
#define FREEGL_MATERIAL_H

#include "../utils/glm/vec3.hpp"

using namespace glm;

class Material {
private:
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;

public:
    Material(vec3 ambient, vec3 diffuse, vec3 specular, float shininess);

    inline vec3 getAmbient(){return this->ambient;}
    inline vec3 getDiffuse(){return this->diffuse;}
    inline vec3 getSpecular(){return this->specular;}
    inline float getShininess(){return this->shininess;}

    static Material Default;
    static Material Emerald;
    static Material Jade;
    static Material Obsidian;
    static Material Pearl;
    static Material Ruby;
    static Material Turquoise;
    static Material Brass;
    static Material Bronze;
    static Material Chrome;
    static Material Copper;
    static Material Gold;
    static Material Silver;
    static Material Plastic;


};


#endif //FREEGL_MATERIAL_H
