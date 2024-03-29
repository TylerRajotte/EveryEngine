#ifndef GameObject_H
#define GameObject_H
#include "dependancies.h"
#include "Render/shader.h"
#include "Render/modelloader.h"

class GameObject{
    public:
        bool Init(int NewID);
        void RenderObject();
        // This function would then later be called by the object manager
        void Update();

        void SetArrayAttribute(int Attribute, int NewValue[3]);
        int* GetArrayAttribute(int Attribute);

        void SetName(std::string NewName);
        std::string GetName();

        int GetID();

    private:
        int ID;
        std::string Name;
        int Pos[3];
        int Scale[3];
        int Rotation[3];
        int RotationOrigin[3];

        unsigned int VBO;
        unsigned int EBO;
        unsigned int VAO;

        int PointCount;

        Shader* shader = nullptr;
};

#endif