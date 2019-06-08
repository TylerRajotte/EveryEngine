#include "gameobject.h"

void GameObject::Init(int NewID, std::string NewName, int NewPos[3], int NewScale[3], int NewRotation[3], int NewRotationOrigin[3]){
    // Basic input for the freshly created gameobject
    ID = NewID;
    Name = NewName;
    for(int i = 0; i < 3; i++){
        Pos[i] = NewPos[i];
        Scale[i] = NewScale[i];
        Rotation[i] = NewRotation[i];
        RotationOrigin[i] = NewRotationOrigin[i];
    }

    
}

void GameObject::SetArrayAttribute(int Attribute, int NewValue[3]){
    switch(Attribute){
        case 0:
            for(int i = 0; i < 3; i++){
                Pos[i] = NewValue[i];
            }
            break;

        case 1:
            for(int i = 0; i < 3; i++){
                Scale[i] = NewValue[i];
            }
            break;

        case 2:
            for(int i = 0; i < 3; i++){
                Rotation[i] = NewValue[i];
            }
            break;

        case 3:
            for(int i = 0; i < 3; i++){
                RotationOrigin[i] = NewValue[i];
            }
            break;
        
        default:
            std::cout << stderr << "Error Invaild Attribute" << std::endl;
            break;
    }
}

int* GameObject::GetArrayAttribute(int Attribute){
    switch(Attribute){
        case 0:
            return Pos;
            break;

        case 1:
            return Scale;
            break;

        case 2:
            return Rotation;
            break;

        case 3:
            return RotationOrigin;
            break;
        
        default:
            std::cout << stderr << "Error Invaild Attribute" << std::endl;
            break;
    }
}

void GameObject::SetName(std::string NewName){
    Name = NewName;
}
std::string GameObject::GetName(){
    return Name;
}

void GameObject::SetID(int NewId){
    ID = NewId;
}
int GameObject::GetID(){
    return ID;
}