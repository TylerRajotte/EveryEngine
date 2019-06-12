#ifndef ModelLoader_H
#define ModelLoader_H

#include "../dependancies.h"

class ModelLoader{
    public:
        bool OpenModel(int ID);
        std::array<float,3> ParseModelLine(std::string Line);

        std::vector<float> GetVertices();
        std::vector<unsigned int> GetIndices();
        int VerticesLength();
        int IndicesLength();


    private:
        std::vector<float> Vertices;
        std::vector<unsigned int> Indices;
};
#endif