//
//  Light.cpp
//  Trust
//
//  Created by Lincoln Scheer on 8/26/21.
//  Copyright © 2021 Lincoln Scheer. All rights reserved.
//

#include "Light.hpp"

glm::vec3 lightPos;

Light::Light() {
    lightPos = glm::vec3(0.0f,0.0f,0.0f);
}

Light::Light(glm::vec3 pos) {
    lightPos = pos;
}

glm::vec3 Light::getPos() {
    return lightPos;
}

void Light::setPos(float x, float y, float z) {
    lightPos = glm::vec3(x, y, z);
}

