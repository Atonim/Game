#pragma once
#include "InputListener.h"
#include "Player.h"
#include "Field.h"
#include "Mytypes.h"
//#include "SpaceEvent.h"
//#include "KeyEvent.h"
//#include "WinEvent.h"
//#include "DamageEvent.h"
//#include "LoseEvent.h"
//#include "CureEvent.h"
//#include "EventFactory.h"
//#include "PEFactory.h"
#include "KeyFactory.h"
#include "DamageFactory.h"
#include "CureFactory.h"
#include "SpaceFactory.h"
#include "LoseFactory.h"
#include "WinFactory.h"
class Logic
{
public:
	void start(int, Field&, Player&, int&);
};

