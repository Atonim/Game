#include "MediumLevel.h"

Field* MediumLevel::generateLevel()
{
	return this->levelGenerator.setRules();
}
