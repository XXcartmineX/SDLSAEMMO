#include "Inputs.h"
FLAG Inputs::kA;
FLAG Inputs::kB;
FLAG Inputs::kC;
FLAG Inputs::kD;
FLAG Inputs::kE;
FLAG Inputs::kF;
FLAG Inputs::kG;
FLAG Inputs::kH;
FLAG Inputs::kI;
FLAG Inputs::kJ;
FLAG Inputs::kK;
FLAG Inputs::kL;
FLAG Inputs::kM;
FLAG Inputs::kN;
FLAG Inputs::kO;
FLAG Inputs::kP;
FLAG Inputs::kQ;
FLAG Inputs::kR;
FLAG Inputs::kS;
FLAG Inputs::kT;
FLAG Inputs::kU;
FLAG Inputs::kV;
FLAG Inputs::kW;
FLAG Inputs::kX;
FLAG Inputs::kY;
FLAG Inputs::kZ;
FLAG Inputs::kESCAPE;
FLAG Inputs::kF1;
FLAG Inputs::kF2;
FLAG Inputs::kF3;
FLAG Inputs::kF4;
FLAG Inputs::kF5;
FLAG Inputs::kF6;
FLAG Inputs::kF7;
FLAG Inputs::kF8;
FLAG Inputs::kF9;
FLAG Inputs::kF10;
FLAG Inputs::kF11;
FLAG Inputs::kF12;
FLAG Inputs::kIMPPNT;
FLAG Inputs::kSUPR;
FLAG Inputs::kRIGHTSHIFT;
FLAG Inputs::kLEFTSHIFT;
FLAG Inputs::kTAB;
FLAG Inputs::kBLOQMAYUS;
FLAG Inputs::kBACKSPACE;
FLAG Inputs::kENTER;
FLAG Inputs::kSPACE;
FLAG Inputs::kLEFTCTRL;
FLAG Inputs::kRIGHTCTRL;
FLAG Inputs::kFN;
FLAG Inputs::kALT;
FLAG Inputs::kALTGR;
FLAG Inputs::kOR;
FLAG Inputs::kLEFTARROW;
FLAG Inputs::kRIGHTARROW;
FLAG Inputs::kUPARROW;
FLAG Inputs::kDOWNARROW;
FLAG Inputs::kINSERT;
FLAG Inputs::kNUMPAD1;
FLAG Inputs::kNUMPAD2;
FLAG Inputs::kNUMPAD3;
FLAG Inputs::kNUMPAD4;
FLAG Inputs::kNUMPAD5;
FLAG Inputs::kNUMPAD6;
FLAG Inputs::kNUMPAD7;
FLAG Inputs::kNUMPAD8;
FLAG Inputs::kNUMPAD9;
FLAG Inputs::kNUMPAD0;
FLAG Inputs::kONE;
FLAG Inputs::kTWO;
FLAG Inputs::kTHREE;
FLAG Inputs::kFOUR;
FLAG Inputs::kFIVE;
FLAG Inputs::kSIX;
FLAG Inputs::kSEVEN;
FLAG Inputs::kEIGHT;
FLAG Inputs::kNINE;
FLAG Inputs::kCERO;
FLAG Inputs::kMOUSEBUTTON1;
FLAG Inputs::kMOUSEBUTTON2;
bool Inputs::KeyPressed(KeyPresses key)
{
	const Uint8* keyP = SDL_GetKeyboardState(NULL);
	switch (key) {
	case KeyPresses::A:
		return keyP[SDL_SCANCODE_A] ? true : false;
	case KeyPresses::B:
		return keyP[SDL_SCANCODE_B] ? true : false;
	case KeyPresses::C:
		return keyP[SDL_SCANCODE_C] ? true : false;
	case KeyPresses::D:
		return keyP[SDL_SCANCODE_D] ? true : false;
	case KeyPresses::E:
		return keyP[SDL_SCANCODE_E] ? true : false;
	case KeyPresses::F:
		return keyP[SDL_SCANCODE_F] ? true : false;
	case KeyPresses::G:
		return keyP[SDL_SCANCODE_G] ? true : false;
	case KeyPresses::H:
		return keyP[SDL_SCANCODE_H] ? true : false;
	case KeyPresses::I:
		return keyP[SDL_SCANCODE_I] ? true : false;
	case KeyPresses::J:
		return keyP[SDL_SCANCODE_J] ? true : false;
	case KeyPresses::K:
		return keyP[SDL_SCANCODE_K] ? true : false;
	case KeyPresses::L:
		return keyP[SDL_SCANCODE_L] ? true : false;
	case KeyPresses::M:
		return keyP[SDL_SCANCODE_M] ? true : false;
	case KeyPresses::N:
		return keyP[SDL_SCANCODE_N] ? true : false;
	case KeyPresses::O:
		return keyP[SDL_SCANCODE_O] ? true : false;
	case KeyPresses::P:
		return keyP[SDL_SCANCODE_P] ? true : false;
	case KeyPresses::Q:
		return keyP[SDL_SCANCODE_Q] ? true : false;
	case KeyPresses::R:
		return keyP[SDL_SCANCODE_R] ? true : false;
	case KeyPresses::S:
		return keyP[SDL_SCANCODE_S] ? true : false;
	case KeyPresses::T:
		return keyP[SDL_SCANCODE_T] ? true : false;
	case KeyPresses::U:
		return keyP[SDL_SCANCODE_U] ? true : false;
	case KeyPresses::V:
		return keyP[SDL_SCANCODE_V] ? true : false;
	case KeyPresses::W:
		return keyP[SDL_SCANCODE_W] ? true : false;
	case KeyPresses::X:
		return keyP[SDL_SCANCODE_X] ? true : false;
	case KeyPresses::Y:
		return keyP[SDL_SCANCODE_Y] ? true : false;
	case KeyPresses::Z:
		return keyP[SDL_SCANCODE_Z] ? true : false;
	case KeyPresses::ESCAPE:
		return keyP[SDL_SCANCODE_ESCAPE] ? true : false;
	case KeyPresses::F1:
		return keyP[SDL_SCANCODE_F1] ? true : false;
	case KeyPresses::F2:
		return keyP[SDL_SCANCODE_F2] ? true : false;
	case KeyPresses::F3:
		return keyP[SDL_SCANCODE_F3] ? true : false;
	case KeyPresses::F4:
		return keyP[SDL_SCANCODE_F4] ? true : false;
	case KeyPresses::F5:
		return keyP[SDL_SCANCODE_F5] ? true : false;
	case KeyPresses::F6:
		return keyP[SDL_SCANCODE_F6] ? true : false;
	case KeyPresses::F7:
		return keyP[SDL_SCANCODE_F7] ? true : false;
	case KeyPresses::F8:
		return keyP[SDL_SCANCODE_F8] ? true : false;
	case KeyPresses::F9:
		return keyP[SDL_SCANCODE_F9] ? true : false;
	case KeyPresses::F10:
		return keyP[SDL_SCANCODE_F10] ? true : false;
	case KeyPresses::F11:
		return keyP[SDL_SCANCODE_F11] ? true : false;
	case KeyPresses::F12:
		return keyP[SDL_SCANCODE_F12] ? true : false;
	case KeyPresses::TAB:
		return keyP[SDL_SCANCODE_TAB] ? true : false;
	case KeyPresses::ONE:
		return keyP[SDL_SCANCODE_1] ? true : false;
	case KeyPresses::TWO:
		return keyP[SDL_SCANCODE_2] ? true : false;
	case KeyPresses::THREE:
		return keyP[SDL_SCANCODE_3] ? true : false;
	case KeyPresses::FOUR:
		return keyP[SDL_SCANCODE_4] ? true : false;
	case KeyPresses::FIVE:
		return keyP[SDL_SCANCODE_5] ? true : false;
	case KeyPresses::SIX:
		return keyP[SDL_SCANCODE_6] ? true : false;
	case KeyPresses::SEVEN:
		return keyP[SDL_SCANCODE_7] ? true : false;
	case KeyPresses::EIGHT:
		return keyP[SDL_SCANCODE_8] ? true : false;
	case KeyPresses::NINE:
		return keyP[SDL_SCANCODE_9] ? true : false;
	case KeyPresses::CERO:
		return keyP[SDL_SCANCODE_0] ? true : false;
	case KeyPresses::BACKSPACE:
		return keyP[SDL_SCANCODE_BACKSPACE] ? true : false;
	case KeyPresses::ENTER:
		return keyP[SDL_SCANCODE_RETURN] ? true : false;
	case KeyPresses::LEFTSHIFT:
		return keyP[SDL_SCANCODE_LSHIFT] ? true : false;
	case KeyPresses::RIGHTSHIFT:
		return keyP[SDL_SCANCODE_RSHIFT] ? true : false;
	case KeyPresses::LEFTCTRL:
		return keyP[SDL_SCANCODE_LCTRL] ? true : false;
	case KeyPresses::RIGHTCTRL:
		return keyP[SDL_SCANCODE_RCTRL] ? true : false;
	case KeyPresses::ALT:
		return keyP[SDL_SCANCODE_LALT] ? true : false;
	case KeyPresses::ALTGR:
		return keyP[SDL_SCANCODE_RALT] ? true : false;
	case KeyPresses::LEFTARROW:
		return keyP[SDL_SCANCODE_LEFT] ? true : false;
	case KeyPresses::RIGHTARROW:
		return keyP[SDL_SCANCODE_RIGHT] ? true : false;
	case KeyPresses::UPARROW:
		return keyP[SDL_SCANCODE_UP] ? true : false;
	case KeyPresses::DOWNARROW:
		return keyP[SDL_SCANCODE_DOWN] ? true : false;
	case KeyPresses::NUMPAD1:
		return keyP[SDL_SCANCODE_INTERNATIONAL1] ? true : false;
	case KeyPresses::NUMPAD2:
		return keyP[SDL_SCANCODE_INTERNATIONAL2] ? true : false;
	case KeyPresses::NUMPAD3:
		return keyP[SDL_SCANCODE_INTERNATIONAL3] ? true : false;
	case KeyPresses::NUMPAD4:
		return keyP[SDL_SCANCODE_INTERNATIONAL4] ? true : false;
	case KeyPresses::NUMPAD5:
		return keyP[SDL_SCANCODE_INTERNATIONAL5] ? true : false;
	case KeyPresses::NUMPAD6:
		return keyP[SDL_SCANCODE_INTERNATIONAL6] ? true : false;
	case KeyPresses::NUMPAD7:
		return keyP[SDL_SCANCODE_INTERNATIONAL7] ? true : false;
	case KeyPresses::NUMPAD8:
		return keyP[SDL_SCANCODE_INTERNATIONAL8] ? true : false;
	case KeyPresses::NUMPAD9:
		return keyP[SDL_SCANCODE_INTERNATIONAL9] ? true : false;
	}
}

