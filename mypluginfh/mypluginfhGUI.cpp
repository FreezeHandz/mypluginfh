#include "pch.h"
#include "mypluginfh.h"
#include "inputFun.h"
//plugin developer = PG

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
	if (ImGui::Checkbox("Enable plugin", &check_plug)) {
		//PG
		// Start the plugin and set the ball and car location in the map
	}
	ImGui::SameLine();
	static int item_current_1 = 0;
	ImGui::PushItemWidth(170);

	if (ImGui::Combo("##choose", &item_current_1, "Freeplay\0Local Private match")) {
		//PG
		//If it's not possible to use the plugin in local private match, do nothing about it.
		//This drop menu will start the plugin in the displayed gamemode if it isn't there already
		//Options for private match: Time: no limit, Boost:unlimited
	}
	

	ImGui::NewLine();	ImGui::PopItemWidth();
	static bool check_steer = false;
	if (ImGui::Checkbox("Enable Air steer", &check_steer)) {
		//PG
		//Enable air steer for the macro
	}
	ImGui::SameLine();
	static int steerLoR = 0;
	
	//PG_0
	//I don't how to give these inputs to the plugin. I'll leave that to you.
	//However what I want is to change the direction of the axis
	//Examples: Left or right, Up or Down
	ImGui::RadioButton("Left##1", &steerLoR, 0);
	ImGui::SameLine();
	ImGui::RadioButton("Right##1", &steerLoR, 1);
	

	static bool check_pitch = false;
	if (ImGui::Checkbox("Enable Air pitch", &check_pitch)) {
		//PG
		//Enable air pitch for the macro
	}
	ImGui::SameLine();
	static int pitchDoU = 0;

	//PG_0
	ImGui::RadioButton("Up", &pitchDoU, 0); 
	ImGui::SameLine(173);
	ImGui::RadioButton("Down", &pitchDoU, 1);

	static bool check_roll = false;
	if (ImGui::Checkbox("Enable Air roll", &check_roll)) {
		//PG
		//Enable air roll for the macro
	}
	ImGui::SameLine(120);

	static int rollLoR = 0;

	//PG_0
	ImGui::RadioButton("Left##2", &rollLoR, 0); ImGui::SameLine();
	ImGui::RadioButton("Right##2", &rollLoR, 1);


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
		//PG
		//After the macro ends, I want the option to manually reset car orientation to the one the macro started
	}	
	
	//These sliders are used to set a starting car orientation
	if (newslider("Steer axis", &angle_steer)) {
		//PG
		// The input for the plugin will be a int from 0 to 8
	}
	
	lines();

	if (newslider("Pitch axis", &angle_pitch)) {
		//PG
		// The input for the plugin will be a int from 0 to 8
	}
	
	lines();

	if (newslider("Roll axis", &angle_roll)) {
		//PG
		// The input for the plugin will be a int from 0 to 8
	}

	static bool check_manual_or = false;
	ImGui::NewLine();
	if (ImGui::Checkbox("Enable Manual Car Orientation", &check_manual_or)) {
		//PG_1
		//Allow to change at any time car orientation with the following slider. Inputs are float
		//Those will add rotation to the relative axis
	}
	
	static float add_angle_steer = 0.0f;
	static float add_angle_pitch = 0.0f;
	static float add_angle_roll = 0.0f;

	if (ImGui::SliderAngle("Add to steer axis", &add_angle_steer, 0.0f, 360.0f)) {
		//PG_1
	}

	if (ImGui::SliderAngle("Add to pitch axis", &add_angle_pitch, 0.0f, 360.0f)) {
		//PG_1
	}

	if (ImGui::SliderAngle("Add to roll axis", &add_angle_roll, 0.0f, 360.0f)) {
		//PG_1
	}
	
	ImGui::NewLine();
	ImGui::Separator();
	ImGui::Text("Macro timeout");
	static int timeout = 0;
	static int max_sec = 30;
	if (ImGui::SliderInt("##timeout", &timeout, -1, max_sec, "%d sec")) {
		//PG
		//This is for how much time the macro will be executed
		// -1 is for unlimited time
	}
	

	ImGui::NewLine(); ImGui::SameLine(406);
	ImGui::Text("Change range");	ImGui::SameLine();
	ImGui::PushItemWidth(100);
	ImGui::InputInt("seconds", &max_sec);


	if (buttons(2.26893f, "Start")) {
		//PG
		//It starts the macro
	}
	ImGui::SameLine(0, 40);
	if (buttons(0.10472f, "Stop")) {
		//PG
		//It stops tha macro before it ends
	}
	
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
