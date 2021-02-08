//
// Created by bruno on 06/02/2021.
//

#ifndef FREEGL_NORMAL_H
#define FREEGL_NORMAL_H


#include <iterator>

class Normal {
private:
    float x;
    float y;
    float z;
public:
    Normal(float x, float y, float z);
    Normal();

    static Normal Back;
    static Normal Front;
    static Normal Top;
    static Normal Bottom;
    static Normal Right;
    static Normal Left;

    inline std::string toString(){
        return "\n\tx: "+ std::to_string(x) + "y: "+ std::to_string(y) + "z: "+ std::to_string(z);
    }
};


#endif //FREEGL_NORMAL_H
