/*
   Just include the basic Header Files needed across
   most of the Project's Classes.
*/

#pragma once

#include <stdint.h>
#include <math.h>
#include <cstdlib>
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <GL/gl.h>
#include <GL/glu.h>

#define SQR(N) ((N)*(N))

using namespace std;

//Conversion of Angles
inline double toDegrees(double radians){ return radians * 180.0f / 3.1415926535898; }
inline double toRadians(double degrees){ return degrees / 180.0f * 3.1415926535898; }
