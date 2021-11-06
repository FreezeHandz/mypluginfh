#include "pch.h"
#include "mypluginfh.h"


BAKKESMOD_PLUGIN(mypluginfh, "write a plugin description here", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

bool en_steer = false;
bool en_pitch = false;
bool en_roll = false;

void mypluginfh::onLoad()
{
	_globalCvarManager = cvarManager;

	cvarManager->registerCvar("flightFH_enabled", "0", "Enable flight mode", true, true, 0, true, 1)
		.addOnValueChanged([this](std::string, CVarWrapper cvar) {
		if (cvar.getBoolValue()) {
			hookEvents();
		}
		else {
			unhookEvents();
		}});
	
	cvarManager->registerCvar("enable_air_Steer","0","Enable air steer",true,true,0,true, 1)
		.addOnValueChanged([this](std::string, CVarWrapper cvar) {
		en_steer = cvar.getBoolValue();
		});
}

void mypluginfh::onUnload()
{
}

// hooks events to allow the plugin to work
void mypluginfh::hookEvents() {
	auto sw = getSW();

	if (sw.IsNull()) return;

	auto cars = sw.GetCars();

	if (cars.IsNull()) return;

	CarWrapper car = gameWrapper->GetLocalCar();

	if (!car || !car.GetCollisionComponent()) {
		return;
	}

	gameWrapper->HookEventPost("Function TAGame.Car_TA.SetVehicleInput",
		[this](...) { setBallCarLocation(); });
}

// hooks events to allow the plugin to work
void mypluginfh::unhookEvents() {
	gameWrapper->UnhookEventPost("Function TAGame.Car_TA.SetVehicleInput");
}

ServerWrapper mypluginfh::getSW() {
	if (gameWrapper->IsInOnlineGame()) {
		return NULL;
	}
	else if (gameWrapper->IsInGame()) {
		return  gameWrapper->GetGameEventAsServer();
	}
	//cvarManager->log("no server");
	return NULL;
}
void  mypluginfh::setBallCarLocation() {
	if (!gameWrapper->IsInFreeplay()) { return; }
	ServerWrapper server = gameWrapper->GetCurrentGameState();
	if (!server) { return; }

	BallWrapper ball = server.GetBall();
	if (!ball) { return; }
	CarWrapper car = gameWrapper->GetLocalCar();
	if (!car) { return; }

	
	ball.SetLocation(Vector(0,0,1022));
	car.SetLocation(Vector(0,2560,1022));
	car.SetVelocity(Vector{ 0,0,0 });
	ball.SetVelocity(Vector{ 0,0,0 });

	//setRotator adds a fixed orientation
}