//
//  ImGuiManager.hpp
//  GLFW_OpenGL
//
//  Created by Lincoln Scheer on 3/25/21.
//  Copyright © 2021 Lincoln Scheer. All rights reserved.
//

#ifndef ImGuiManager_hpp
#define ImGuiManager_hpp

#include <stdio.h>
#include "imgui.h"
#include "imgui_impl_glfw_gl3.h"
#include "Camera.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class ImGuiManager {
public:
    ImGuiManager(GLFWwindow *window);
    void beginFrame(GLFWwindow *window);
    bool drawWindow(glm::vec3 &cube_position, glm::vec3 &cube_rotation, glm::vec4 &cube_color, glm::vec3 &light_position, glm::vec4 &light_color, glm::vec4 &clear_color, glm::vec3 &camera_position, float &yaw, float &pitch);
    void endFrame();
    void shutDown();
};

#endif /* ImGuiManager_hpp */
