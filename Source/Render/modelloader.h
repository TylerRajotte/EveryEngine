#ifndef ModelLoader_H
#define ModelLoader_H

#include "../dependancies.h"

class ModelLoader{
    public:
        bool OpenModel(int ID);
        std::array<int,3> ParseModelLine(std::string Line);
        int* GetVertices();
        int* GetIndices();

    private:
        std::vector<int> Vertices;
        std::vector<int> Indices;
};
#endif