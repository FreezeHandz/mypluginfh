#pragma once

#include "pch.h"
#include "mypluginfh.h"
#define  M_PI_4 (3.14159265358979323846f / 4);
/*

input_fun: public BakkesMod::Plugin::PluginSettingsWindow {
public:
	bool SliderAngle_rl2(const char* label, float* v_rad, float v_default, int position = (-1));
};
*/

bool forte(const char *gio, float* v_rad, float v_default, int position = (-1));

void prova1();