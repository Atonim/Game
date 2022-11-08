#pragma once
#include "IMessage.h"
class ErrMessage : public IMessage
{
public:
	enum type{FIELD, WALLS, OVERHEAL};
	const char* get_message(int key) override;
};
//возвращает ошибки

