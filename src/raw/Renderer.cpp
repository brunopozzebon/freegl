//
// Created by Bruno Pozzebon on 24/01/2021.
//
#include "Renderer.h"

Renderer::Renderer(Color color) {
    glClearColor(color.getR(), color.getB(), color.getB(), color.getA());
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_BLEND_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Renderer::draw(vector<Mesh*> meshes) {

    for (int i = 0; i < meshes.size(); i++) {
        Mesh* m = meshes[i];
        m->draw();
    }
}

void Renderer::clear() {
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
}