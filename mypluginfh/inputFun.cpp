#include "pch.h"
#include "inputFun.h"

float rangePI(float value,float start, float end) {
	if (value > start && value < end)
		return end;
	return -1;
}

bool SliderAngle_rl(const char* label, float* v_rad, float v_default) {

	bool ret = ImGui::SliderAngle(label, v_rad, 0.0f, 360.0f);
	if (ImGui::BeginPopupContextItem(label))
	{
		char buf[64];
		sprintf(buf, "Reset to %.f", v_default);

		if (ImGui::MenuItem(buf))
			*v_rad = v_default;
		ImGui::EndPopup();
	}
	float pi4 = M_PI_4;
	for (int n = 0; n < 8; n++) {
		float k = rangePI(*v_rad, pi4 * n, pi4 * (n + 1));
		if (k != -1)
			*v_rad = k;
	}
	return ret;
}



int output_position(int value, const char* label) {
	const char* items[] = { "Position 0", "Position 1", "Position 2", "Position 3", "Position 4", "Position 5", "Position 6", "Position 7" };
	const char* combo_preview_value = items[value];
	if (ImGui::BeginCombo(label, combo_preview_value))
	{
		for (int n = 0; n < IM_ARRAYSIZE(items); n++)
		{
			const bool is_selected = (value == n);
			if (ImGui::Selectable(items[n], is_selected))
				value = n;

			// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
			if (is_selected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndCombo();
	}
	return value;
}
