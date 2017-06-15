#include "InputManager.h"

int32_t InputManager::actions = 0;
int16_t InputManager::positionsy = 0,
	InputManager::positionsx = 0;
const int32_t InputManager::mask = 1;


void InputManager::MapPosition(float x, float y)
{
	x *= 100;
	positionsx = x;
	y *= 100;
	positionsy = y;
}

void InputManager::MapActions(Inputs::KeyPresses input)
{
	actions |= KeyBitMapping(input);
}

void InputManager::Reset()
{
	actions = positionsx = positionsy = 0;
}

int32_t InputManager::KeyBitMapping(Inputs::KeyPresses input)
{
	switch (input)
	{
	case Inputs::LEFTARROW:
	case Inputs::A: return mask << 19;
	case Inputs::B: break;
	case Inputs::C: break;
	case Inputs::RIGHTARROW:
	case Inputs::D: return mask << 18;
	case Inputs::E: break;
	case Inputs::F: break;
	case Inputs::G: break;
	case Inputs::H: break;
	case Inputs::I: break;
	case Inputs::J: break;
	case Inputs::K: break;
	case Inputs::L: break;
	case Inputs::M: break;
	case Inputs::N: break;
	case Inputs::Ñ: break;
	case Inputs::O: break;
	case Inputs::P: break;
	case Inputs::Q: break;
	case Inputs::R: break;
	case Inputs::DOWNARROW:
	case Inputs::S: return mask << 17;
	case Inputs::T: break;
	case Inputs::U: break;
	case Inputs::V: break;
	case Inputs::UPARROW:
	case Inputs::W: return mask << 16;
	case Inputs::X: break;
	case Inputs::Y: break;
	case Inputs::Z: break;
	case Inputs::ESCAPE: return mask;
	case Inputs::F1: break;
	case Inputs::F2: break;
	case Inputs::F3: break;
	case Inputs::F4: break;
	case Inputs::F5: break;
	case Inputs::F6: break;
	case Inputs::F7: break;
	case Inputs::F8: break;
	case Inputs::F9: break;
	case Inputs::F10: break;
	case Inputs::F11: break;
	case Inputs::F12: break;
	case Inputs::IMPPNT: break;
	case Inputs::SUPR: break;
	case Inputs::RIGHTSHIFT: break;
	case Inputs::LEFTSHIFT: break;
	case Inputs::TAB: break;
	case Inputs::BLOQMAYUS: break;
	case Inputs::BACKSPACE: break;
	case Inputs::ENTER: break;
	case Inputs::SPACE: break;
	case Inputs::LEFTCTRL: break;
	case Inputs::RIGHTCTRL: break;
	case Inputs::FN: break;
	case Inputs::ALT: break;
	case Inputs::ALTGR: break;
	case Inputs::OR: break;
	case Inputs::INSERT: break;
	case Inputs::NUMPAD1: break;
	case Inputs::NUMPAD2: break;
	case Inputs::NUMPAD3: break;
	case Inputs::NUMPAD4: break;
	case Inputs::NUMPAD5: break;
	case Inputs::NUMPAD6: break;
	case Inputs::NUMPAD7: break;
	case Inputs::NUMPAD8: break;
	case Inputs::NUMPAD9: break;
	case Inputs::NUMPAD0: break;
	case Inputs::ONE: break;
	case Inputs::TWO: break;
	case Inputs::THREE: break;
	case Inputs::FOUR: break;
	case Inputs::FIVE: break;
	case Inputs::SIX: break;
	case Inputs::SEVEN: break;
	case Inputs::EIGHT: break;
	case Inputs::NINE: break;
	case Inputs::CERO: break;
	case Inputs::MOUSEBUTTON1: break;
	case Inputs::MOUSEBOTTON2: break;
	default: ;
	}
	return 0;
}

float InputManager::ReinterpretPosX(int64_t data)
{
	int16_t posX = 0;
	data = data >> 48;
	for (int i = 15; i--;)
	{
		posX += data & 1;
		data = data >> 1;
	}
	return (float)(posX / 100);
}

float InputManager::ReinterpretPosY(int64_t data)
{
	int16_t posY = 0;
	data = data >> 32;
	for (int i = 15; i--;)
	{
		posY += data & 1;
		data = data >> 1;
	}
	return float(posY / 100);
}

int32_t InputManager::ReinterpretID(int64_t data)
{
	auto id = 0;
	for (int i = 31; i--;)
	{
		id += data & 1;
		data = data >> 1;
	}
	return id;
}

InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}
