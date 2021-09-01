//
//  Display.hpp
//  GLFW_OpenGL
//
//  Created by Lincoln Scheer on 3/24/21.
//  Copyright © 2021 Lincoln Scheer. All rights reserved.
//

#ifndef Display_hpp
#define Display_hpp

#include <stdio.h>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

#include "Manager.hpp"

class Display {
public:
    int screenWidth, screenHeight;
    GLFWwindow *window;
    Display();
    GLFWwindow* createDisplay(int width, int height);
    void updateScreenBufferSize(GLFWwindow *_window);
private:
    void init();
    
};

#endif /* Display_hpp */
