#version 330 core
layout (location = 0) in vec2 vertex; //vec 2 position, vec 2 texCoord
layout (location = 1) in  vec2 textuaCoord;

out vec2 TexCoords;

uniform mat4 model;
uniform mat4 projection;

void main(void)
{
    TexCoords = textuaCoord;
//    gl_Position = projection * model * vec4(vertex, 0.0, 1.0);
    gl_Position = vec4(vertex.x, vertex.y, 0.0, 1.0);
}
