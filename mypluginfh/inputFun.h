#pragma once

#include "pch.h"
#include "mypluginfh.h"
#define  M_PI_4 (3.14159265358979323846f / 4);

bool SliderAngle_rl(const char* label, float* v_rad, float v_default);

int output_position(int value, const char* label);