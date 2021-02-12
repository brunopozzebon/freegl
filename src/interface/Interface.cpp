//
// Created by Bruno Pozzebon on 27/01/2021.
//

#include "Interface.h"
#include "styles/LightStyle.h"

Interface::Interface(Window window) {
    ImGui::CreateContext();
    ImGui_ImplOpenGL3_Init("#version 330");
    ImGui_ImplGlfw_InitForOpenGL(window.getWindow(), true);

    LightStyle::create();
}

void Interface::newFrame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void Interface::render() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
