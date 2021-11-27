R"(
#version 330 core
in vec4 vs_color;

out vec4 fs_fragColor;

void main()
{
    fs_fragColor = vs_color;
} 
)"