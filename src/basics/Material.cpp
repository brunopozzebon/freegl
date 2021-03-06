//
// Created by bruno on 12/02/2021.
//

#include "Material.h"

Material::Material(vec3 ambient, vec3 diffuse, vec3 specular, float shininess) {
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->shininess = shininess;
}

Material Material::Emerald = Material(
        vec3(0.0215, 0.1745, 0.0215),
        vec3(0.07568, 0.61424, 0.07568),
        vec3(0.633, 0.727811, 0.633),
        0.6f);

Material Material::Jade = Material(
        vec3(0.135, 0.2225, 0.1575),
        vec3(0.54, 0.89, 0.63),
        vec3(0.316228, 0.316228, 0.316228),
        0.1
);

Material Material::Obsidian = Material(
        vec3(0.05375, 0.05, 0.0662),
        vec3(0.18275, 0.17, 0.22525),
        vec3(0.332741, 0.328634, .346435),
        0.3
);

Material Material::Pearl = Material(
        vec3(0.25, 0.20725, 0.20725),
        vec3(1, 0.829, 0.829),
        vec3(0.296648, 0.296648, 0.296648),
        0.088
);

Material Material::Ruby = Material(
        vec3(0.1745, 0.01175, 0.01175),
        vec3(0.61424, 0.04136, 0.04136),
        vec3(0.727811, 0.626959, 0.626959),
        0.6
);

Material Material::Turquoise = Material(
        vec3(0.1, 0.18725, 0.1745),
        vec3(0.396, 0.74151, 0.69102),
        vec3(0.297254, 0.30829, 0.306678),
        0.1
);

Material Material::Brass = Material(
        vec3(0.329412, 0.223529, 0.027451),
        vec3(0.780392, 0.568627, 0.113725),
        vec3(0.992157, 0.941176, 0.807843),
        0.21794872
);

Material Material::Bronze = Material(
        vec3(0.2125, 0.1275, 0.054),
        vec3(0.714, 0.4284, 0.18144),
        vec3(0.393548, 0.271906, 0.166721),
        0.2
);

Material Material::Chrome = Material(
        vec3(0.25, 0.25, 0.25),
        vec3(0.4, 0.4, 0.4),
        vec3(0.774597, 0.774597, 0.774597),
        0.6
);

Material Material::Copper = Material(
        vec3(0.19125, 0.0735, 0.0225),
        vec3(0.7038, 0.27048, 0.0828),
        vec3(0.256777, 0.137622, 0.086014),
        0.1
);

Material Material::Gold = Material(
        vec3(0.24725, 0.1995, 0.0745),
        vec3(0.75164, 0.60648, 0.22648),
        vec3(0.628281, 0.555802, 0.366065),
        0.4
);

Material Material::Silver = Material(
        vec3(0.19225, 0.19225, 0.19225),
        vec3(0.50754, 0.50754, 0.50754),
        vec3(0.508273, 0.508273, 0.508273),
        0.4
);

Material Material::Plastic = Material(
        vec3(0.0, 0.0, 0.0),
        vec3(0.55, 0.55, 0.55),
        vec3(0.70, 0.70, 0.70),
        .25
);

Material Material::Default = Material(
        vec3(0.3, 0.3, 0.3),
        vec3(0.90, 0.9, 0.9),
        vec3(0.6, 0.6, 0.6),
        100.0f

);