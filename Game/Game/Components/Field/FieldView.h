#pragma once
#include <iostream>
#include <Windows.h>
#include "Field.h"
#include "../Player/Player.h"
#include "Cell/Cell.h"
#include "Cell/CellView.h"
#include "../../../Menu/Menu.h"
#include <iostream>
class FieldView : public Menu
{
	CellView cellView;
public:
	void DrawField(Field*, Player*);
};

