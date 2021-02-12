//
// Created by Bruno Pozzebon on 24/01/2021.
//
#include "Renderer.h"

Renderer::Renderer(Color color) {
    glClearColor(color.getR(), color.getB(), color.getB(), color.getA());
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_BLEND_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    shader = Shader("../src/resources/shaders/vertexShader.glsl",
                  "../src/resources/shaders/fragmentShader.glsl");
    shader.bind();
    shader.setUniform1i("u_texture", 0);
}


void Renderer::draw(vector<Mesh*> meshes, Camera * camera) {

    shader.bind();
    shader.setUniform4Mat("u_projection", camera->getProjection());
    shader.setUniform4Mat("u_view", camera->getView());
    shader.setUniform3Vec("u_camera_position", camera->getPosition());


    for (int i = 0; i < meshes.size(); i++) {
        Mesh* m = meshes[i];
        glm::mat4 model = m->getTransformations();
        shader.setUniform4Mat("u_model", model);
        m->draw();
    }
}

void Renderer::clear() {
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
}

void Renderer::putLight(Light light) {
    shader.setUniform3Vec("u_light.color", light.getColor());
    shader.setUniform3Vec("u_light.position", light.getPosition());
}
