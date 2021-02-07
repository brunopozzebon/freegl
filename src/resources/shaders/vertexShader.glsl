#version 330 core

layout(location=0) in vec3 position;
layout(location=1) in vec4 colorIn;
layout(location=2) in vec2 textureIn;
layout(location=3) in vec3 normal;

out vec2 textureOut;
out vec4 colorOut;
out vec3 normalOut;
out vec3 fragPosition;

uniform mat4 u_VP;
uniform mat4 u_model;

void main(){
    gl_Position= u_VP * u_model * vec4(position, 1.0);
    colorOut = colorIn;
    textureOut = textureIn;
    //normalOut = normal;
    normalOut = mat3(transpose(inverse(u_model))) * normal;
    fragPosition = vec3(u_model * vec4(position, 1.0));
}