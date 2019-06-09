#ifndef Dependancies_H
#define Dependancies_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <vector>
#include <array>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "Render/math_3d.h"

const int GO_POS = 0;
const int GO_SCALE = 1;
const int GO_ROTATION = 2;
const int GO_ROTATIONORIGIN = 3;
const int GO_ID = 4;
const int GO_NAME = 5;

// Temp setting should eventually use Settings.txt
const std::string GameObjectsLocation = "GameObjects/";

#endif