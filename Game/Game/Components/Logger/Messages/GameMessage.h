#pragma once
#include "IMessage.h"
class GameMessage : public IMessage
{
public:
	enum type{START, OVER, PAUSED, SAVED};
	const char* get_message(int key) override;
};

