#include "ErrLevel.h"

bool ErrLevel::check(logLevel priority)
{
	return priority <= ERRLVL;
}

const char* ErrLevel::get_sentence(int key)
{
	ErrMessage message;
	return message.get_message(key);
}
