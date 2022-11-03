#include "InfoLevel.h"

bool InfoLevel::check(logLevel priority)
{
    return priority <= INFOLVL;
}

const char* InfoLevel::get_sentence(int key)
{
    InfoMessage message;
    return message.get_message(key);
}
