//
//  Event.h
//  Trust
//
//  Created by Lincoln Scheer on 9/1/21.
//  Copyright © 2021 Lincoln Scheer. All rights reserved.
//

#ifndef Event_h
#define Event_h

#include "string"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "ImGuiManager.hpp"
#include "Scene.h"

/*
 ====================
 ABSTRACT EVENT CLASS
 ====================
 */

// Event class is a template for other sub-delagate events.
// It is meant to only old the title and a compleation boolean
// because all functionality is meant to be abstracted to other classes.
class Event {
public:
    // Title Get & Set
    void setTitle(const char* title)    { this->m_title = title; }
    const char* getTitle()              { return this->m_title; }
    // Completed Get & Set
    bool isCompleted()                  { return this->m_completed; }
    void markCompleted()                { this->m_completed = true; }
private:
    const char* m_title;
    bool m_completed = false;
};


/*
 ====================================================
 DELEGATE SPECIFIC DEFINITIONS & IMPLEMENTATION BELOW
 ====================================================
 */



// Universal Event
class UniversalEvent: public Event {
    /*
    Functionality Not Yet Needed But...
    ...May Be Useful Later
    */
};


// Memory Event
class MemoryEvent: public Event {
    /*
    Functionality Not Yet Needed But...
    ...May Be Useful Later
    */
};


// Asset Event
class AssetEvent: public Event {
    /*
    Functionality Not Yet Needed But...
    ...May Be Useful Later
    */
};


// Gui Evemt
class GUIEvent: public Event {
    /*
    Functionality Not Yet Needed But...
    ...May Be Useful Later
    */
};


// Render Event
/*
 Render event only requires a window pointer and scene pointer.
 */
class RenderEvent: public Event {
public:
    RenderEvent(GLFWwindow *window, ImGuiManager *imGui, Scene *scene) {
        this->m_window = window;
        this->m_imGui = imGui;
        this->m_scene = scene;
    }
    
    GLFWwindow* getWindow()     { return this->m_window; }
    ImGuiManager* getImGui()    { return this->m_imGui; }
    Scene* getScene()           { return this->m_scene; }
    
private:
    GLFWwindow *m_window;
    ImGuiManager *m_imGui;
    Scene *m_scene;
};

// Display Event
class DisplayEvent: public Event {
    
};

#endif /* Event_h */
