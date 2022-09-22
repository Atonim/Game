#pragma once
#include <iostream>
#include <Windows.h>
#include "Field.h"
#include "Player.h"
#include "Cell.h"
#include "CellView.h"

class FieldView
{
	CellView cellView;
public:
	void DrawField(Field&);
};

