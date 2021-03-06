#version 330 core

out vec4 color;

// Texture samplers
uniform sampler2D ourTexture1;

void main()
{
    // Linearly interpolate between both textures (second texture is only slightly combined)
    color = vec4(1.0f);
}
