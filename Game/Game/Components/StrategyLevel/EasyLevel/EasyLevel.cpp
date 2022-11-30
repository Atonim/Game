#include "EasyLevel.h"

Field* EasyLevel::generateLevel()
{
	return this->levelGenerator.setRules();
}
