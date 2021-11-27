R"(
#version 330 core
layout (location = 0) in vec3 in_pos;
layout (location = 1) in vec4 in_color;

out vec4 vs_color;

void main()
{
    vs_color = in_color;
    gl_Position = vec4(in_pos, 1.0);
}
)"