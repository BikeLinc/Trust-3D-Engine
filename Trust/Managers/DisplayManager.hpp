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

#include <iostream>
#include <stddef.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Manager.hpp"

class DisplayManager: public Manager {
public:
    /** startUp() is a virtual function that is inherited from the Manager class and is
        meant to be called prior to any other public methods in this class. */
    void startUp() override;
    
    /** shutDown() is a virtual function that is inherited from the Manager class and is
        meant to be called before termination of the entire engine and in reverse
        initialization order. */
    void shutDown() override;
    
    /** getWindowReference() is a function that returns a pointer of the member window
        variable. If the current member window variable is NULL then function calls
        createWindowReference() to initialize a current context. */
    GLFWwindow* getWindowReference();
    
    /** getWindowWidth() is a function that returns a the current width of the member
        window variable, If the current member window variable is NULL then the function
        returns a zero value.*/
    int getWindowWidth();
    
    /** getWindowHeight() is a function that returns a the current width of the member
    window variable, If the current member window variable is NULL then the function
    returns a zero value.*/
    int getWindowHeight();
    
    /** updateViewportSize() is a function that first gets the member winfow variable's
        frame buffer width and height and then sets the current OpenGL viewport to
        the width and a cropped height to avoid streaching when window resize. If the
        current memeber window variable is NULL */
    void updateViewportSize();
    
    
private:
    // Private Member Variables
    GLFWwindow *m_window = NULL;
    int m_screenWidth, m_screenHeight;
    
    /** createWindowReference() is a function that creates a new GLFWwindow context
        and sets the window hints to a full 3D depth capabilities. Function does not check
        if member window variable is NULL  because that is done in getWindowReference()*/
    GLFWwindow* createWindowReference();
    
    /** initGLFW() is a function that calls all the necesary initialization code and window
        hints so that a window can be initialized on all platforms(WIN & UNIX) using OpenGL 3.3 and GLFW3
        MUST BE CALLED BEFORE initGLEW() */
    void initGLFW();
    
    /** initGLEW() is a function that create a new OpenGL viewport on the given window context.
        MUST BE CALLLED AFTER initGLFW() */
    void initGLEW();
    
    /** terminateGLFW() throws away and frees the memory that the member window
        variable was using. This is called by shutDown() */
    void terminateGLFW();
};

#endif /* DisplayManager_hpp */
