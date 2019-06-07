#include "gameobject.h"

// Might make sense to change these out for a update attribute function than many of these
// Yeah after having a second look that would probably be the better idea in the long run

void GameObject::SetPos(int NewPos[3]){
    for(int i = 0; i < 3; i++){
        Pos[i] = NewPos[i];
    }
}
int* GameObject::GetPos(){
    return Pos;
}

void GameObject::SetScale(int NewScale[3]){
    for(int i = 0; i < 3; i++){
        Scale[i] = NewScale[i];
    }
}
int* GameObject::GetScale(){
    return Scale;
}

void GameObject::SetRot(int NewRot[3]){
    for(int i = 0; i < 3; i++){
        Rotation[i] = NewRot[i];
    }
}

int* GameObject::GetRot(){
    return Rotation;
}

void GameObject::SetRotOrigin(int NewRotOrigin[3]){
    for(int i = 0; i < 3; i++){
        RotationOrigin[i] = NewRotOrigin[i];
    }
}
int* GameObject::GetRotOrigin(){
    return RotationOrigin;
}