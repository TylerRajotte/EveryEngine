#include "modelloader.h"
#include "../dependancies.h"

std::array<int,3> ModelLoader::ParseModelLine(std::string Line){
    


    std::array<int, 3> finaloutput = {0, 0, 0};
    return finaloutput;
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
                case 'v': {
                    // Add a vert
                    std::array<int, 3> FormatedVert = ParseModelLine(CurrentLine);
                    for(int i = 0; i < 2; i++){
                        Vertices.push_back(FormatedVert[i]);
                    }
                    std::cout << "Loaded Vertex - " << CurrentLine << std::endl;
                    break;
                }
                case 'f': {
                    // Add a Face
                    std::array<int, 3> FormatedIndices = ParseModelLine(CurrentLine);
                    for(int i = 0; i < 2; i++){
                        Indices.push_back(FormatedIndices[i]);
                    }
                    std::cout << "Loaded Indice - " << CurrentLine << std::endl;
                }
                default: {
                    // Something else doesn't matter though
                    break;
                }
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