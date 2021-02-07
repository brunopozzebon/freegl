#version 330 core

layout(location=0) in vec3 positionIn;
layout(location=1) in vec4 colorIn;
layout(location=2) in vec2 textureIn;
layout(location=3) in vec3 normalIn;

out vec2 text;
out vec4 color;
out vec3 normal;
out vec3 fragPosition;

uniform mat4 u_view;
uniform mat4 u_projection;
uniform mat4 u_model;

void main(){
    gl_Position= u_projection * u_view * u_model * vec4(positionIn, 1.0);
    color = colorIn;
    text = textureIn;
    normal = mat3(transpose(inverse(u_model))) * normalIn;
    fragPosition = vec3(u_model * vec4(positionIn, 1.0));
}