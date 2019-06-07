#include "gameobject.h"

void GameObject::SetAttribute(int Attribute, int NewValue[3]){
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

int* GameObject::GetAttribute(int Attribute){
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