//
//  EngineLoop.cpp
//  Trust
//
//  Created by Lincoln Scheer on 8/25/21.
//  Copyright © 2021 Lincoln Scheer. All rights reserved.
//

#include "EngineLoop.hpp"

void EngineLoop::start() {
    
    MemoryManager memoryManager;
    DisplayManager displayManager;
    AssetManager assetManager;
    RendererManager rendererManager;
    GUIManager guiManager;
    
    memoryManager.startUp();
    assetManager.startUp();
    displayManager.startUp();
    
    GLFWwindow * window = displayManager.getWindowReference();
    
    rendererManager.startUp();
    guiManager.startUp();
    
    ImGuiManager imGui = ImGuiManager(window);

    
    Scene scene(600,400);
    
    //glfwSwapInterval(0); // VSYNC
    
    /* Main Rendering Loop */
    while(!glfwWindowShouldClose(window)) {
        
        displayManager.updateViewportSize();
        
        rendererManager.prepare(scene);
        rendererManager.render(scene);
        rendererManager.drawGUI(window, imGui, scene);
        rendererManager.cleanup(window);
        
    }
        
        
        // Cleanup Before Window Termination
        imGui.shutDown();
    
    
    
    
    guiManager.shutDown();
    rendererManager.shutDown(scene);
    assetManager.shutDown();
    displayManager.shutDown();
    memoryManager.shutDown();
}

// void EngineLoop::load();

// void EngineLoop::loop();
