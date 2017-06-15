#pragma once
#include <SDL.h>

typedef bool FLAG;

class Inputs
{
private:
	static FLAG kA;
	static FLAG kB;
	static FLAG kC;
	static FLAG kD;
	static FLAG kE;
	static FLAG kF;
	static FLAG kG;
	static FLAG kH;
	static FLAG kI;
	static FLAG kJ;
	static FLAG kK;
	static FLAG kL;
	static FLAG kM;
	static FLAG kN;
	static FLAG kO;
	static FLAG kP;
	static FLAG kQ;
	static FLAG kR;
	static FLAG kS;
	static FLAG kT;
	static FLAG kU;
	static FLAG kV;
	static FLAG kW;
	static FLAG kX;
	static FLAG kY;
	static FLAG kZ;
	static FLAG kESCAPE;
	static FLAG kF1;
	static FLAG kF2;
	static FLAG kF3;
	static FLAG kF4;
	static FLAG kF5;
	static FLAG kF6;
	static FLAG kF7;
	static FLAG kF8;
	static FLAG kF9;
	static FLAG kF10;
	static FLAG kF11;
	static FLAG kF12;
	static FLAG kIMPPNT;
	static FLAG kSUPR;
	static FLAG kRIGHTSHIFT;
	static FLAG kLEFTSHIFT;
	static FLAG kTAB;
	static FLAG kBLOQMAYUS;
	static FLAG kBACKSPACE;
	static FLAG kENTER;
	static FLAG kSPACE;
	static FLAG kLEFTCTRL;
	static FLAG kRIGHTCTRL;
	static FLAG kFN;
	static FLAG kALT;
	static FLAG kALTGR;
	static FLAG kOR;
	static FLAG kLEFTARROW;
	static FLAG kRIGHTARROW;
	static FLAG kUPARROW;
	static FLAG kDOWNARROW;
	static FLAG kINSERT;
	static FLAG kNUMPAD1;
	static FLAG kNUMPAD2;
	static FLAG kNUMPAD3;
	static FLAG kNUMPAD4;
	static FLAG kNUMPAD5;
	static FLAG kNUMPAD6;
	static FLAG kNUMPAD7;
	static FLAG kNUMPAD8;
	static FLAG kNUMPAD9;
	static FLAG kNUMPAD0;
	static FLAG kONE;
	static FLAG kTWO;
	static FLAG kTHREE;
	static FLAG kFOUR;
	static FLAG kFIVE;
	static FLAG kSIX;
	static FLAG kSEVEN;
	static FLAG kEIGHT;
	static FLAG kNINE;
	static FLAG kCERO;
	static FLAG kMOUSEBUTTON1;
	static FLAG kMOUSEBUTTON2;
public:
	enum KeyPresses
	{
		A,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		Ñ,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z,
		ESCAPE,
		F1,
		F2,
		F3,
		F4,
		F5,
		F6,
		F7,
		F8,
		F9,
		F10,
		F11,
		F12,
		IMPPNT,
		SUPR,
		RIGHTSHIFT,
		LEFTSHIFT,
		TAB,
		BLOQMAYUS,
		BACKSPACE,
		ENTER,
		SPACE,
		LEFTCTRL,
		RIGHTCTRL,
		FN,
		ALT,
		ALTGR,
		OR,
		LEFTARROW,
		RIGHTARROW,
		UPARROW,
		DOWNARROW,
		INSERT,
		NUMPAD1,
		NUMPAD2,
		NUMPAD3,
		NUMPAD4,
		NUMPAD5,
		NUMPAD6,
		NUMPAD7,
		NUMPAD8,
		NUMPAD9,
		NUMPAD0,
		ONE,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		CERO,
		MOUSEBUTTON1,
		MOUSEBOTTON2
	};

	static bool KeyPressed(KeyPresses key);
	static bool KeyDown(KeyPresses key);
	static bool KeyUp(KeyPresses key);
	Inputs();
	~Inputs();
};
