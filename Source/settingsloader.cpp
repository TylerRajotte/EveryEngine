#include "settingsloader.h"

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
                std::vector<std::string> BrokenLine; 

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
                    BrokenLine.push_back(CleanedSection);
                }
                // All these if statements hurt my soul but this pretty much the only way
                if(BrokenLine[0] == "WindowName"){
                    WindowName = BrokenLine[1];
                } else if (BrokenLine[0] == "WindowXSize"){
                    WindowXSize = std::stoi(BrokenLine[1]);
                } else if (BrokenLine[0] == "WindowYSize"){
                    WindowYSize = std::stoi(BrokenLine[1]);
                } else if (BrokenLine[0] == "WindowXPos"){
                    // Check for special centered else just use the number
                    if (BrokenLine[1] == "CENTERED"){
                        WindowXPos = SDL_WINDOWPOS_CENTERED;
                    } else {
                        WindowXPos = std::stoi(BrokenLine[1]);
                    }
                } else if (BrokenLine[0] == "WindowYPos"){
                    // Check for special centered else just use the number
                    if (BrokenLine[1] == "CENTERED"){
                        WindowYPos = SDL_WINDOWPOS_CENTERED;
                    } else {
                        WindowYPos = std::stoi(BrokenLine[1]);
                    }
                } else if (BrokenLine[0] == "EnableVsync"){
                    // Enable bool support in the text file
                    if (BrokenLine[1] == "TRUE"){
                        EnableVsync = true;
                    } else if (BrokenLine[1] == "FALSE") {
                        EnableVsync = false;
                    } else {
                        std::cout << stderr << " Error: Invalid Vsync settting" << std::endl;
                        return false;
                    }
                } else {
                    std::cout << stderr << " Error: Invalid setting specified" << std::endl;
                    return false;
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