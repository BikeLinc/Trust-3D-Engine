//
//  Display.cpp
//  GLFW_OpenGL
//
//  Created by Lincoln Scheer on 3/24/21.
//  Copyright © 2021 Lincoln Scheer. All rights reserved.
//
#include <iostream>

#include "Display.hpp"

int screenWidth, screenHeight;

GLfloat lastX, lastY;
bool keys[1024];
bool firstMouse = true;
bool guiFocoused = false;

void keyCallback();
void mouseCallback();
void scrollCallback();

Display::Display() {
    init();
}

void Display::init() {
    // New OpenGL Context
    glfwInit();
    
    // Setup OpenGL Core Version 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    // Required For OSX
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

    GLFWwindow* Display::createDisplay(int width, int height) {
    
    /* Setup Window */
    
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    
    GLFWwindow *window = glfwCreateWindow(width, height, "CHONG_3D_TOOL", nullptr, nullptr);
        this->window = window;
    // Mapping Screen
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    
    // Check If GLFW Window Creation Was Sucessful
    if(nullptr == window) {
        std::cout << "Failed To Create GLFW Window" << std::endl;
        glfwTerminate();
        return NULL;
    }
    
    // Make Context Current
    glfwMakeContextCurrent(window);
        
    glfwGetFramebufferSize( window, &width, &height );
        // Set the required callback functions
    
    // Enable Newer OpenGL Features
    glewExperimental = GL_TRUE;
    
    // Check If GLEW Is Initialized
    if(GLEW_OK != glewInit()) {
        std::cout << "Failed To Initialize GLEW" << std::endl;
        return NULL;
    }
    // Set Drawing Area
    glViewport(0,0,screenWidth, screenHeight);
    
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        
    return window;
}

void Display::updateScreenBufferSize(GLFWwindow *_window) {
    int width, height;
    glfwGetFramebufferSize(_window, &width, &height);
    glViewport(0,-(width-height)/2,width,width);
}

void keyCallback( GLFWwindow *window, int key, int scancode, int action, int mode ) {
    if( key == GLFW_KEY_ESCAPE && action == GLFW_PRESS )
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    
    if ( key >= 0 && key < 1024 )
    {
        if( action == GLFW_PRESS )
        {
            keys[key] = true;
            std::cout << "Key \'" << char(key) << "\' Pressed" << std::endl;
        }
        else if( action == GLFW_RELEASE )
        {
            keys[key] = false;
            std::cout << "Key \'" << char(key) << "\' Released" << std::endl;
        }
    }
}

void mouseCallback( GLFWwindow *window, double xPos, double yPos ) {
    
    lastX = xPos;
    lastY = yPos;
    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT)) {
        if( firstMouse ){
            lastX = xPos;
            lastY = yPos;
            firstMouse = false;
        }
        GLfloat xOffset = xPos - lastX;
        GLfloat yOffset = lastY - yPos;  // Reversed since y-coordinates go from bottom to left
        
        lastX = xPos;
        lastY = yPos;
        
        //camera.processMouseMovement( xOffset, yOffset );
    } else if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT)) {
    } else {
        lastX = xPos;
        lastY = yPos;
    }
}
void scrollCallback( GLFWwindow *window, double xOffset, double yOffset) {
    //camera.processMouseScroll( yOffset );
}
