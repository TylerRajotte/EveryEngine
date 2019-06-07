#ifndef GameObject_H
#define GameObject_H

#include "dependancies.h"

class GameObject{
    public:
        void SetPos(int Pos[3]){};
        int GetPos();
        void SetScale();
        int GetScale();
    private:
        int ID;
        std::string Name;
        int Pos[3];
        int Scale[3];
        int Rotation[3];
        int RotationOrigin[3];

};

#endif