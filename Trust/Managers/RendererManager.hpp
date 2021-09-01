//
//  RendererManager.hpp
//  Trust
//
//  Created by Lincoln Scheer on 8/31/21.
//  Copyright © 2021 Lincoln Scheer. All rights reserved.
//

#ifndef RendererManager_hpp
#define RendererManager_hpp

#include <glm/gtc/type_ptr.hpp>

#include "ImGuiManager.hpp"

#include "Manager.hpp"
#include "Shader.h"

#include "Scene.h"

class RendererManager: public Manager {
public:
    GLuint m_lightProgram;
    GLuint m_lampProgram;
    CameraPosition m_cameraPosition;
    void startUp() override;
    void shutDown(Scene scene);
    void prepare(Scene scene);
    void render(Scene scene);
    void drawGUI(GLFWwindow *window, ImGuiManager imGui, Scene scene);
    void cleanup(GLFWwindow *window);
};

#endif /* RendererManager_hpp */
