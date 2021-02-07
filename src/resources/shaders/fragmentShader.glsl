#version 330 core

out vec4 color;
in vec4 colorOut;
in vec2 textureOut;
in vec3 normalOut;
in vec3 fragPosition;

uniform sampler2D u_texture;
uniform vec3 u_viewPos;


void main(){
    vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);

    float ambientStrength = 0.1;
    float specularStrength = 0.7;
    float diffuseStrengh = 0.3;

    vec3 ambient = ambientStrength * lightColor;

    vec3 norm = normalize(normalOut);
    vec3 lightDir = normalize(vec3(0, 0, 0) - fragPosition);
    float diff = max(dot(norm, lightDir), 0.0);

    vec3 diffuse = diffuseStrengh * diff * lightColor;

    vec3 viewDir = normalize(u_viewPos - fragPosition);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;


     vec3 light = (ambient +diffuse+specular);
    //if(mod(floor(fragPosition.x),2)==0 && mod(floor(fragPosition.y),2)==0 && mod(floor(fragPosition.z),2)==0){
    //    color= vec4(0.0, 0.0, 1.0, 1.0);
   // }else{
        color= vec4(light, 1.0) * colorOut;//*texture(u_texture, textureOut);
 //   }

}