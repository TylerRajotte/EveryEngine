#ifndef Settings_H
#define Settings_H

#include "dependancies.h"

class SettingsLoader{
    public:
        bool LoadSettings(std::string Location);

        std::string WindowName;
        int WindowXSize;
        int WindowYSize;
        int WindowXPos;
        int WindowYPos;
        bool EnableVsync;
        std::string GameObjectsLocation;
};

#endif