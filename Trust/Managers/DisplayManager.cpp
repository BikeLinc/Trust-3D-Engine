//
//  DisplayManager.cpp
//  Trust
//
//  Created by Lincoln Scheer on 8/30/21.
//  Copyright © 2021 Lincoln Scheer. All rights reserved.
//

#include "DisplayManager.hpp"

void DisplayManager::startUp() {
    initGLFW();
}

void DisplayManager::shutDown()  {
    terminateGLFW();
}

GLFWwindow* DisplayManager::getWindowReference() {
    if(m_window == NULL) {
        m_window = createWindowReference();
        initGLEW();
        if(m_window == NULL) { // Double check if initialization failed above
            std::cout << "Cannot Create A Valid GLFW Reference" << std::endl;
            return NULL;
        }
    }
    return m_window;
}

int DisplayManager::getWindowWidth() {
    if(m_window == NULL) { // Dont return anything if there is no window
        return 0;
    } else {
        updateViewportSize();
        return m_screenWidth;
    }
}

int DisplayManager::getWindowHeight() {
    if(m_window == NULL) { // Dont return anything if there is no window
        return 0;
    } else {
        updateViewportSize();
    return m_screenWidth;
    }
}

void DisplayManager::updateViewportSize() {
    // Get width and height
    glfwGetFramebufferSize(m_window, &m_screenWidth, &m_screenHeight);
    // Set viewport width and height with an offset to avoid streaching
    glViewport(0, -(m_screenWidth - m_screenHeight)/2 ,m_screenWidth ,m_screenWidth);
}
    
GLFWwindow* DisplayManager::createWindowReference() {
    GLFWwindow *window = glfwCreateWindow(600,400,"GLFW-OpenGL Window", nullptr, nullptr);
    if (nullptr == window) { // If window wasnt initialized, shut the engine down.
        std::cout << "Failed To Create GLFW Window" << std::endl;
        shutDown();
        return NULL;
    }
    glfwMakeContextCurrent(window);
    glfwGetFramebufferSize(window, &m_screenWidth, &m_screenHeight);
    
    // Enable 3D Depth
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    
    // Enable JPEG and RGBA
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    return window;
}

void DisplayManager::initGLFW() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Required For OSX
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
}

void DisplayManager::initGLEW() {
    glewExperimental = GL_TRUE;
    if(GLEW_OK != glewInit()) { // If GLEW wasnt initialized, shut the engine down
        std::cout << "Failed To Initialize GLEW" << std::endl;
        shutDown();
    }
    // Set viewport width and height with an offset to avoid streaching
    glViewport(0, -(m_screenWidth - m_screenHeight)/2 ,m_screenWidth ,m_screenWidth);
}

void DisplayManager::terminateGLFW() {
    glfwTerminate();
}
