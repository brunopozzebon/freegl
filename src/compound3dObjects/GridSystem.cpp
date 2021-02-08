//
// Created by bruno on 07/02/2021.
//

#include "GridSystem.h"

GridSystem::GridSystem() : shader(
        Shader("../src/resources/shaders/linevertexShader.glsl",
               "../src/resources/shaders/lineFragmentShader.glsl")
) {
    this->linex = Line(Position(0.0f, 0.0f, 0.0f), Position(1000.0f, 0.0f, 0.0f), Color::Red);
    this->liney = Line(Position(0.0f, 0.0f, 0.0f), Position(0.0f, 1000.0f, 0.0f), Color::Yellow);
    this->linez = Line(Position(0.0f, 0.0f, 0.0f), Position(0.0f, 0.0f, 1000.0f), Color::Green);
}

void GridSystem::draw() {
    linex.draw();
    liney.draw();
    linez.draw();
}

void GridSystem::setVP(glm::mat4 vp) {
    shader.bind();
    shader.setUniform4Mat("u_VP", vp);
}
