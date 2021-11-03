#include "pch.h"
#include "mypluginfh.h"
#define M_PI_4 (3.14159265358979323846 / 4)

// Plugin Settings Window code here
std::string mypluginfh::GetPluginName() {
	return "mypluginfh";
}

void mypluginfh::SetImGuiContext(uintptr_t ctx) {
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

bool SliderAngle_rl(const char* label, float* v_rad, float v_default, int position = (-1)) {

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
		*v_rad = position *M_PI_4;
	}
	return ret;
}

// Render the plugin settings here
// This will show up in bakkesmod when the plugin is loaded at
//  f2 -> plugins -> mypluginfh
void mypluginfh::RenderSettings() {
	//Enable plugin
	static bool check_plug = false;
	ImGui::Checkbox("Enable", &check_plug); ImGui::SameLine();
	static int item_current_1 = 0;
	ImGui::Combo("Plugin", &item_current_1, "Freeplay\0Local Private match");
	ImGui::NewLine();
	//Enable air steer
	static bool check_steer = false;
	ImGui::Checkbox("Enable", &check_steer); ImGui::SameLine();
	static int item_current_2 = 0;
	ImGui::Combo("Air steer", &item_current_2, "Left\0Right");

	//enable air pitch
	static bool check_pitch = false;
	ImGui::Checkbox("Enable", &check_pitch); ImGui::SameLine();
	static int item_current_3 = 0;
	ImGui::Combo("Air pitch", &item_current_3, "Up\0Down");

	//enable air roll
	static bool check_roll = false;
	ImGui::Checkbox("Enable", &check_roll); ImGui::SameLine();
	static int item_current_4 = 0;
	ImGui::Combo("Air roll", &item_current_4, "Left\0Right");

	ImGui::NewLine();
	ImGui::Separator();
	ImGui::NewLine();
	ImGui::Text("Car Orientation"); ImGui::SameLine();
	
	if (ImGui::Button("Reset")){}

	const char* items[] = { "Position 0", "Position 1", "Position 2", "Position 3", "Position 4", "Position 5", "Position 6", "Position 7"};
	static int roll_pos = 0; // Here we store our selection data as an index.
	static int pitch_pos = 0;
	static int steer_pos = 0;
	const char* combo_preview_value_roll = items[roll_pos];  // Pass in the preview value visible before opening the combo (it could be anything)
	const char* combo_preview_value_pitch = items[pitch_pos];
	const char* combo_preview_value_steer = items[steer_pos];
	
	if (ImGui::BeginCombo("Steer", combo_preview_value_steer))
	{
		for (int n = 0; n < IM_ARRAYSIZE(items); n++)
		{
			const bool is_selected = (steer_pos == n);
			if (ImGui::Selectable(items[n], is_selected))
				steer_pos = n;

			// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
			if (is_selected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndCombo();
	} 
	if (ImGui::BeginCombo("Pitch", combo_preview_value_pitch))
	{
		for (int n = 0; n < IM_ARRAYSIZE(items); n++)
		{
			const bool is_selected = (pitch_pos == n);
			if (ImGui::Selectable(items[n], is_selected))
				pitch_pos = n;

			// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
			if (is_selected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndCombo();
	}
	if (ImGui::BeginCombo("Roll", combo_preview_value_roll))
	{
		for (int n = 0; n < IM_ARRAYSIZE(items); n++)
		{
			const bool is_selected = (roll_pos == n);
			if (ImGui::Selectable(items[n], is_selected))
				roll_pos = n;

			// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
			if (is_selected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndCombo();
	}
	//MANUAL
	ImGui::Text("Manual Car Orientation");
	static float angle_steer = 0.0f;
	static float angle_pitch = 0.0f;
	//ImGui::SliderAngle("Pitch axis", &angle_pitch, 0.0f, 360.0f);
	static float angle_roll = 0.0f;
	
	
	ImGui::NewLine();
	ImGui::NewLine();
	SliderAngle_rl("Steer axis", &angle_steer, 0.0f);
	SliderAngle_rl("Pitch axis", &angle_pitch, 0.0f, pitch_pos);
	SliderAngle_rl("Roll axis", &angle_roll, 0.0f, roll_pos);
	ImGui::Text("Steer deg=%f", angle_steer);

	//SliderFloatDefault("okey",&angle_roll,0.0f,6.28f,3.0f);
	
}




/*
// Do ImGui rendering here
void mypluginfh::Render()
{
	if (!ImGui::Begin(menuTitle_.c_str(), &isWindowOpen_, ImGuiWindowFlags_None))
	{
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}

	ImGui::End();

	if (!isWindowOpen_)
	{
		cvarManager->executeCommand("togglemenu " + GetMenuName());
	}
}

// Name of the menu that is used to toggle the window.
std::string mypluginfh::GetMenuName()
{
	return "mypluginfh";
}

// Title to give the menu
std::string mypluginfh::GetMenuTitle()
{
	return menuTitle_;
}

// Don't call this yourself, BM will call this function with a pointer to the current ImGui context
void mypluginfh::SetImGuiContext(uintptr_t ctx)
{
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

// Should events such as mouse clicks/key inputs be blocked so they won't reach the game
bool mypluginfh::ShouldBlockInput()
{
	return ImGui::GetIO().WantCaptureMouse || ImGui::GetIO().WantCaptureKeyboard;
}

// Return true if window should be interactive
bool mypluginfh::IsActiveOverlay()
{
	return true;
}

// Called when window is opened
void mypluginfh::OnOpen()
{
	isWindowOpen_ = true;
}

// Called when window is closed
void mypluginfh::OnClose()
{
	isWindowOpen_ = false;
}
*/
