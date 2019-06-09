#include "modelloader.h"
#include "../dependancies.h"

int* ModelLoader::ParseModelLine(std::string InputLine){
    int final[3] = {0, 0, 0};
    return final;
}

bool ModelLoader::OpenModel(int ID){
    // Inital Setup Variables for converting ints to strings and finding the Model Location
    std::stringstream IDAsStringStream;
    IDAsStringStream << ID;
    std::string FileLocation = GameObjectsLocation + IDAsStringStream.str() + "/model.obj";

    // Opening the Model File
    std::ifstream ModelFile(FileLocation.c_str());

    // Check if it actually worked
    if(ModelFile.is_open()){
        std::string CurrentLine;
        // Go through all the lines
        while(getline(ModelFile, CurrentLine)){
            // Switch for the first letter
            switch (CurrentLine.front()){
                case 'v':
                    // Add a vert
                    int* FormatedVert = ParseModelLine(CurrentLine);
                    VerticesVectorPointers.resize(VerticesVectorPointers.size() + 1);
                    VerticesVectorPointers.push_back(FormatedVert);
                    std::cout << "Loaded Vertex - " << CurrentLine << std::endl;
                    break;
                case 'f':
                    // Add a Face
                    int* FormatedIndices = ParseModelLine(CurrentLine);
                    IndicesVectorPointers.resize(IndicesVectorPointers.size() + 1);
                    IndicesVectorPointers.push_back(FormatedIndices);
                    std::cout << "Loaded Indices - " << CurrentLine << std::endl;
                    break;
                default:
                    // Something else doesn't matter though
                    break;
            }
        }  
    } else {
        // If theres troubles opening the file
        std::cout << stderr << " Error: Unable to open model for ID - " << IDAsStringStream.str() << std::endl;
        ModelFile.close();
        return false;
    }
    // Wrap off the file and close it down as its not needed
    ModelFile.close();

    return true;
}