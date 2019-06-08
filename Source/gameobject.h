#ifndef GameObject_H
#define GameObject_H
#include "dependancies.h"

class GameObject{
    public:
        void Init(int ID, std::string Name, int Pos[3], int Scale[3], int Rotation[3], int RotationOrigin[3]);
        // This function would then later be called by the object manager
        void Update();

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