#version 330 core

layout(location=0) in vec3 position;
layout(location=1) in vec4 colorIn;
layout(location=2) in vec2 textureIn;
out vec2 textureOut;

out vec4 colorOut;

uniform mat4 u_MVP;

void main(){
    gl_Position= u_MVP * vec4(position, 1.0);
    colorOut = colorIn;
    textureOut = textureIn;
}