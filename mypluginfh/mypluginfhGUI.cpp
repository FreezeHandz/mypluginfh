#include "pch.h"
#include "mypluginfh.h"
#include "inputFun.h"


// Plugin Settings Window code here
std::string mypluginfh::GetPluginName() {
	return "mypluginfh";
}

void mypluginfh::SetImGuiContext(uintptr_t ctx) {
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}




// Render the plugin settings here
// This will show up in bakkesmod when the plugin is loaded at
//  f2 -> plugins -> mypluginfh
void mypluginfh::RenderSettings() {
	//Enable plugin
	static bool check_plug = false;
	ImGui::Checkbox("Enable plugin", &check_plug); ImGui::SameLine();
	static int item_current_1 = 0;
	ImGui::PushItemWidth(170);
	ImGui::Combo("##choose", &item_current_1, "Freeplay\0Local Private match");
	ImGui::NewLine();
	ImGui::PopItemWidth();
	//Enable air steer
	static bool check_steer = false;
	ImGui::Checkbox("Enable Air steer", &check_steer); ImGui::SameLine();
	
	static int item_current_2 = 0;
	
	ImGui::RadioButton("Left##1", &item_current_2, 0); ImGui::SameLine();
	ImGui::RadioButton("Right##1", &item_current_2, 1);
	

	//enable air pitch
	static bool check_pitch = false;
	ImGui::Checkbox("Enable Air pitch", &check_pitch); ImGui::SameLine();
	static int item_current_3 = 0;
	ImGui::RadioButton("Up", &item_current_3, 0); ImGui::SameLine(173);
	ImGui::RadioButton("Down", &item_current_3, 1);

	//enable air roll
	static bool check_roll = false;
	ImGui::Checkbox("Enable Air roll", &check_roll); ImGui::SameLine(120);
	static int item_current_4 = 0;
	ImGui::RadioButton("Left##2", &item_current_4, 0); ImGui::SameLine();
	ImGui::RadioButton("Right##2", &item_current_4, 1);


	static int angle_steer = 0;
	static int angle_pitch = 0;
	static int angle_roll = 0;
	ImGui::NewLine();
	ImGui::Separator();
	ImGui::Text("Initial Car Orientations"); ImGui::SameLine();
	if (ImGui::SmallButton("Reset")) {
		angle_steer = 0;
		angle_pitch = 0;
		angle_roll = 0;
	}
	ImGui::SameLine(0,50);
	if (ImGui::SmallButton("Reset last orientation")) {
		
	}	
	
	newslider("Steer axis", &angle_steer);
	lines();
	newslider("Pitch axis", &angle_pitch);
	lines();
	newslider("Roll axis", &angle_roll);

	static bool check_manual_or = false;
	ImGui::NewLine();
	ImGui::Checkbox("Enable Manual Car Orientation", &check_manual_or);
	static float add_angle_steer = 0.0f;
	static float add_angle_pitch = 0.0f;
	static float add_angle_roll = 0.0f;
	ImGui::SliderAngle("Add to steer axis", &add_angle_steer, 0.0f, 360.0f);
	ImGui::SliderAngle("Add to pitch axis", &add_angle_pitch, 0.0f, 360.0f);
	ImGui::SliderAngle("Add to roll axis", &add_angle_roll, 0.0f, 360.0f);

	ImGui::NewLine();
	ImGui::Separator();
	ImGui::Text("Macro timeout");
	static int timeout = 0;
	static int max_sec = 30;
	ImGui::SliderInt("##timeout", &timeout, -1, max_sec, "%d sec");
	ImGui::NewLine(); ImGui::SameLine(406);
	ImGui::Text("Change range");	ImGui::SameLine();
	ImGui::PushItemWidth(100);
	ImGui::InputInt("seconds", &max_sec);


	buttons(2.26893f, "Start");
	ImGui::SameLine();
	buttons(0.10472f, "Stop");
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
