#include <GL/glew.h>
#include "src/raw/Window.h"
#include "src/models/Plane.h"
#include "src/raw/Shader.h"
#include "src/camera/PerspectiveCamera.h"
#include "src/raw/Renderer.h"
#include "src/compound3dObject/Cube.h"
#include "src/raw/Interface.h"
#include "src/models/Line.h"
#include "src/compound3dObject/GridSystem.h"
#include "src/compound3dObject/Sphere.h"
#include "src/compound3dObject/Prism.h"

int main(void) {
    Window window(800, 600, "Hello World");
    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
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

    //Cube * cube = new Cube(Position(0,0,0), Color::Green, 5, 5, 5);

    //Sphere * sphere = new Sphere(Position(100,0,0), Color::White, 10, 30,30);

    Prism * prism = new Prism(Position(0, 0, 0), Color::White,
                              10, 3, 20, 10, 10);
    meshes.push_back(prism);


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