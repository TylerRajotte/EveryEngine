#ifndef Dependancies_H
#define Dependancies_H

#include <iostream> // Cout
#include <fstream> // FileIO
#include <string.h> // Strings
#include <sstream> // Convert string to floats in modelloader
#include <vector> // When c arrays give you a headack
#include <array> // When c arrays give you a headack part 2 (I think they might be faster/efficent)
#include <algorithm> // Find the smallest and bigest values 
#include <GL/glew.h>
#include <SDL2/SDL.h>

// For specificing attributes without having to know the codes
const int GO_POS = 0;
const int GO_SCALE = 1;
const int GO_ROTATION = 2;
const int GO_ROTATIONORIGIN = 3;
const int GO_ID = 4;
const int GO_NAME = 5;

// Temp settings that should eventually use Settings.txt
const std::string GameObjectsLocation = "GameObjects/";
const int windowXSize = 640;
const int windowYSize = 480;

#endif