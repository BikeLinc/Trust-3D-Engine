//
//  RendererManager.cpp
//  Trust
//
//  Created by Lincoln Scheer on 8/31/21.
//  Copyright © 2021 Lincoln Scheer. All rights reserved.
//

#include "RendererManager.hpp"

void RendererManager::startUp() {
    Shader lightShader("res/shaders/cube_vertex.glsl", "res/shaders/cube_fragment.glsl");
    Shader lampShader("res/shaders/lamp_vertex.glsl", "res/shaders/lamp_fragment.glsl");
    m_lightProgram = lightShader.Program;
    m_lampProgram = lampShader.Program;
}

void RendererManager::shutDown(Scene scene) {
    glDeleteVertexArrays(1, &scene.m_cube.cubeVAO);
    glDeleteVertexArrays(1, &scene.m_cube.lightVAO);
    glDeleteBuffers(1, &scene.m_cube.VBO);
}

void RendererManager::prepare(Scene scene) {
    glClearColor(scene.clearColor.x, scene.clearColor.y, scene.clearColor.z, scene.clearColor.w);
}

void RendererManager::render(Scene scene) {
    m_cameraPosition.set(scene.m_camera.getPosition(), scene.m_camera.getPitch(), scene.m_camera.getYaw());
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Use cooresponding shader when setting uniforms/drawing objects
    glUseProgram(m_lightProgram);
    GLint objectColorLoc = glGetUniformLocation(m_lightProgram, "objectColor" );
    GLint lightColorLoc  = glGetUniformLocation(m_lightProgram, "lightColor" );
    GLint lightPosLoc  = glGetUniformLocation(m_lightProgram, "lightPos" );
    GLint viewPosLoc  = glGetUniformLocation(m_lightProgram, "viewPos" );
    glUniform3f( objectColorLoc, scene.m_cube.color.x, scene.m_cube.color.y, scene.m_cube.color.z );
    glUniform3f( lightColorLoc,  scene.m_light.color.x, scene.m_light.color.y, scene.m_light.color.z );
    glUniform3f( lightPosLoc, scene.m_light.getPos().x, scene.m_light.getPos().y, scene.m_light.getPos().z);
    glUniform3f(viewPosLoc, scene.m_camera.getPosition().x, scene.m_camera.getPosition().y, scene.m_camera.getPosition().z);
    
    // Create camera transformations
    glm::mat4 view(1);
    view = scene.m_camera.getViewMatrix( );
    
    // Get the uniform locations
    GLint modelLoc = glGetUniformLocation( m_lightProgram, "model" );
    GLint viewLoc = glGetUniformLocation( m_lightProgram,  "view" );
    GLint projLoc = glGetUniformLocation(m_lightProgram,  "projection" );
    
    // Pass the matrices to the shader
    glUniformMatrix4fv( viewLoc, 1, GL_FALSE, glm::value_ptr( view ) );
    glUniformMatrix4fv( projLoc, 1, GL_FALSE, glm::value_ptr( scene.m_camera.projection ) );
    
    // Draw the container (using container's vertex attributes)
    glBindVertexArray( scene.m_cube.cubeVAO );
    
    
    glm::mat4 model(1);
    model = glm::translate(model, glm::vec3(scene.m_cube.position.x, scene.m_cube.position.y, scene.m_cube.position.z));
    model = glm::rotate(model, scene.m_cube.rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, scene.m_cube.rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, scene.m_cube.rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
    glUniformMatrix4fv( modelLoc, 1, GL_FALSE, glm::value_ptr( model ) );
    glDrawArrays( GL_TRIANGLES, 0, 36 );
    glBindVertexArray( 0 );
    
    // Also draw the lamp object, again binding the appropriate shader
    glUseProgram(m_lampProgram);
    
    // Get location objects for the matrices on the lamp shader (these could be different on a different shader)
    modelLoc = glGetUniformLocation( m_lampProgram, "model" );
    viewLoc = glGetUniformLocation( m_lampProgram, "view" );
    projLoc = glGetUniformLocation(m_lampProgram, "projection" );
    
    // Set matrices
    glUniformMatrix4fv( viewLoc, 1, GL_FALSE, glm::value_ptr( view ) );
    glUniformMatrix4fv( projLoc, 1, GL_FALSE, glm::value_ptr(scene.m_camera.projection ) );
    model = glm::mat4(1);
    model = glm::translate( model, scene.m_light.getPos());
    model = glm::scale( model, glm::vec3( 0.2f ) ); // Make it a smaller cube
    model = glm::translate(model, glm::vec3(scene.m_light.position.x, scene.m_light.position.y, scene.m_light.position.z));
    glUniformMatrix4fv( modelLoc, 1, GL_FALSE, glm::value_ptr( model ) );
    
    glBindVertexArray( scene.m_cube.lightVAO );
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawArrays( GL_TRIANGLES, 0, 36 );
    glBindVertexArray( 0 );
}

void RendererManager::drawGUI(GLFWwindow *window, ImGuiManager imGui, Scene scene) {
    /* Render ImGui On Frame */
    imGui.beginFrame(window);
    imGui.drawWindow(scene.m_cube.position, scene.m_cube.rotation, scene.m_cube.color, scene.m_light.position, scene.m_light.color, scene.clearColor, m_cameraPosition.m_position, m_cameraPosition.m_yaw, m_cameraPosition.m_pitch);
    scene.m_camera.setPosition(glm::vec3(0.0f, 0.0f,0.0f));
    imGui.endFrame();
    scene.m_camera.setPosition(glm::vec3((m_cameraPosition.m_position.x - scene.m_camera.getPosition().x), (m_cameraPosition.m_position.y - scene.m_camera.getPosition().y), (m_cameraPosition.m_position.z - scene.m_camera.getPosition().z)));
    scene.m_camera.setYaw((m_cameraPosition.m_yaw - scene.m_camera.getYaw()));
    scene.m_camera.setPitch((m_cameraPosition.m_pitch - scene.m_camera.getPitch()));
}

void RendererManager::cleanup(GLFWwindow *window) {
    glfwPollEvents();
    glfwSwapBuffers(window);
}
