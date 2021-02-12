//
// Created by bruno on 11/02/2021.
//

#pragma once

#ifndef FREEGL_LIGHTSTYLE_H
#define FREEGL_LIGHTSTYLE_H

#include "../../utils/imgui/imgui.h"
#include "../../utils/imgui/imgui_impl_glfw.h"
#include "../../utils/imgui/imgui_impl_opengl3.h"
#include "../../utils/Convertion.h"
#include "../../basics/Color.h"

class LightStyle {
public:
    static void create() {

        //SetUp roboto
        ImGuiIO &io = ImGui::GetIO();
        io.Fonts->AddFontFromFileTTF("../roboto.ttf", 12.0f);

        ImGuiStyle &style = ImGui::GetStyle();

        //Paddings
        style.WindowPadding = ImVec2(20.0f, 20.0f);
        style.FramePadding = ImVec2(8.0f, 4.0f);
        style.ItemSpacing = ImVec2(15.0f, 6.0f);
        style.ItemInnerSpacing = ImVec2(7.0f, 7.0f);

        style.ScrollbarSize = 12.0f;
        style.GrabMinSize = 14.0f;

        //Border
        style.WindowBorderSize = 0.0f;
        style.ChildBorderSize = 0.0f;
        style.PopupBorderSize = 0.0f;
        style.FrameBorderSize = 0.0f;
        style.TabBorderSize = 0.0f;

        //BorderRadius
        style.WindowRounding = 4.0f;
        style.FrameRounding = 4.0f;
        style.ScrollbarRounding = 4.0f;
        style.GrabRounding = 12.0f;

        //Colors
        style.Colors[ImGuiCol_Text] = ImVec4(0.0, 0.0, 0.0, 1.00f);
        style.Colors[ImGuiCol_TextDisabled] = Convertion::toImguiColor(Color("#999999FF"));
        style.Colors[ImGuiCol_WindowBg] = Convertion::toImguiColor(Color("#F0F0F0FF"));
        style.Colors[ImGuiCol_PopupBg] = Convertion::toImguiColor(Color("#FFFFFFFA"));
        style.Colors[ImGuiCol_Border] = Convertion::toImguiColor(Color("#0000004D"));
        style.Colors[ImGuiCol_BorderShadow] = Convertion::toImguiColor(Color("#00000000"));
        style.Colors[ImGuiCol_FrameBg] = Convertion::toImguiColor(Color("#FFFFFFFF"));
        style.Colors[ImGuiCol_FrameBgHovered] = Convertion::toImguiColor(Color("#4296FA66"));
        style.Colors[ImGuiCol_FrameBgActive] = Convertion::toImguiColor(Color("#4296FAAB"));
        style.Colors[ImGuiCol_TitleBg] = Convertion::toImguiColor(Color("#F5F5F5FF"));
        style.Colors[ImGuiCol_TitleBgCollapsed] = Convertion::toImguiColor(Color("#FFFFFF82"));
        style.Colors[ImGuiCol_TitleBgActive] = Convertion::toImguiColor(Color("#D1D1D1FF"));
        style.Colors[ImGuiCol_MenuBarBg] = Convertion::toImguiColor(Color("#DBDBDBFF"));
        style.Colors[ImGuiCol_ScrollbarBg] = Convertion::toImguiColor(Color("#FAFAFA87"));
        style.Colors[ImGuiCol_ScrollbarGrab] = Convertion::toImguiColor(Color("#B0B0B0CC"));
        style.Colors[ImGuiCol_ScrollbarGrabHovered] = Convertion::toImguiColor(Color("#7D7D7DCC"));
        style.Colors[ImGuiCol_ScrollbarGrabActive] = Convertion::toImguiColor(Color("#7D7D7DFF"));
        style.Colors[ImGuiCol_CheckMark] = Convertion::toImguiColor(Color("#4296FAFF"));
        style.Colors[ImGuiCol_SliderGrab] = Convertion::toImguiColor(Color("#4296FAC7"));
        style.Colors[ImGuiCol_SliderGrabActive] = Convertion::toImguiColor(Color("#758ACC99"));
        style.Colors[ImGuiCol_Button] = Convertion::toImguiColor(Color("#4296FA66"));
        style.Colors[ImGuiCol_ButtonHovered] = Convertion::toImguiColor(Color("#4296FAFF"));
        style.Colors[ImGuiCol_ButtonActive] = Convertion::toImguiColor(Color("#0F87FAFF"));
        style.Colors[ImGuiCol_Header] = Convertion::toImguiColor(Color("#4296FA4F"));
        style.Colors[ImGuiCol_HeaderHovered] = Convertion::toImguiColor(Color("#4296FACC"));
        style.Colors[ImGuiCol_HeaderActive] = Convertion::toImguiColor(Color("#4296FAFF"));
        style.Colors[ImGuiCol_ResizeGrip] = Convertion::toImguiColor(Color("#5959592B"));
        style.Colors[ImGuiCol_ResizeGripHovered] = Convertion::toImguiColor(Color("#4296FAAB"));
        style.Colors[ImGuiCol_ResizeGripActive] = Convertion::toImguiColor(Color("#4296FAF2"));
        style.Colors[ImGuiCol_PlotLines] = Convertion::toImguiColor(Color("#636363FF"));
        style.Colors[ImGuiCol_PlotLinesHovered] = Convertion::toImguiColor(Color("#FF6E59FF"));
        style.Colors[ImGuiCol_PlotHistogram] = Convertion::toImguiColor(Color("#E6B300FF"));
        style.Colors[ImGuiCol_PlotHistogramHovered] = Convertion::toImguiColor(Color("#FF7300FF"));
        style.Colors[ImGuiCol_TextSelectedBg] = Convertion::toImguiColor(Color("#4296FA59"));
        style.Colors[ImGuiCol_Tab] = Convertion::toImguiColor(Color("#C3CBD5ED"));
        style.Colors[ImGuiCol_TabActive] = Convertion::toImguiColor(Color("#4296FAAB"));
        style.Colors[ImGuiCol_TabHovered] = Convertion::toImguiColor(Color("#4296FAAB"));
        style.Colors[ImGuiCol_TabUnfocused] = Convertion::toImguiColor(Color("#EBECEEFB"));
        style.Colors[ImGuiCol_TabUnfocusedActive] = Convertion::toImguiColor(Color("#BDD1E9FF"));

    }
};


#endif //FREEGL_LIGHTSTYLE_H

