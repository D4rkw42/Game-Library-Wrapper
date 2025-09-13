#version 330 core

in vec4 color;

in vec3 pos;
in float border;
in float diameter;

out vec4 FragColor;

void main() {
    float dist = length(pos.xy);

    float percent = border / (diameter/2);
    float limit = 0.5 - 0.5 * percent;

    if (dist <= 0.5 && dist >= limit) {
        FragColor = color;
    } else {
        discard;
    }
}