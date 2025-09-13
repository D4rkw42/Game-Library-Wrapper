#version 330 core

layout (location = 0) in vec3 aPos;

out vec4 color;

out vec3 pos;
out float border;
out float diameter;

uniform mat4 projection;
uniform mat4 model;

uniform vec4 aColor;

uniform float aBorder;
uniform float aDiameter;

void main() {
    gl_Position = projection * model * vec4(aPos, 1.0f);

    color = aColor;

    pos = aPos;
    border = aBorder;
    diameter = aDiameter;
}