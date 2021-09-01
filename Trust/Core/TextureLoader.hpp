//
//  TextureLoader.hpp
//  GLFW_OpenGL
//
//  Created by Lincoln Scheer on 3/26/21.
//  Copyright © 2021 Lincoln Scheer. All rights reserved.
//

#ifndef TextureLoader_hpp
#define TextureLoader_hpp

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "SOIL2.h"

class TextureLoader {
public:
    GLuint texture;
    TextureLoader();
private:
    GLuint loadTexture();
    
};

#endif /* TextureLoader_hpp */