bool Inputs::KeyDown(KeyPresses key)
{
		const Uint8* keyP = SDL_GetKeyboardState(NULL);
	switch (key) {
	case KeyPresses::A:
		if (!kA && keyP[SDL_SCANCODE_A])
		{
			kA = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_A]) kA = false;
			return false;
		}
	case KeyPresses::B:
		if (!kB && keyP[SDL_SCANCODE_B])
		{
			kB = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_B]) kB = false;
			return false;
		}
	case KeyPresses::C:
		if (!kC && keyP[SDL_SCANCODE_C])
		{
			kC = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_C]) kC = false;
			return false;
		}
	case KeyPresses::D:
		if (!kD && keyP[SDL_SCANCODE_D])
		{
			kD = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_D]) kD = false;
			return false;
		}
	case KeyPresses::E:
		if (!kE && keyP[SDL_SCANCODE_E])
		{
			kE = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_E]) kE = false;
			return false;
		}
	case KeyPresses::F:
		if (!kF && keyP[SDL_SCANCODE_F])
		{
			kF = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_F]) kF = false;
			return false;
		}
	case KeyPresses::G:
		if (!kG && keyP[SDL_SCANCODE_G])
		{
			kG = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_G]) kG = false;
			return false;
		}
	case KeyPresses::H:
		if (!kH && keyP[SDL_SCANCODE_H])
		{
			kH = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_H]) kH = false;
			return false;
		}
	case KeyPresses::I:
		if (!kI && keyP[SDL_SCANCODE_I])
		{
			kI = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_I]) kI = false;
			return false;
		}
	case KeyPresses::J:
		if (!kJ && keyP[SDL_SCANCODE_J])
		{
			kJ = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_J]) kJ = false;
			return false;
		}
	case KeyPresses::K:
		if (!kK && keyP[SDL_SCANCODE_K])
		{
			kK = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_K]) kK = false;
			return false;
		}
	case KeyPresses::L:
		if (!kL && keyP[SDL_SCANCODE_L])
		{
			kL = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_L]) kL = false;
			return false;
		}
	case KeyPresses::M:
		if (!kM && keyP[SDL_SCANCODE_M])
		{
			kM = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_M]) kM = false;
			return false;
		}
	case KeyPresses::N:
		if (!kN && keyP[SDL_SCANCODE_N])
		{
			kN = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_N]) kN = false;
			return false;
		}
	case KeyPresses::O:
		if (!kO && keyP[SDL_SCANCODE_O])
		{
			kO = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_O]) kO = false;
			return false;
		}
	case KeyPresses::P:
		if (!kP && keyP[SDL_SCANCODE_P])
		{
			kP = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_P]) kP = false;
			return false;
		}
	case KeyPresses::Q:
		if (!kQ && keyP[SDL_SCANCODE_Q])
		{
			kQ = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_Q]) kQ = false;
			return false;
		}
	case KeyPresses::R:
		if (!kR && keyP[SDL_SCANCODE_R])
		{
			kR = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_R]) kR = false;
			return false;
	case KeyPresses::S:
		if (!kS && keyP[SDL_SCANCODE_S])
		{
			kS = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_S]) kS = false;
			return false;
		}
	case KeyPresses::T:
		if (!kT && keyP[SDL_SCANCODE_T])
		{
			kT = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_T]) kT = false;
			return false;
		}
	case KeyPresses::U:
		if (!kU && keyP[SDL_SCANCODE_U])
		{
			kU = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_U]) kU = false;
			return false;
		}
	case KeyPresses::V:
		if (!kV && keyP[SDL_SCANCODE_V])
		{
			kV = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_V]) kV = false;
			return false;
		}
	case KeyPresses::W:
		if (!kW && keyP[SDL_SCANCODE_W])
		{
			kW = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_W]) kW = false;
			return false;
		}
	case KeyPresses::X:
		if (!kX && keyP[SDL_SCANCODE_X])
		{
			kX = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_X]) kX = false;
			return false;
		}
	case KeyPresses::Y:
		if (!kY && keyP[SDL_SCANCODE_Y])
		{
			kY = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_Y]) kY = false;
			return false;
		}
	case KeyPresses::Z:
		if (!kZ && keyP[SDL_SCANCODE_Z])
		{
			kZ = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_Z]) kZ = false;
			return false;
		}
	case KeyPresses::ESCAPE:
		if (!kESCAPE && keyP[SDL_SCANCODE_ESCAPE])
		{
			kESCAPE = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_ESCAPE]) kESCAPE = false;
			return false;
		}
	case KeyPresses::F1:
		if (!kF1 && keyP[SDL_SCANCODE_F1])
		{
			kF1 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_F1]) kF1 = false;
			return false;
		}
	case KeyPresses::F2:
		if (!kF2 && keyP[SDL_SCANCODE_F2])
		{
			kF2 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_F2]) kF2 = false;
			return false;
		}
	case KeyPresses::F3:
		if (!kF3 && keyP[SDL_SCANCODE_F3])
		{
			kF3 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_F3]) kF3 = false;
			return false;
		}
	case KeyPresses::F4:
		if (!kF4 && keyP[SDL_SCANCODE_F4])
		{
			kF4 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_F4]) kF4 = false;
			return false;
		}
	case KeyPresses::F5:
		if (!kF5 && keyP[SDL_SCANCODE_F5])
		{
			kF5 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_F5]) kF5 = false;
			return false;
		}
	case KeyPresses::F6:
		if (!kF6 && keyP[SDL_SCANCODE_F6])
		{
			kF6 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_F6]) kF6 = false;
			return false;
		}
	case KeyPresses::F7:
		if (!kF7 && keyP[SDL_SCANCODE_F7])
		{
			kF7 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_F7]) kF7 = false;
			return false;
		}
	case KeyPresses::F8:
		if (!kF8 && keyP[SDL_SCANCODE_F8])
		{
			kF8 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_F8]) kF8 = false;
			return false;
		}
	case KeyPresses::F9:
		if (!kF9 && keyP[SDL_SCANCODE_F9])
		{
			kF9 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_F9]) kF9 = false;
			return false;
		}
	case KeyPresses::F10:
		if (!kF10 && keyP[SDL_SCANCODE_F10])
		{
			kF10 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_F10]) kF10 = false;
			return false;
		}
	case KeyPresses::F11:
		if (!kF11 && keyP[SDL_SCANCODE_F11])
		{
			kF11 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_F11]) kF11 = false;
			return false;
		}
	case KeyPresses::F12:
		if (!kF12 && keyP[SDL_SCANCODE_F12])
		{
			kF12 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_F12]) kF12 = false;
			return false;
		}
	case KeyPresses::IMPPNT:
		if (!kIMPPNT && keyP[SDL_SCANCODE_PRINTSCREEN])
		{
			kIMPPNT = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_PRINTSCREEN]) kIMPPNT = false;
			return false;
		}
	case KeyPresses::SUPR:
		if (!kSUPR && keyP[SDL_SCANCODE_DELETE])
		{
			kSUPR = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_DELETE]) kSUPR = false;
			return false;
		}
	case KeyPresses::RIGHTSHIFT:
		if (!kRIGHTSHIFT && keyP[SDL_SCANCODE_RSHIFT])
		{
			kRIGHTSHIFT = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_RSHIFT]) kRIGHTSHIFT = false;
			return false;
		}
	case KeyPresses::LEFTSHIFT:
		if (!kLEFTSHIFT && keyP[SDL_SCANCODE_LSHIFT])
		{
			kLEFTSHIFT = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_LSHIFT]) kLEFTSHIFT = false;
			return false;
		}
	case KeyPresses::TAB:
		if (!kTAB && keyP[SDL_SCANCODE_TAB])
		{
			kTAB = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_TAB]) kTAB = false;
			return false;
		}
	case KeyPresses::BACKSPACE:
		if (!kBACKSPACE && keyP[SDL_SCANCODE_BACKSPACE])
		{
			kBACKSPACE = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_BACKSPACE]) kBACKSPACE = false;
			return false;
		}
	case KeyPresses::ENTER:
		if (!kENTER && keyP[SDL_SCANCODE_RETURN])
		{
			kENTER = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_RETURN]) kENTER = false;
			return false;
		}
	case KeyPresses::SPACE:
		if (!kSPACE && keyP[SDL_SCANCODE_SPACE])
		{
			kSPACE = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_SPACE]) kSPACE = false;
			return false;
		}
	case KeyPresses::LEFTCTRL:
		if (!kLEFTCTRL && keyP[SDL_SCANCODE_LCTRL])
		{
			kLEFTCTRL = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_LCTRL]) kLEFTCTRL = false;
			return false;
		}
	case KeyPresses::RIGHTCTRL:
		if (!kRIGHTCTRL && keyP[SDL_SCANCODE_RCTRL])
		{
			kRIGHTCTRL = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_RCTRL]) kRIGHTCTRL = false;
			return false;
		}
	case KeyPresses::ALT:
		if (!kALT && keyP[SDL_SCANCODE_LALT])
		{
			kALT = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_LALT]) kALT = false;
			return false;
		}
	case KeyPresses::ALTGR:
		if (!kALTGR && keyP[SDL_SCANCODE_RALT])
		{
			kALTGR = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_RALT]) kALTGR = false;
			return false;
		}
	case KeyPresses::LEFTARROW:
		if (!kLEFTARROW && keyP[SDL_SCANCODE_LEFT])
		{
			kLEFTARROW = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_LEFT]) kLEFTARROW = false;
			return false;
		}
	case KeyPresses::RIGHTARROW:
		if (!kRIGHTARROW && keyP[SDL_SCANCODE_RIGHT])
		{
			kRIGHTARROW = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_RIGHT]) kRIGHTARROW = false;
			return false;
		}
	case KeyPresses::UPARROW:
		if (!kUPARROW && keyP[SDL_SCANCODE_UP])
		{
			kUPARROW = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_UP]) kUPARROW = false;
			return false;
		}
	case KeyPresses::DOWNARROW:
		if (!kDOWNARROW && keyP[SDL_SCANCODE_DOWN])
		{
			kDOWNARROW = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_DOWN]) kDOWNARROW = false;
			return false;
		}
	case KeyPresses::INSERT:
		if (!kINSERT && keyP[SDL_SCANCODE_INSERT])
		{
			kINSERT = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_INSERT]) kINSERT = false;
			return false;
		}
	case KeyPresses::NUMPAD1:
		if (!kNUMPAD1 && keyP[SDL_SCANCODE_INTERNATIONAL1])
		{
			kNUMPAD1 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_INTERNATIONAL1]) kNUMPAD1 = false;
			return false;
		}
	case KeyPresses::NUMPAD2:
		if (!kNUMPAD2 && keyP[SDL_SCANCODE_INTERNATIONAL2])
		{
			kNUMPAD2 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_INTERNATIONAL2]) kNUMPAD2 = false;
			return false;
		}
	case KeyPresses::NUMPAD3:
		if (!kNUMPAD3 && keyP[SDL_SCANCODE_INTERNATIONAL3])
		{
			kNUMPAD3 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_INTERNATIONAL3]) kNUMPAD3 = false;
			return false;
		}
	case KeyPresses::NUMPAD4:
		if (!kNUMPAD4 && keyP[SDL_SCANCODE_INTERNATIONAL4])
		{
			kNUMPAD4 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_INTERNATIONAL4]) kNUMPAD4 = false;
			return false;
		}
	case KeyPresses::NUMPAD5:
		if (!kNUMPAD5 && keyP[SDL_SCANCODE_INTERNATIONAL5])
		{
			kNUMPAD5 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_INTERNATIONAL5]) kNUMPAD5 = false;
			return false;
		}
	case KeyPresses::NUMPAD6:
		if (!kNUMPAD6 && keyP[SDL_SCANCODE_INTERNATIONAL6])
		{
			kNUMPAD6 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_INTERNATIONAL6]) kNUMPAD6 = false;
			return false;
		}
	case KeyPresses::NUMPAD7:
		if (!kNUMPAD7 && keyP[SDL_SCANCODE_INTERNATIONAL7])
		{
			kNUMPAD7 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_INTERNATIONAL7]) kNUMPAD7 = false;
			return false;
		}
	case KeyPresses::NUMPAD8:
		if (!kNUMPAD8 && keyP[SDL_SCANCODE_INTERNATIONAL8])
		{
			kNUMPAD8 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_INTERNATIONAL8]) kNUMPAD8 = false;
			return false;
		}
	case KeyPresses::NUMPAD9:
		if (!kNUMPAD9 && keyP[SDL_SCANCODE_INTERNATIONAL9])
		{
			kNUMPAD9 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_INTERNATIONAL9]) kNUMPAD9 = false;
			return false;
		}
	case KeyPresses::ONE:
		if (!kONE && keyP[SDL_SCANCODE_1])
		{
			kONE = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_1]) kONE = false;
			return false;
		}
	case KeyPresses::TWO:
		if (!kTWO && keyP[SDL_SCANCODE_2])
		{
			kTWO = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_2]) kTWO = false;
			return false;
		}
	case KeyPresses::THREE:
		if (!kTHREE && keyP[SDL_SCANCODE_3])
		{
			kTHREE = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_3]) kTHREE = false;
			return false;
		}
	case KeyPresses::FOUR:
		if (!kFOUR && keyP[SDL_SCANCODE_4])
		{
			kFOUR = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_4]) kFOUR = false;
			return false;
		}
	case KeyPresses::FIVE:
		if (!kFIVE && keyP[SDL_SCANCODE_5])
		{
			kFIVE = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_5]) kFIVE = false;
			return false;
		}
	case KeyPresses::SIX:
		if (!kSIX && keyP[SDL_SCANCODE_6])
		{
			kSIX = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_6]) kSIX = false;
			return false;
		}
	case KeyPresses::SEVEN:
		if (!kSEVEN && keyP[SDL_SCANCODE_7])
		{
			kSEVEN = true;
  			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_7]) kSEVEN = false;
			return false;
		}
	case KeyPresses::EIGHT:
		if (!kEIGHT && keyP[SDL_SCANCODE_8])
		{
			kEIGHT = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_8]) kEIGHT = false;
			return false;
		}
	case KeyPresses::NINE:
		if (!kNINE && keyP[SDL_SCANCODE_9])
		{
			kNINE = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_9]) kNINE = false;
			return false;
		}
	case KeyPresses::CERO:
		if (!kCERO && keyP[SDL_SCANCODE_0])
		{
			kCERO = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_SCANCODE_0]) kCERO = false;
			return false;
		}
	case KeyPresses::MOUSEBUTTON1:
		if (!kMOUSEBUTTON1 && keyP[SDL_BUTTON_LEFT])
		{
			kMOUSEBUTTON1 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_BUTTON_LEFT]) kMOUSEBUTTON1 = false;
			return false;
		}
	case KeyPresses::MOUSEBOTTON2:
		if (!kMOUSEBUTTON2 && keyP[SDL_BUTTON_RIGHT])
		{
			kMOUSEBUTTON2 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_BUTTON_RIGHT]) kMOUSEBUTTON2 = false;
			return false;
		}
		}

	}
	return false;
}

