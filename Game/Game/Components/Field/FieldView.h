#pragma once
#include <iostream>
#include <Windows.h>
#include "Field.h"
#include "../Player/Player.h"
#include "Cell/Cell.h"
#include "Cell/CellView.h"
#include <iostream>
class FieldView
{
	CellView cellView;
public:
	void DrawField(Field*, Player*);
};

