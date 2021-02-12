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
    Light light(Color::White, Position(100, 200, -200));

    Renderer renderer(Color::Gray);
    renderer.putLight(light);

    PerspectiveCamera *camera = new PerspectiveCamera(window);
    Interface interface(window);

    vector<Mesh *> meshes;

    {
        /**
    Cube *cube = new Cube(Position(10, 10, 10), 10, 10, 10,
                          Material::Bronze);
    Cube *cube1 = new Cube(Position(20, 10, 10), 10, 10, 10,
                           Material::Default);
    Cube *cube2 = new Cube(Position(30, 10, 10), 10, 10, 10,
                           Material::Plastic);
    Cube *cube3 = new Cube(Position(40, 10, 10), 10, 10, 10,
                           Material::Turquoise);
    Cube *cube4 = new Cube(Position(50, 10, 10), 10, 10, 10,
                           Material::Obsidian);
    Cube *cube5 = new Cube(Position(60, 10, 10), 10, 10, 10,
                           Material::Emerald);
    Cube *cube6 = new Cube(Position(70, 10, 10), 10, 10, 10,
                           Material::Ruby);
    Cube *cube7 = new Cube(Position(80, 10, 10), 10, 10, 10,
                           Material::Gold);
    Cube *cube8 = new Cube(Position(10, 20, 10), 10, 10, 10,
                           Material::Copper);
    Cube *cube9 = new Cube(Position(20, 20, 10), 10, 10, 10,
                           Material::Chrome);
    Cube *cube10 = new Cube(Position(30, 20, 10), 10, 10, 10,
                            Material::Brass);
    Cube *cube11 = new Cube(Position(40, 20, 10), 10, 10, 10,
                            Material::Emerald);
    Cube *cube12 = new Cube(Position(50, 20, 10), 10, 10, 10,
                            Material::Jade);
    Cube *cube13 = new Cube(Position(60, 20, 10), 10, 10, 10,
                            Material::Pearl);
    Cube *cube14 = new Cube(Position(70, 20, 10), 10, 10, 10,
                            Material::Silver);

    meshes.push_back(cube);
    meshes.push_back(cube1);
    meshes.push_back(cube2);
    meshes.push_back(cube3);
    meshes.push_back(cube4);
    meshes.push_back(cube5);
    meshes.push_back(cube6);
    meshes.push_back(cube7);
    meshes.push_back(cube8);
    meshes.push_back(cube9);
    meshes.push_back(cube10);
    meshes.push_back(cube11);
    meshes.push_back(cube12);
    meshes.push_back(cube13);
    meshes.push_back(cube14);**/
}

    Cube *cube = new Cube(Position(0, 0, 0), 10, 10, 10,
                          Material::Default);

    meshes.push_back(cube);
    GridSystem grid;

    float floats[] = {1.0f, 0.0f, 1.0f};

    while (window.isOpen()) {

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