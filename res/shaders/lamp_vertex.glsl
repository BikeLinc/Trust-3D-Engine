#version 330 core
layout (location = 0) in vec3 position;

uniform mat4 model; // Converts Local Obj Coords To Camera Coords
uniform mat4 view; // Converts To Window Coords
uniform mat4 projection; // Converts To Normalized Coods

void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0f);
}
