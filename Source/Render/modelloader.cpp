#include "modelloader.h"
#include "../dependancies.h"

std::array<float,3> ModelLoader::ParseModelLine(std::string Line){
    // Setup some variables
    std::array<float, 3> finaloutput;
    std::string Delimiter = " ";
    size_t pos;
    size_t floatconvertsize;

    // Run it once to get rid of the letter off the start
    pos = Line.find(Delimiter);
    Line.erase(0, pos + Delimiter.length());

    // Break the lines up on there spaces and add them to the output
    for(int i = 0; i < 3; i++){
        pos = Line.find(Delimiter);
        finaloutput[i] = std::stof(Line.substr(0, pos), &floatconvertsize);
        Line.erase(0, pos + Delimiter.length());
    }
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
                    std::array<float, 3> FormatedVert = ParseModelLine(CurrentLine);
                    for(int i = 0; i < 2; i++){
                        Vertices.push_back(FormatedVert[i]);
                    }
                    std::cout << "Loaded Vertex - " << FormatedVert[0] << " " << FormatedVert[1] << " " << FormatedVert[2] << std::endl;
                    break;
                }
                case 'f': {
                    // Add a Face
                    std::array<float, 3> FormatedIndices = ParseModelLine(CurrentLine);
                    for(int i = 0; i < 2; i++){
                        Indices.push_back(int(FormatedIndices[i]));
                    }
                    std::cout << "Loaded Indice - " << FormatedIndices[0] << " " << FormatedIndices[1] << " " << FormatedIndices[2] << " "<< std::endl;
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

std::vector<float>* ModelLoader::GetVertices(){
    for(int i; i < Vertices.size(); i++){
        std::cout << Vertices[i] << std::endl;
    }
    return &Vertices;
}

std::vector<int>* ModelLoader::GetIndices(){
    return &Indices;
}