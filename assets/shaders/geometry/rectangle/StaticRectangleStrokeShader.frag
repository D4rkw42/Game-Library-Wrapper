#version 330 core

in vec4 color;
in vec3 pos;

in float width;
in float height;
in float border;

out vec4 FragColor;

void main() {
    float distX = length(pos.x);
    float distY = length(pos.y);

    float percentW = border / (width/2);
    float percentH = border / (height/2);

    float limitW = 0.5 - 0.5 * percentW;
    float limitH = 0.5 - 0.5 * percentH;

    if (distX > limitW || distY > limitH) {
        FragColor = color;
    } else {
        discard;
    }
}