#version 330 core

out vec4 color;
in vec4 colorOut;
in vec2 textureOut;

uniform sampler2D u_texture;

void main(){
    color=colorOut*texture(u_texture, textureOut);
}