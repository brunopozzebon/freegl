#include <GL/glew.h>
#include "src/raw/Window.h"
#include "src/compound2dObjects/Plane.h"
#include "src/raw/Shader.h"
#include "src/camera/PerspectiveCamera.h"
#include "src/raw/Renderer.h"
#include "src/raw/Interface.h"
#include "src/models/Line.h"
#include "src/compound3dObjects/GridSystem.h"
#include "src/compound3dObjects/Sphere.h"
#include "src/compound3dObjects/Prism.h"
#include "src/compound3dObjects/Pyramid.h"
#include "src/compound3dObjects/Cylinder.h"
#include "src/compound3dObjects/Cone.h"
#include "src/compound2dObjects/Circle.h"
#include "src/compound2dObjects/Triangle.h"

int main(void) {
    Window window(800, 600, "Hello World");
   // glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    Renderer renderer(Color::Gray);
    PerspectiveCamera * camera = new PerspectiveCamera(window);
    Interface interface(window);

    vector<Mesh *> meshes;

    /*
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Cube *cube = new Cube(Position(i * 30, j * 30, 0), Color::Yellow, 20, 20, 20);
            meshes.push_back(cube);
        }
    }
     */
   //Plane * plane = new Plane(Position(0,0,0), Color::Turquoise, 20, 20);
   Circle * cicle= new Circle(Position(10,0,10), Color::Turquoise,10);

   meshes.push_back(cicle);


    GridSystem grid;

    while (window.isOpen()) {

        camera->update();

        interface.newFrame();
        ImGui::Text("Application average %.3f ms/frame)", 1000.0f);

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