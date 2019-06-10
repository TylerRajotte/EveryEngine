#ifndef ModelLoader_H
#define ModelLoader_H

#include "../dependancies.h"

class ModelLoader{
    public:
        bool OpenModel(int ID);
        std::array<float,3> ParseModelLine(std::string Line);
        float* GetVertices();
        unsigned int* GetIndices();

    private:
        std::vector<float> Vertices;
        std::vector<int> Indices;
};
#endif