#include "pch.h"
#include "inputFun.h"


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

bool buttons( float color, const char* name) {
	
	ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(color / 7.0f, 0.6f, 0.6f));
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(color / 7.0f, 0.7f, 0.7f));
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(color / 7.0f, 0.8f, 0.8f));
	bool bottun = ImGui::Button(name);
	ImGui::PopStyleColor(3);
	return bottun;
}

bool newslider(const char* label, int* pos) {
	enum Element { Element_0, Element_1, Element_2, Element_3, Element_4, Element_5, Element_6, Element_7, Element_8, Element_COUNT };
	const char* elems_names[Element_COUNT] = { "0 deg", "45 deg", "90 deg", "135 deg","180 deg","225 deg","270 deg","315 deg","360 deg" };
	const char* elem_name = (*pos >= 0 && *pos < Element_COUNT) ? elems_names[*pos] : "Unknown";
	bool ret = ImGui::SliderInt(label, pos, 0, Element_COUNT - 1, elem_name);
	return ret;
}

void lines() {
	ImGui::Text("");
	for (int k = 1; k < 9; k++) {
		ImGui::SameLine(k * 71);
		ImGui::Text("|");
	}
}