#ifndef GameObject_H
#define GameObject_H
#include "dependancies.h"

const int GO_POS = 0;
const int GO_SCALE = 1;
const int GO_ROTATION = 2;
const int GO_ROTATIONORIGIN = 3;
const int GO_ID = 4;
const int GO_NAME = 5;

class GameObject{
    public:
        void SetArrayAttribute(int Attribute, int NewValue[3]);
        int* GetArrayAttribute(int Attribute);

        void SetName(std::string NewName);
        std::string GetName();

        void SetID(int NewId);
        int GetID();

    private:
        int ID;
        std::string Name;
        int Pos[3];
        int Scale[3];
        int Rotation[3];
        int RotationOrigin[3];
};

#endif