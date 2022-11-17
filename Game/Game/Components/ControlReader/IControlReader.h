#pragma once
#include "../../Mytypes.h"
class IControlReader
{
public:
	virtual eDirection read(char) = 0;
};

