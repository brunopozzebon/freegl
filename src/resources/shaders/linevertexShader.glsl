#version 330 core

layout(location=0) in vec3 position;
layout(location=1) in vec4 colorIn;

out vec4 colorOut;

uniform mat4 u_VP;

void main(){
    gl_Position= u_VP  * vec4(position, 1.0);
    colorOut = colorIn;
}