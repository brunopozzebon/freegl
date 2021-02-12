//
// Created by Bruno Pozzebon on 24/01/2021.
//

#include "Shader.h"

Shader::Shader(){
    Shader("../src/resources/shaders/vertexShader.glsl",
           "../src/resources/shaders/fragmentShader.glsl");
}

Shader::Shader(string vertexFilepath, string fragmentFilepath) {
    unsigned int program = glCreateProgram();
    string vertexShader = parse(vertexFilepath);
    string fragmentShader = parse(fragmentFilepath);

    unsigned int vertexShaderId = compile(GL_VERTEX_SHADER, vertexShader);
    unsigned int fragmentShaderId = compile(GL_FRAGMENT_SHADER, fragmentShader);
    glAttachShader(program, vertexShaderId);
    glAttachShader(program, fragmentShaderId);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);
    glUseProgram(program);
    programId = program;
}

Shader::~Shader() {
    glDeleteShader(programId);
}

int Shader::compile(unsigned int type, string &source) {
    unsigned int id = glCreateShader(type);
    const char *src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char *message = (char *) alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile shader" << message << ((type == GL_VERTEX_SHADER) ? "Vertex" : "Fragment")
                  << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}

string Shader::parse(const string path) {
    ifstream stream(path);
    string line;
    string str;
    while (getline(stream, line)) {
        str += line + "\n";
    }
    return str;
}


void Shader::bind() {
    glUseProgram(programId);
}

void Shader::unbind() {
    glUseProgram(0);
}

void Shader::setUniform4f(const string name, float a, float b, float c, float d) {
    GLint location = getLocation(name);
    glUniform4f(location, a, b, c, d);
}

void Shader::setUniform1i(const string name, int a) {
    GLint location = getLocation(name);
    glUniform1i(location, a);
}

void Shader::setUniform3Vec(const string name, glm::vec3 vec) {
    GLint location = getLocation(name);
    glUniform3f(location, vec.x, vec.y, vec.z);
}

void Shader::setUniform4Mat(const string name, glm::mat4 matrix) {
    GLint location = getLocation(name);
    glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);
}

void Shader::setUniform1f(const char *name, float value) {
    GLint location = getLocation(name);
    glUniform1f(location, value);
}


GLint Shader::getLocation(const string &name) {
    if(locationCache.find(name)!= locationCache.end()){
        return locationCache[name];
    }

    GLint location = glGetUniformLocation(programId, name.c_str());
    locationCache[name] = location;
    return location;
}




