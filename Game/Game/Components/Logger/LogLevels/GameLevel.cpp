#include "GameLevel.h"

bool GameLevel::check(logLevel priority)
{
    return priority <= GAMELVL;
}

const char* GameLevel::get_sentence(int key)
{
    GameMessage message;
    return message.get_message(key);
}
