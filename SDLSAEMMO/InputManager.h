#pragma once
#include "Inputs.h"
class InputManager
{
private:
	static const int32_t		mask;
	static int32_t				actions;
	static int16_t				positionsx,
								positionsy;
	static int32_t KeyBitMapping(Inputs::KeyPresses input);
	static int32_t ReinterpretID(int64_t data);
	static float ReinterpretPosX(int64_t data);
	static float ReinterpretPosY(int64_t data);
public:
	static void MapPosition(float x, float y);
	static void MapActions(Inputs::KeyPresses input);
	static void Reset();
	static inline int32_t getActions() { return actions; }
	static inline int16_t getPositionsX() { return positionsx; }
	static inline int16_t getPositionsY() { return positionsy; }
	InputManager();
	~InputManager();
};

