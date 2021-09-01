//
//  DisplayManager.hpp
//  Trust
//
//  Created by Lincoln Scheer on 8/30/21.
//  Copyright © 2021 Lincoln Scheer. All rights rese&rved.
//

#ifndef DisplayManager_hpp
#define DisplayManager_hpp

#define GLEW_STATIC

// STD Library
#include <iostream>
#include <stddef.h>

// GLEW (OPEN_GL)
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>

#include "Manager.hpp"

class DisplayManager: public Manager {
public:
    void startUp() override;
    void shutDown() override;
    GLFWwindow* getWindowReference();
    int getWindowWidth();
    int getWindowHeight();
    void updateViewportSize();
private:
    GLFWwindow *m_window = NULL;
    int m_screenWidth, m_screenHeight;
    GLFWwindow* createWindowReference();
    void initGLFW();
    void initGLEW();
    void terminateGLFW();
};

#endif /* DisplayManager_hpp */
