#pragma once
#include "IMessage.h"
class InfoMessage : public IMessage
{
public:
	enum type{DEATH, DAMAGE, HEAL, KEY, PRAYING, CELL, VICTORY};
	const char* get_message(int key) override;
};

