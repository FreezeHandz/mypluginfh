#pragma once

#include "pch.h"
#include "mypluginfh.h"
#define M_PI_4 (3.14159265358979323846f / 4);



int output_position(int value, const char* label);

bool buttons( float color, const char* name);

bool newslider(const char* label, int* pos);
void lines();