#pragma once
#include "../Field/Field.h"
template <typename... Rules>
class LevelGenerator
{
public:
	Field* setRules();

	template<typename RuleType>
	void establish(Field*);
};

template<typename ...Rules>
Field* LevelGenerator<Rules...>::setRules()
{
	Field* field = new Field;
	
	(establish<Rules>(field), ...);
	
	return field;
}

template<typename ...Rules>
template<typename RuleType>
void LevelGenerator<Rules...>::establish(Field* field)
{
	RuleType obj;
	obj.establish(field);
}
