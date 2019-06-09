#ifndef ModelLoader_H
#define ModelLoader_H

class ModelLoader{
    public:
        bool OpenModel(int ID);
        int* ParseModelLine(std::string InputLine);
        int* GetVertices();
        int* GetIndices();

    private:
        std::vector<int*> VerticesVectorPointers;
        std::vector<int*> IndicesVectorPointers;
};
#endif