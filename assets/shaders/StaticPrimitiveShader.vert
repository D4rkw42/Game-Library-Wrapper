#version 330 core

layout (location = 0) in vec3 aPos;

out vec4 color;

uniform mat4 projection;
uniform mat4 model;

uniform vec4 aColor;

void main() {
    gl_Position = projection * model * vec4(aPos, 1.0f);

    color = aColor;
}