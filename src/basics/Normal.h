//
// Created by bruno on 06/02/2021.
//

#ifndef FREEGL_NORMAL_H
#define FREEGL_NORMAL_H


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

};


#endif //FREEGL_NORMAL_H
