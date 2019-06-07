#ifndef GameObject_H
#define GameObject_H
// Will later controll the ai, sound and interactivity
#include "dependancies.h"

const int GO_POS = 0;
const int GO_SCALE = 1;
const int GO_ROTATION = 2;
const int GO_ROTATIONORIGIN = 3;

class GameObject{
    public:
        void SetAttribute(int Attribute, int NewValue[3]);
        int* GetAttribute(int Attribute);

    private:
        int ID;
        std::string Name;
        int Pos[3];
        int Scale[3];
        int Rotation[3];
        int RotationOrigin[3];

};

#endif