//TO DO REPARAR ESTE PEDO

bool Inputs::KeyUp(KeyPresses key)
{
	const Uint8* keyP = SDL_GetKeyboardState(NULL);
	switch (key) {
	case KeyPresses::A:
		if (kA && !keyP[SDL_SCANCODE_A])
		{
			kA = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_A]) kA = true;
			return false;
		}
	case KeyPresses::B:
		if (kB && !keyP[SDL_SCANCODE_B])
		{
			kB = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_B]) kB = true;
			return false;
		}
	case KeyPresses::C:
		if (kC && !keyP[SDL_SCANCODE_C])
		{
			kC = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_C]) kC = true;
			return false;
		}
	case KeyPresses::D:
		if (kD && !keyP[SDL_SCANCODE_D])
		{
			kD = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_D]) kD = true;
			return false;
		}
	case KeyPresses::E:
		if (kE && !keyP[SDL_SCANCODE_E])
		{
			kE = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_E]) kE = true;
			return false;
		}
	case KeyPresses::F:
		if (kF && !keyP[SDL_SCANCODE_F])
		{
			kF = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_F]) kF = true;
			return false;
		}
	case KeyPresses::G:
		if (kG && !keyP[SDL_SCANCODE_G])
		{
			kG = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_G]) kG = true;
			return false;
		}
	case KeyPresses::H:
		if (kH && !keyP[SDL_SCANCODE_H])
		{
			kH = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_H]) kH = true;
			return false;
		}
	case KeyPresses::I:
		if (kI && !keyP[SDL_SCANCODE_I])
		{
			kI = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_I]) kI = true;
			return false;
		}
	case KeyPresses::J:
		if (kJ && !keyP[SDL_SCANCODE_J])
		{
			kJ = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_J]) kJ = true;
			return false;
		}
	case KeyPresses::K:
		if (kK && !keyP[SDL_SCANCODE_K])
		{
			kK = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_K]) kK = true;
			return false;
		}
	case KeyPresses::L:
		if (kL && !keyP[SDL_SCANCODE_L])
		{
			kL = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_L]) kL = true;
			return false;
		}
	case KeyPresses::M:
		if (kM && !keyP[SDL_SCANCODE_M])
		{
			kM = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_M]) kM = true;
			return false;
		}
	case KeyPresses::N:
		if (kN && !keyP[SDL_SCANCODE_N])
		{
			kN = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_N]) kN = true;
			return false;
		}
	case KeyPresses::O:
		if (kO && !keyP[SDL_SCANCODE_O])
		{
			kO = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_O]) kO = true;
			return false;
		}
	case KeyPresses::P:
		if (kP && !keyP[SDL_SCANCODE_P])
		{
			kP = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_P]) kP = true;
			return false;
		}
	case KeyPresses::Q:
		if (kQ && !keyP[SDL_SCANCODE_Q])
		{
			kQ = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_Q]) kQ = true;
			return false;
		}
	case KeyPresses::R:
		if (kR && !keyP[SDL_SCANCODE_R])
		{
			kR = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_R]) kR = true;
			return false;
	case KeyPresses::S:
		if (kS && !keyP[SDL_SCANCODE_S])
		{
			kS = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_S]) kS = true;
			return false;
		}
	case KeyPresses::T:
		if (kT && !keyP[SDL_SCANCODE_T])
		{
			kT = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_T]) kT = true;
			return false;
		}
	case KeyPresses::U:
		if (kU && !keyP[SDL_SCANCODE_U])
		{
			kU = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_U]) kU = true;
			return false;
		}
	case KeyPresses::V:
		if (kV && !keyP[SDL_SCANCODE_V])
		{
			kV = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_V]) kV = true;
			return false;
		}
	case KeyPresses::W:
		if (kW && !keyP[SDL_SCANCODE_W])
		{
			kW = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_W]) kW = true;
			return false;
		}
	case KeyPresses::X:
		if (kX && !keyP[SDL_SCANCODE_X])
		{
			kX = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_X]) kX = true;
			return false;
		}
	case KeyPresses::Y:
		if (kY && !keyP[SDL_SCANCODE_Y])
		{
			kY = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_Y]) kY = true;
			return false;
		}
	case KeyPresses::Z:
		if (kZ && !keyP[SDL_SCANCODE_Z])
		{
			kZ = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_Z]) kZ = true;
			return false;
		}
	case KeyPresses::ESCAPE:
		if (kESCAPE && !keyP[SDL_SCANCODE_ESCAPE])
		{
			kESCAPE = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_ESCAPE]) kESCAPE = true;
			return false;
		}
	case KeyPresses::F1:
		if (kF1 && !keyP[SDL_SCANCODE_F1])
		{
			kF1 = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_F1]) kF1 = true;
			return false;
		}
	case KeyPresses::F2:
		if (kF2 && !keyP[SDL_SCANCODE_F2])
		{
			kF2 = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_F2]) kF2 = true;
			return false;
		}
	case KeyPresses::F3:
		if (kF3 && !keyP[SDL_SCANCODE_F3])
		{
			kF3 = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_F3]) kF3 = true;
			return false;
		}
	case KeyPresses::F4:
		if (kF4 && !keyP[SDL_SCANCODE_F4])
		{
			kF4 = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_F4]) kF4 = true;
			return false;
		}
	case KeyPresses::F5:
		if (kF5 && !keyP[SDL_SCANCODE_F5])
		{
			kF5 = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_F5]) kF5 = true;
			return false;
		}
	case KeyPresses::F6:
		if (kF6 && !keyP[SDL_SCANCODE_F6])
		{
			kF6 = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_F6]) kF6 = true;
			return false;
		}
	case KeyPresses::F7:
		if (kF7 && !keyP[SDL_SCANCODE_F7])
		{
			kF7 = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_F7]) kF7 = true;
			return false;
		}
	case KeyPresses::F8:
		if (kF8 && !keyP[SDL_SCANCODE_F8])
		{
			kF8 = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_F8]) kF8 = true;
			return false;
		}
	case KeyPresses::F9:
		if (kF9 && !keyP[SDL_SCANCODE_F9])
		{
			kF9 = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_F9]) kF9 = true;
			return false;
		}
	case KeyPresses::F10:
		if (kF10 && !keyP[SDL_SCANCODE_F10])
		{
			kF10 = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_F10]) kF10 = true;
			return false;
		}
	case KeyPresses::F11:
		if (kF11 && !keyP[SDL_SCANCODE_F11])
		{
			kF11 = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_F11]) kF11 = true;
			return false;
		}
	case KeyPresses::F12:
		if (kF12 && !keyP[SDL_SCANCODE_F12])
		{
			kF12 = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_F12]) kF12 = true;
			return false;
		}
	case KeyPresses::IMPPNT:
		if (kIMPPNT && !keyP[SDL_SCANCODE_PRINTSCREEN])
		{
			kIMPPNT = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_PRINTSCREEN]) kIMPPNT = true;
			return false;
		}
	case KeyPresses::SUPR:
		if (kSUPR && !keyP[SDL_SCANCODE_DELETE])
		{
			kSUPR = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_DELETE]) kSUPR = true;
			return false;
		}
	case KeyPresses::RIGHTSHIFT:
		if (kRIGHTSHIFT && !keyP[SDL_SCANCODE_RSHIFT])
		{
			kRIGHTSHIFT = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_RSHIFT]) kRIGHTSHIFT = true;
			return false;
		}
	case KeyPresses::LEFTSHIFT:
		if (kLEFTSHIFT && !keyP[SDL_SCANCODE_LSHIFT])
		{
			kLEFTSHIFT = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_LSHIFT]) kLEFTSHIFT = true;
			return false;
		}
	case KeyPresses::TAB:
		if (kTAB && !keyP[SDL_SCANCODE_TAB])
		{
			kTAB = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_TAB]) kTAB = true;
			return false;
		}
	case KeyPresses::BACKSPACE:
		if (kBACKSPACE && !keyP[SDL_SCANCODE_BACKSPACE])
		{
			kBACKSPACE = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_BACKSPACE]) kBACKSPACE = true;
			return false;
		}
	case KeyPresses::ENTER:
		if (kENTER && !keyP[SDL_SCANCODE_RETURN])
		{
			kENTER = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_RETURN]) kENTER = true;
			return false;
		}
	case KeyPresses::SPACE:
		if (kSPACE && !keyP[SDL_SCANCODE_SPACE])
		{
			kSPACE = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_SPACE]) kSPACE = true;
			return false;
		}
	case KeyPresses::LEFTCTRL:
		if (kLEFTCTRL && !keyP[SDL_SCANCODE_LCTRL])
		{
			kLEFTCTRL = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_LCTRL]) kLEFTCTRL = true;
			return false;
		}
	case KeyPresses::RIGHTCTRL:
		if (kRIGHTCTRL && !keyP[SDL_SCANCODE_RCTRL])
		{
			kRIGHTCTRL = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_RCTRL]) kRIGHTCTRL = true;
			return false;
		}
	case KeyPresses::ALT:
		if (kALT && !keyP[SDL_SCANCODE_LALT])
		{
			kALT = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_LALT]) kALT = true;
			return false;
		}
	case KeyPresses::ALTGR:
		if (kALTGR && !keyP[SDL_SCANCODE_RALT])
		{
			kALTGR = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_RALT]) kALTGR = true;
			return false;
		}
	case KeyPresses::LEFTARROW:
		if (kLEFTARROW && !keyP[SDL_SCANCODE_LEFT])
		{
			kLEFTARROW = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_LEFT]) kLEFTARROW = true;
			return false;
		}
	case KeyPresses::RIGHTARROW:
		if (kRIGHTARROW && !keyP[SDL_SCANCODE_RIGHT])
		{
			kRIGHTARROW = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_RIGHT]) kRIGHTARROW = true;
			return false;
		}
	case KeyPresses::UPARROW:
		if (kUPARROW && !keyP[SDL_SCANCODE_UP])
		{
			kUPARROW = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_UP]) kUPARROW = true;
			return false;
		}
	case KeyPresses::DOWNARROW:
		if (kDOWNARROW && !keyP[SDL_SCANCODE_DOWN])
		{
			kDOWNARROW = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_DOWN]) kDOWNARROW = true;
			return false;
		}
	case KeyPresses::INSERT:
		if (kINSERT && !keyP[SDL_SCANCODE_INSERT])
		{
			kINSERT = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_INSERT]) kINSERT = true;
			return false;
		}
	case KeyPresses::NUMPAD1:
		if (kNUMPAD1 && !keyP[SDL_SCANCODE_INTERNATIONAL1])
		{
			kNUMPAD1 = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_INTERNATIONAL1]) kNUMPAD1 = true;
			return false;
		}
	case KeyPresses::NUMPAD2:
		if (kNUMPAD2 && !keyP[SDL_SCANCODE_INTERNATIONAL2])
		{
			kNUMPAD2 = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_INTERNATIONAL2]) kNUMPAD2 = true;
			return false;
		}
	case KeyPresses::NUMPAD3:
		if (kNUMPAD3 && !keyP[SDL_SCANCODE_INTERNATIONAL3])
		{
			kNUMPAD3 = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_INTERNATIONAL3]) kNUMPAD3 = true;
			return false;
		}
	case KeyPresses::NUMPAD4:
		if (kNUMPAD4 && !keyP[SDL_SCANCODE_INTERNATIONAL4])
		{
			kNUMPAD4 = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_INTERNATIONAL4]) kNUMPAD4 = true;
			return false;
		}
	case KeyPresses::NUMPAD5:
		if (kNUMPAD5 && !keyP[SDL_SCANCODE_INTERNATIONAL5])
		{
			kNUMPAD5 = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_INTERNATIONAL5]) kNUMPAD5 = true;
			return false;
		}
	case KeyPresses::NUMPAD6:
		if (kNUMPAD6 && !keyP[SDL_SCANCODE_INTERNATIONAL6])
		{
			kNUMPAD6 = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_INTERNATIONAL6]) kNUMPAD6 = true;
			return false;
		}
	case KeyPresses::NUMPAD7:
		if (kNUMPAD7 && !keyP[SDL_SCANCODE_INTERNATIONAL7])
		{
			kNUMPAD7 = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_INTERNATIONAL7]) kNUMPAD7 = true;
			return false;
		}
	case KeyPresses::NUMPAD8:
		if (kNUMPAD8 && !keyP[SDL_SCANCODE_INTERNATIONAL8])
		{
			kNUMPAD8 = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_INTERNATIONAL8]) kNUMPAD8 = true;
			return false;
		}
	case KeyPresses::NUMPAD9:
		if (kNUMPAD9 && !keyP[SDL_SCANCODE_INTERNATIONAL9])
		{
			kNUMPAD9 = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_INTERNATIONAL9]) kNUMPAD9 = true;
			return false;
		}
	case KeyPresses::ONE:
		if (kONE && !keyP[SDL_SCANCODE_1])
		{
			kONE = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_1]) kONE = true;
			return false;
		}
	case KeyPresses::TWO:
		if (kTWO && !keyP[SDL_SCANCODE_2])
		{
			kTWO = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_2]) kTWO = true;
			return false;
		}
	case KeyPresses::THREE:
		if (kTHREE && !keyP[SDL_SCANCODE_3])
		{
			kTHREE = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_3]) kTHREE = true;
			return false;
		}
	case KeyPresses::FOUR:
		if (kFOUR && !keyP[SDL_SCANCODE_4])
		{
			kFOUR = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_4]) kFOUR = true;
			return false;
		}
	case KeyPresses::FIVE:
		if (kFIVE && !keyP[SDL_SCANCODE_5])
		{
			kFIVE = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_5]) kFIVE = true;
			return false;
		}
	case KeyPresses::SIX:
		if (kSIX && !keyP[SDL_SCANCODE_6])
		{
			kSIX = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_6]) kSIX = true;
			return false;
		}
	case KeyPresses::SEVEN:
		if (kSEVEN && !keyP[SDL_SCANCODE_7])
		{
			kSEVEN = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_7]) kSEVEN = true;
			return false;
		}
	case KeyPresses::EIGHT:
		if (kEIGHT && !keyP[SDL_SCANCODE_8])
		{
			kEIGHT = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_8]) kEIGHT = true;
			return false;
		}
	case KeyPresses::NINE:
		if (kNINE && !keyP[SDL_SCANCODE_9])
		{
			kNINE = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_9]) kNINE = true;
			return false;
		}
	case KeyPresses::CERO:
		if (kCERO && !keyP[SDL_SCANCODE_0])
		{
			kCERO = true;
			return true;
		}
		else
		{
			if (keyP[SDL_SCANCODE_0]) kCERO = true;
			return false;
		}
	case KeyPresses::MOUSEBUTTON1:
		if (kMOUSEBUTTON1 && !keyP[SDL_BUTTON_LEFT])
		{
			kMOUSEBUTTON1 = true;
			return true;
		}
		else
		{
			if (keyP[SDL_BUTTON_LEFT]) kMOUSEBUTTON1 = true;
			return false;
		}
	case KeyPresses::MOUSEBOTTON2:
		if (kMOUSEBUTTON2 && !keyP[SDL_BUTTON_RIGHT])
		{
			kMOUSEBUTTON2 = true;
			return true;
		}
		else
		{
			if (!keyP[SDL_BUTTON_RIGHT]) kMOUSEBUTTON2 = true;
			return false;
		}
		return true;
		}
	}
}

Inputs::Inputs()
{
}


Inputs::~Inputs()
{
}
