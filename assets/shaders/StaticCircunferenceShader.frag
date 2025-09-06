#version 330 core

in vec4 color;
in vec3 circPos;

out vec4 FragColor;

void main() {
    float dist = length(circPos.xy);

    if (dist <= 0.5) {
        FragColor = color;
    } else {
        discard;
    }
}