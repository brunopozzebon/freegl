//
// Created by Bruno Pozzebon on 24/01/2021.
//
#pragma once
#include "GL/glew.h"
#include "string"
#include "../utils/glm/ext.hpp"
#include <iostream>
#include <fstream>
#include <unordered_map>

#ifndef UNTITLED_SHADER_H
#define UNTITLED_SHADER_H

using namespace std;

class Shader {
private:
    unsigned int programId;
    unordered_map<string, GLint> locationCache;
    string parse(const string path);
    int compile(unsigned int type, string &source);

public:
    Shader(string vertexFilepath, string fragmentFilepath);

    ~Shader();

    void bind();

    void unbind();

    void setUniform4f(const string name, float a, float b, float c, float d);
    void setUniform1i(const string name, int a);
    void setUniform4Mat(const string name, glm::mat4 matrix);
    void setUniform3Vec(const string name, glm::vec3 vec);

    GLint getLocation(const string& name);
};


#endif //UNTITLED_SHADER_H
