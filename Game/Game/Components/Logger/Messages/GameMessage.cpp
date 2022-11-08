#include "GameMessage.h"

const char* GameMessage::get_message(int key)
{
    switch (key) {
    case START:
        return "[GAME] Game has been started.";
    case OVER:
        return "[GAME] Game over.";
    case PAUSED:
        return "[GAME] Game has been paused.";
    case SAVED:
        return "[GAME] Game has been saved.";
    default:
        return "INCORRECT GAME LOG KEY.";
    }
}
