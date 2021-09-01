//
//  Mesh.hpp
//  Trust
//
//  Created by Lincoln Scheer on 8/26/21.
//  Copyright © 2021 Lincoln Scheer. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include <GL/glew.h>
#include <glm/glm.hpp>

class Mesh {
public:
    GLuint VBO;
    GLuint VAO;
    GLuint cubeVAO, lightVAO;
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
    glm::vec4 color;
    void loadMeshFromVertices();
    void loadMeshFromVerticesWithoutNormals();
    void loadCube();
};

#endif /* Might_hpp */
