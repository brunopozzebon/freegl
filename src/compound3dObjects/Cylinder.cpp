//
// Created by bruno on 07/02/2021.
//

#include "Cylinder.h"

Cylinder::Cylinder(Position position, float ray, float height, float lateralFaces, Material material) :
 Prism(position, ray*2, ray*2, height, lateralFaces, 48, material){

}
