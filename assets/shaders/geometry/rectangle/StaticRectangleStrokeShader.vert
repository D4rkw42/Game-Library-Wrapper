#version 330 core

layout (location = 0) in vec3 aPos;

out vec4 color;
out vec3 pos;

out float width;
out float height;
out float border;

uniform mat4 projection;
uniform mat4 model;

uniform vec4 aColor;

uniform float aWidth;
uniform float aHeight;
uniform float aBorder;

void main() {
    gl_Position = projection * model * vec4(aPos, 1.0f);

    color = aColor;
    pos = aPos;

    width = aWidth;
    height = aHeight;
    border = aBorder;
}