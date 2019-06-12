#include "gameobject.h"

bool GameObject::Init(int NewID, std::string NewName, int NewPos[3], int NewScale[3], int NewRotation[3], int NewRotationOrigin[3]){
    // Basic input for the freshly created gameobject
    ID = NewID;
    Name = NewName;
    for(int i = 0; i < 3; i++){
        Pos[i] = NewPos[i];
        Scale[i] = NewScale[i];
        Rotation[i] = NewRotation[i];
        RotationOrigin[i] = NewRotationOrigin[i];
    }

    // Load the model
    ModelLoader* modelloader = nullptr;
    modelloader = new ModelLoader;
    if (modelloader->OpenModel(ID)){
        std::cout << "Loaded Model for Game Object - " << ID << std::endl;
    } else {
        return false;
    }

    // Start New shader
    shader = new Shader;
    if(shader->CompileShaders(ID)){
        std::cout << "Compiled shaders for Game Object " << ID << std::endl;
    } else {
        return false;
    }

    // Generate Buffers
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    // Bind VAO
    glBindVertexArray(VAO);

    // Inital raw data
    int VerticesSize = modelloader->VerticesLength();
    std::vector<float> VerticesVector = modelloader->GetVertices();

    int IndicesSize = modelloader->IndicesLength();
    std::vector<unsigned int> IndicesVector = modelloader->GetIndices();

    // Output Variables
    float vertices[VerticesSize];
    unsigned int indices[IndicesSize];
    
    // Converting from one data type to the next
    for(int i = 0; i < VerticesSize; i++){
        vertices[i] = VerticesVector.at(i);
    }
    for(int i = 0; i < IndicesSize; i++){
        indices[i] = IndicesVector.at(i);
    }

    // Setup the VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Setup the EBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Set Vertex Pointer atrributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Final Binds
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0);

    std::cout << "Created VBO, EBO and VAO for Game Object - " << ID << std::endl;

    return true;    
}

void GameObject::RenderObject(){
    // Render Code
    glUseProgram(shader->ShaderProgram);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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