#version 330 core

struct Light{
    vec3 color;
    vec3 position;
};

struct Material{
    vec3 ambient_intensity;
    vec3 diffuse_intensity;
    vec3 specular_intensity;
    float shininess;
};

uniform Material u_material;

out vec4 result;
in vec2 text;
in vec3 normal;
in vec3 fragPosition;

uniform sampler2D u_texture;
uniform vec3 u_camera_position;
uniform Light u_light;

void main(){
    vec3 ambientLight = u_material.ambient_intensity * u_light.color;

    vec3 normalDirection = normalize(normal);
    vec3 lightDir = normalize(u_light.position - fragPosition);

    float diff = max(dot(normalDirection, lightDir), 0.0);

    vec3 diffuseLight = u_material.diffuse_intensity * diff * u_light.color;

    vec3 viewDir = normalize(u_camera_position - fragPosition);
    vec3 reflectDir = reflect(-lightDir, normalDirection);

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), u_material.shininess);
    vec3 specularLight = u_material.specular_intensity * spec * u_light.color;

    vec3 light = (ambientLight + diffuseLight + specularLight);
    result = vec4(light, 1.0)*texture(u_texture, text);
}