#ifndef GameObject_H
#define GameObject_H
// Will later controll the ai, sound and interactivity
#include "dependancies.h"

class GameObject{
    public:
        void SetPos(int NewPos[3]);
        int* GetPos();
        void SetScale(int NewScale[3]);
        int* GetScale();
        void SetRot(int NewRot[3]);
        int* GetRot();
        void SetRotOrigin(int NewRotOrigin[3]);
        int* GetRotOrigin();

    private:
        int ID;
        std::string Name;
        int Pos[3];
        int Scale[3];
        int Rotation[3];
        int RotationOrigin[3];

};

#endif