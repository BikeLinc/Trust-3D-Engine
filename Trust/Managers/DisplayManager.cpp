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
    }
    if(m_window == NULL) {
        std::cout << "Cannot Create A Valid GLFW Reference" << std::endl;
        return NULL;
    }
    return m_window;
}

int DisplayManager::getWindowWidth() {
    return m_screenWidth;
}

int DisplayManager::getWindowHeight() {
    return m_screenWidth;
}

void DisplayManager::updateViewportSize() {
    glfwGetFramebufferSize(m_window, &m_screenWidth, &m_screenHeight);
    glViewport(0, -(m_screenWidth - m_screenHeight)/2 ,m_screenWidth ,m_screenWidth);
}
    
GLFWwindow* DisplayManager::createWindowReference() {
    GLFWwindow *window = glfwCreateWindow(600,400,"GLFW-OpenGL Window", nullptr, nullptr);
    glfwGetFramebufferSize(window, &m_screenWidth, &m_screenHeight);
    if (nullptr == window) {
        std::cout << "Failed To Create GLFW Window" << std::endl;
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(window);
    glfwGetFramebufferSize(window, &m_screenWidth, &m_screenHeight);
    
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
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
    if(GLEW_OK != glewInit()) {
        std::cout << "Failed To Initialize GLEW" << std::endl;
    }
    glViewport(0,0, m_screenWidth, m_screenHeight);
}

void DisplayManager::terminateGLFW() {
    glfwTerminate();
}
