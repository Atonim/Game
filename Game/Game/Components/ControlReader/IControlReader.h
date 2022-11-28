#pragma once
#include "../../Mytypes.h"
#include <utility>
#include <vector>
class IControlReader
{
public:
	virtual eDirection read(char) = 0;
	virtual std::vector<std::pair<char, eDirection>>* getControl() = 0;
};

