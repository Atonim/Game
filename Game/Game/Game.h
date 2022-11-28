#pragma once
#include "../Menu/Settings/FieldMenu/FieldSettings.h"
#include "Components/InputListener/InputListener.h"
#include "Components/Logic/Logic.h"
#include "Components/Field/Field.h"
#include "Components/Field/FieldView.h"
#include "Components/Player/Player.h"
#include "Components/Mediator/CommandMediator.h"
#include "Components/Controller/Controller.h"
#include "Components/LevelRunner/LevelRunner.h"
#include "Components/Logger/LogObserver/LogObserver.h"
#include "../Menu/Settings/LogMenu/LogMenu.h"
#include "Components/ControlReader/IControlReader.h"
class Game
{
public:
	void run(LogObserver*, Field*, IControlReader*);
};

