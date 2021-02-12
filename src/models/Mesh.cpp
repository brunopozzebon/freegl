//
// Created by Bruno Pozzebon on 31/01/2021.
//

#include "Mesh.h"

Mesh::Mesh(Position origin, Material material, string texture) :
        material(material),
        origin(origin),
        texturePath(texture),
        transformationMatrix(glm::mat4(1.0f)){}

void Mesh::init(){

    vertexBuffer=  new VertexBuffer(vertices);

    VertexArrayLayout vertexArrayLayout;
    vertexArrayLayout.push(3);
    vertexArrayLayout.push(2);
    vertexArrayLayout.push(3);

    vertexArray = new VertexArray();
    vertexArray->addBuffer(vertexBuffer, &vertexArrayLayout);

    indexBuffer = new IndexBuffer(indices);

    texture = new Texture(texturePath);

    texture->bind();
}

void Mesh::draw() {
    vertexArray->bind();
    indexBuffer->bind();
    texture->bind();
    glDrawElements(GL_TRIANGLES, indexBuffer->getSize(), GL_UNSIGNED_INT, nullptr);
}

void Mesh::rotateX(float degres) {
    goToCenter();
    this->transformationMatrix = glm::rotate(transformationMatrix, degres,
                                             glm::vec3(1.0f, 0.0f, 0.0f));
    goToOrigin();
}

void Mesh::rotateY(float degres) {
    goToCenter();
    this->transformationMatrix = glm::rotate(transformationMatrix, degres,
                                             glm::vec3(0.0f, 1.0f, 0.0f));
    goToOrigin();
}

void Mesh::rotateZ(float degres) {
    goToCenter();
    this->transformationMatrix = glm::rotate(transformationMatrix, degres,
                                             glm::vec3(0.0f, 0.0f, 1.0f));
    goToOrigin();
}

void Mesh::rotate(float degreesX, float degreesY, float degreesZ) {
    goToCenter();
    glm::mat4 transition = glm::rotate(transformationMatrix, degreesX,
                                             glm::vec3(1.0f, 0.0f, 0.0f));
    transition = glm::rotate(transition, degreesY,
                                       glm::vec3(0.0f, 1.0f, 0.0f));
    this->transformationMatrix = glm::rotate(transition, degreesZ,
                                       glm::vec3(0.0f, 0.0f, 1.0f));
    goToOrigin();
}

void Mesh::translateX(float delta) {
    this->origin.translate(delta,0.0f, 0.0f);
    this->transformationMatrix = glm::translate(transformationMatrix,
                                                glm::vec3(delta, 0.0f, 0.0f));

}

void Mesh::translateY(float delta) {
    this->origin.setY(this->origin.getY()+delta);
    this->transformationMatrix = glm::translate( this->transformationMatrix,
                                               glm::vec3(0.0f, +delta, 0.0f));
}

void Mesh::translateZ(float delta) {
    this->transformationMatrix = glm::translate(transformationMatrix,
                                                glm::vec3(0.0f, 0.0f, delta));
    this->origin.translate(0.0f, 0.0f, delta);
}

void Mesh::translate(float deltaX, float deltaY, float deltaZ) {
    this->transformationMatrix = glm::translate( this->transformationMatrix,
                                                glm::vec3(deltaX, deltaY, deltaZ));
}

void Mesh::scaleX(float factor) {
    goToCenter();
    this->transformationMatrix = glm::scale(transformationMatrix,
                                                glm::vec3(factor, 1.0f, 1.0f));
    goToOrigin();
}

void Mesh::scaleY(float factor) {
    goToCenter();
    this->transformationMatrix = glm::scale(transformationMatrix,
                                            glm::vec3(1.0f, factor, 1.0f));
    goToOrigin();
}

void Mesh::scaleZ(float factor) {
    goToCenter();
    this->transformationMatrix = glm::scale(transformationMatrix,
                                            glm::vec3(1.0f, 1.0f, factor));
    goToOrigin();
}

void Mesh::scale(float factorX, float factorY, float factorZ) {
    this->transformationMatrix = glm::scale(transformationMatrix,
                                            glm::vec3(factorX, factorY, factorZ));
}

void Mesh::goToCenter() {

    float originX = origin.getX();
    float originY = origin.getY();
    float originZ = origin.getZ();

    this->transformationMatrix = glm::translate(transformationMatrix,
                                            glm::vec3(originX, originY, originZ));
}

void Mesh::goToOrigin() {
    float originX = origin.getX();
    float originY = origin.getY();
    float originZ = origin.getZ();

    this->transformationMatrix = glm::translate(transformationMatrix,
                                                glm::vec3(-originX, -originY, -originZ));
}

void Mesh::setImage(string path) {
    texturePath = path;
    texture = new Texture(texturePath);

    texture->bind();
}

