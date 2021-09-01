//
//  Scene.h
//  Trust
//
//  Created by Lincoln Scheer on 8/31/21.
//  Copyright © 2021 Lincoln Scheer. All rights reserved.
//

#ifndef Scene_h
#define Scene_h

#include "Mesh.hpp"
#include "Light.hpp"
#include "Camera.h"

class Scene {
public:
    Mesh m_cube;
    Light m_light;
    Camera m_camera;
    glm::vec4 clearColor = glm::vec4(0.0f, 0.5f, 0.5f, 1.0f);
    Scene(int width, int height) {
        m_camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
        m_camera.projection = glm::perspective(m_camera.getZoom(), (GLfloat) (width / height), 0.01f, 100.0f);
        
        m_light = Light(glm::vec3(1.2f, 1.0f, 2.0f));
        m_light.color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
        m_light.position = glm::vec3(0.0f, 0.0f, 0.0f);
        
        m_cube.loadCube();
        m_cube.position = glm::vec3(0.0f, 0.0f, 0.0f);
        m_cube.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
        m_cube.color = glm::vec4(0.2f, 0.2f, 0.2f, 1.0f);
    }
};

#endif /* Scene_h */
