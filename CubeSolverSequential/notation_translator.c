#include "notation_translator.h"

const TranslatedNotation translateNotation(Notation notation)
{
	switch (notation)
	{
		case L:
			return (TranslatedNotation) { true, false, Direction_Down, CubeLayer_Left};
		case Lp:
			return (TranslatedNotation) { true, false, Direction_Up, CubeLayer_Left };
		case L2:
			return (TranslatedNotation) { true, true, Direction_Up, CubeLayer_Left };

		case R:
			return (TranslatedNotation) { true, false, Direction_Up, CubeLayer_Right };
		case Rp:
			return (TranslatedNotation) { true, false, Direction_Down, CubeLayer_Right };
		case R2:
			return (TranslatedNotation) { true, true, Direction_Down, CubeLayer_Right };

		case F:
			return (TranslatedNotation) { true, false, Direction_Right, CubeLayer_Front };
		case Fp:
			return (TranslatedNotation) { true, false, Direction_Left, CubeLayer_Front };
		case F2:
			return (TranslatedNotation) { true, true, Direction_Left, CubeLayer_Front };

		case B:
			return (TranslatedNotation) { true, false, Direction_Left, CubeLayer_Back };
		case Bp:
			return (TranslatedNotation) { true, false, Direction_Right, CubeLayer_Back };
		case B2:
			return (TranslatedNotation) { true, true, Direction_Right, CubeLayer_Back };

		case U:
			return (TranslatedNotation) { true, false, Direction_Left, CubeLayer_Top };
		case Up:
			return (TranslatedNotation) { true, false, Direction_Right, CubeLayer_Top };
		case U2:
			return (TranslatedNotation) { true, true, Direction_Right, CubeLayer_Top };

		case D:
			return (TranslatedNotation) { true, false, Direction_Right, CubeLayer_Bottom };
		case Dp:
			return (TranslatedNotation) { true, false, Direction_Left, CubeLayer_Bottom };
		case D2:
			return (TranslatedNotation) { true, true, Direction_Left, CubeLayer_Bottom };

		case M:
			return (TranslatedNotation) { true, false, Direction_Down, CubeLayer_M };
		case Mp:
			return (TranslatedNotation) { true, false, Direction_Up, CubeLayer_M };
		case M2:
			return (TranslatedNotation) { true, true, Direction_Up, CubeLayer_M };

		case E:
			return (TranslatedNotation) { true, false, Direction_Right, CubeLayer_E };
		case Ep:
			return (TranslatedNotation) { true, false, Direction_Left, CubeLayer_E };
		case E2:
			return (TranslatedNotation) { true, true, Direction_Left, CubeLayer_E };

		case S:
			return (TranslatedNotation) { true, false, Direction_Left, CubeLayer_S };
		case Sp:
			return (TranslatedNotation) { true, false, Direction_Right, CubeLayer_S };
		case S2:
			return (TranslatedNotation) { true, true, Direction_Right, CubeLayer_S };

		case x:
			return (TranslatedNotation) { false, false, Direction_Up, CubeLayer_None };
		case xp:
			return (TranslatedNotation) { false, false, Direction_Down, CubeLayer_None };
		case x2:
			return (TranslatedNotation) { false, true, Direction_Down, CubeLayer_None };

		case y:
			return (TranslatedNotation) { false, false, Direction_Left, CubeLayer_None };
		case yp:
			return (TranslatedNotation) { false, false, Direction_Right, CubeLayer_None };
		case y2:
			return (TranslatedNotation) { false, true, Direction_Right, CubeLayer_None };

		case z:
			return (TranslatedNotation) { false, false, Direction_Tilt_Right, CubeLayer_None };
		case zp:
			return (TranslatedNotation) { false, false, Direction_Tilt_Left, CubeLayer_None };
		case z2:
			return (TranslatedNotation) { false, true, Direction_Tilt_Left, CubeLayer_None };
	}
}