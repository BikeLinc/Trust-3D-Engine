//
//  Light.hpp
//  Trust
//
//  Created by Lincoln Scheer on 8/26/21.
//  Copyright © 2021 Lincoln Scheer. All rights reserved.
//

#ifndef Light_hpp
#define Light_hpp

#include <glm/glm.hpp>
#include "Mesh.hpp"

class Light {
public:
    glm::vec3 position;
    glm::vec4 color;
    Light();
    Light(glm::vec3 pos);
    glm::vec3 getPos();
    void setPos(float x, float y, float z);
};

#endif /* Light_hpp */
