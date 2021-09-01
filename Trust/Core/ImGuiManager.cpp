//
//  ImGuiManager.cpp
//  GLFW_OpenGL
//
//  Created by Lincoln Scheer on 3/25/21.
//  Copyright © 2021 Lincoln Scheer. All rights reserved.
//

#include "ImGuiManager.hpp"

bool properties_active = true;
int width, height;

ImGuiManager::ImGuiManager(GLFWwindow *window) {
    ImGui::CreateContext();
    ImGui_ImplGlfwGL3_Init(window, true, NULL);
    ImGui::StyleColorsDark();
    ImGui::GetStyle().WindowRounding = 0.0f;
    ImGui::GetStyle().FrameBorderSize = 0.1f;
    ImGui::GetStyle().FrameRounding = 2.0f;
    ImGui::GetStyle().GrabRounding = 2.0f;
    
    ImVec4* colors = ImGui::GetStyle().Colors;
    colors[ImGuiCol_Text]                   = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    colors[ImGuiCol_WindowBg]               = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
    colors[ImGuiCol_Border]                 = ImVec4(1.00f, 1.00f, 1.00f, 0.00f);
    colors[ImGuiCol_FrameBg]                = ImVec4(0.13f, 0.21f, 0.18f, 1.00f);
    colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.13f, 0.61f, 0.36f, 1.00f);
    colors[ImGuiCol_FrameBgActive]          = ImVec4(0.13f, 0.61f, 0.36f, 1.00f);
    colors[ImGuiCol_TitleBg]                = ImVec4(0.13f, 0.61f, 0.36f, 1.00f);
    colors[ImGuiCol_TitleBgActive]          = ImVec4(0.13f, 0.61f, 0.36f, 1.00f);
    colors[ImGuiCol_CheckMark]              = ImVec4(0.08f, 0.40f, 0.23f, 1.00f);
    colors[ImGuiCol_SliderGrab]             = ImVec4(0.08f, 0.40f, 0.23f, 1.00f);
    colors[ImGuiCol_SliderGrabActive]       = ImVec4(0.08f, 0.40f, 0.23f, 1.00f);
    colors[ImGuiCol_Button]                 = ImVec4(0.08f, 0.40f, 0.23f, 1.00f);
    colors[ImGuiCol_ButtonHovered]          = ImVec4(0.13f, 0.61f, 0.36f, 1.00f);
    colors[ImGuiCol_ButtonActive]           = ImVec4(0.13f, 0.61f, 0.36f, 1.00f);
    colors[ImGuiCol_Header]                 = ImVec4(0.13f, 0.61f, 0.36f, 1.00f);
    colors[ImGuiCol_HeaderHovered]          = ImVec4(0.08f, 0.40f, 0.23f, 1.00f);
    colors[ImGuiCol_HeaderActive]           = ImVec4(0.08f, 0.40f, 0.23f, 1.00f);
    colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.13f, 0.61f, 0.36f, 1.00f);
    colors[ImGuiCol_SeparatorActive]        = ImVec4(0.13f, 0.61f, 0.36f, 1.00f);
    colors[ImGuiCol_ResizeGrip]             = ImVec4(0.13f, 0.61f, 0.36f, 1.00f);
    colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.13f, 0.61f, 0.36f, 1.00f);
    colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.13f, 0.61f, 0.36f, 1.00f);
}

void ImGuiManager::beginFrame(GLFWwindow *window) {
    ImGui_ImplGlfwGL3_NewFrame();
    glfwGetWindowSize(window, &width, &height);
}

bool ImGuiManager::drawWindow(glm::vec3 &cube_position, glm::vec3 &cube_rotation, glm::vec4 &cube_color, glm::vec3 &light_position, glm::vec4 &light_color, glm::vec4 &clear_color, glm::vec3 &camera_position, float &yaw, float &pitch) {
    {
        ImGui::Begin("Settigns");
        if (ImGui::CollapsingHeader("Cube")) {
            ImGui::DragFloat3("Position##cube", glm::value_ptr(cube_position), 0.01f, -1000.0f, 1000.0f, "%.4f", 1.0f);
            ImGui::DragFloat3("Rotation##cube", glm::value_ptr(cube_rotation), 0.01f, -1000.0f, 1000.0f, "%.4f", 1.0f);
            ImGui::ColorEdit3("Color##cube",(float*) &cube_color);
        }
        if (ImGui::CollapsingHeader("Light")) {
            ImGui::DragFloat3("Position##light", glm::value_ptr(light_position), 0.01f, -1000.0f, 1000.0f, "%.4f", 1.0f);
            ImGui::ColorEdit3("Color##light",(float*) &light_color);
        }
        if (ImGui::CollapsingHeader("Camera")) {
            ImGui::DragFloat3("Position##camera", glm::value_ptr(camera_position), 0.01f, -1000.0f, 1000.0f, "%.4f", 1.0f);
            float cam_rot[2] = {yaw, pitch};
            ImGui::DragFloat2("Rotation##camera", cam_rot, 0.01f, -360.0f, 360.0f, "%.4f", 1.0f);
            yaw = cam_rot[0];
            pitch = cam_rot[1];
        }
        if (ImGui::CollapsingHeader("Background")) {
            ImGui::ColorEdit3("Color##background",(float*) &clear_color);
        }
        
        // Stats
        ImGui::NewLine();
        ImGui::NewLine();
        ImGui::Text("Stats:");
        ImGui::Text("Application average %.3f ms/frame (%.3f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::Text("Elapsed Time %.4f min", ImGui::GetTime() / 60);
        ImGui::SetWindowPos(ImVec2(0.0f,height*(1.0f/5.0f)));
        ImGui::SetWindowSize(ImVec2(width/4, height-(height*(1.0f/5.0f))));
        ImGui::End();
        
        ImGui::Begin("a");
        ImGui::SetWindowPos(ImVec2(0,0));
        ImGui::SetWindowSize(ImVec2(width, (height*(1.0f/5.0f))));
        ImGui::End();
        
        ImGui::Begin("c");
        ImGui::SetWindowPos(ImVec2(width*.25f,height*.75));
        ImGui::SetWindowSize(ImVec2(width/2, height*.25));
        ImGui::End();
        
        ImGui::Begin("d");
        ImGui::SetWindowPos(ImVec2(width-(width/4),height*(1.0f/5.0f)));
        ImGui::SetWindowSize(ImVec2(width/4, height-(height*(1.0f/5.0f))));
        ImGui::End();
    }
    return ImGui::IsWindowFocused();
}

void ImGuiManager::endFrame() {
    ImGui::Render();
    ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiManager::shutDown() {
    ImGui_ImplGlfwGL3_Shutdown();
    ImGui::DestroyContext();
}
