#include <GL/glew.h>
#include "src/raw/Window.h"
#include "src/compound2dObjects/Plane.h"
#include "src/raw/Shader.h"
#include "src/camera/PerspectiveCamera.h"
#include "src/raw/Renderer.h"
#include "src/interface/Interface.h"
#include "src/models/Line.h"
#include "src/compound3dObjects/GridSystem.h"
#include "src/compound3dObjects/Sphere.h"
#include "src/compound3dObjects/Prism.h"
#include "src/compound3dObjects/Pyramid.h"
#include "src/compound3dObjects/Cylinder.h"
#include "src/compound3dObjects/Cone.h"
#include "src/compound2dObjects/Circle.h"
#include "src/compound2dObjects/Triangle.h"
#include "src/camera/OrthographicCamera.h"
#include "src/compound3dObjects/Cube.h"

int main(void) {
    Window window(800, 600, "Hello World");
    glfwSwapInterval(1);

   // glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
   Light light(Color::White, Position(200,200,200));

    Renderer renderer(Color::Gray);
    renderer.putLight(light);

    PerspectiveCamera * camera = new PerspectiveCamera(window);
    Interface interface(window);

    vector<Mesh *> meshes;

    Cube * cube= new Cube(Position(10,10,10), Color::Turquoise,10, 10, 10);
    cube->setImage("../src/resources/images/image12.jpg");

    meshes.push_back(cube);

    GridSystem grid;

    float floats[] = {1.0f, 0.0f, 1.0f};



    while (window.isOpen()) {
        cube->rotateX(0.01f);
        camera->update();

        interface.newFrame();
        ImGui::Text("Application average %.3f ms/frame)", 1000.0f);
        ImGui::SliderFloat3("Model Matrix Translation", &floats[0], 0.0f, 960.0f);
       // ImGui::SetWindowPos(ImVec2(0, 768 - ImGui::GetWindowHeight() - 40), true);
        ImGui::ShowStyleEditor();

        renderer.clear();
        renderer.draw(meshes, camera);

        grid.setVP(camera->getProjection() * camera->getView());
        grid.draw();

        interface.render();
        window.update();
    }

    window.close();
    return 0;
}