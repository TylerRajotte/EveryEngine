#ifndef ModelLoader_H
#define ModelLoader_H

class ModelLoader{
    public:
        bool OpenModel(int ID);
        int* GetVertices();
        int* GetIndices();

    private:
        int* VerticesPointer;
        int* IndicesPointer;
};
#endif