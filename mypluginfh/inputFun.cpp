#include "pch.h"
#include "inputFun.h"
/*
bool input_fun::SliderAngle_rl2(const char* label, float* v_rad, float v_default, int position = (-1)) {

	bool ret = ImGui::SliderAngle(label, v_rad, 0.0f, 360.0f);
	if (ImGui::BeginPopupContextItem(label))
	{
		char buf[64];
		sprintf(buf, "Reset to %.f", v_default);

		if (ImGui::MenuItem(buf))
			*v_rad = v_default;
		ImGui::EndPopup();
	}
	if (position != -1) {
		*v_rad = position * M_PI_4;
	}
	return ret;



}
*/
bool forte(const char* label, float* v_rad, float v_default, int position) {

	bool ret = ImGui::SliderAngle(label, v_rad, 0.0f, 360.0f);
	if (ImGui::BeginPopupContextItem(label))
	{
		char buf[64];
		sprintf(buf, "Reset to %.f", v_default);

		if (ImGui::MenuItem(buf))
			*v_rad = v_default;
		ImGui::EndPopup();
	}
	if (position != -1) {
		*v_rad = position * M_PI_4;
	}
	return ret;
}


void prova1() {
	ImGui::Text("oke?");
}