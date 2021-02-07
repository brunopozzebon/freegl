#version 330 core

struct Light{
    vec3 color;
    vec3 position;
};

out vec4 result;
in vec4 color;
in vec2 text;
in vec3 normal;
in vec3 fragPosition;

uniform sampler2D u_texture;
uniform vec3 u_camera_position;
uniform Light u_light;

const float AMBIENT_INTENSITY = 0.1;
const float SPECULAR_INTENSITY = 0.7;
const float DIFFUSE_INTENSITY = 0.5;

void main(){
    vec3 ambientLight = AMBIENT_INTENSITY * u_light.color;

    vec3 normalDirection = normalize(normal);
    vec3 lightDir = normalize(u_light.position - fragPosition);

    float diff = max(dot(normalDirection, lightDir), 0.0);

    vec3 diffuseLight = DIFFUSE_INTENSITY * diff * u_light.color;

    vec3 viewDir = normalize(u_camera_position - fragPosition);
    vec3 reflectDir = reflect(-lightDir, normalDirection);

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specularLight = SPECULAR_INTENSITY * spec * u_light.color;

    vec3 light = (ambientLight + diffuseLight + specularLight);
    result = (vec4(light, 1.0) * color)*texture(u_texture, text);
}