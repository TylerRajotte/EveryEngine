#include "modelloader.h"
#include "../dependancies.h"

bool ModelLoader::OpenModel(int ID){
    std::ofstream ModelFile;
    std::string RawData;
    std::stringstream IDAsStringStream;
    IDAsStringStream << ID;
    std::string ModelDataLine;

    ModelFile.open(GameObjectsLocation + IDAsStringStream.str() + "/model.obj", std::ios::in);
    if(ModelFile.is_open()){
        
    } else {
        std::cout << stderr << " Error: Unable to open model for ID - " << IDAsStringStream.str() << std::endl;
        return false;
    }

    ModelFile.close();

    return true;
}