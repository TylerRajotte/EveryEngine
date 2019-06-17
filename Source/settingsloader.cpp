#include "settingsloader.h"

// std::vector<std::string> split(std::string strToSplit, char delimeter)
// {
//     std::stringstream ss(strToSplit);
//     std::string item;
//     std::vector<std::string> splittedStrings;
//     while (std::getline(ss, item, delimeter))
//     {
//        splittedStrings.push_back(item);
//     }
//     return splittedStrings;
// }

bool SettingsLoader::LoadSettings(std::string Location){
    // Open File
    std::ifstream SettingsFile(Location.c_str());
    // Check if its open
    if(SettingsFile.is_open()){
        std::string Line;
        // Go through each line
        while(getline(SettingsFile, Line)){
            // Check for blank lines and lines with spaces on them
            if((Line == "") || (Line == " ")){
                continue;
            // Check for comment and remove
            } else if(Line.substr(0, 2) == "//"){
                continue;
            } else {
                // Should only have good data by now
                std::stringstream LineStream(Line);
                std::string Section;

                // Delimit around = 
                while(getline(LineStream, Section, '=')){
                    // Remove spaces before and after terms if there actually there
                    std::string CleanedSection;
                    if(Section.front() == ' '){
                        CleanedSection = Section.substr(1);
                    } else if (Section.back() == ' '){
                        CleanedSection = Section.substr(0, Section.length() - 1);
                    } else {
                        CleanedSection = Section;
                    }
                    
                    std::cout << CleanedSection << std::endl;
                }
            }
        }
    } else {
        // Error Occured
        std::cout << stderr << " Error Opening Settings File" << std::endl;
        SettingsFile.close();
        return false;
    }
    // Close out of file
    SettingsFile.close();

    return true;
}