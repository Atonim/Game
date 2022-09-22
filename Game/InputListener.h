#pragma once
#include <cstdio>
#include <conio.h>
#include "Mytypes.h"
class InputListener
{
	eDirection dir;
public:
	void listen(int&);
	int getDir();
};

