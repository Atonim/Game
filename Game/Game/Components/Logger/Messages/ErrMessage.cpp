#include "ErrMessage.h"

const char* ErrMessage::get_message(int key)
{
    switch (key) {
    case WALLS:
        return "[ERROR] Hero cannot pass through the walls.";
    case FIELD:
        return "[ERROR] Incorrect field size input.";
    case OVERHEAL:
        return "[ERROR] Hero has full HP and cannot be healed.";
    default:
        return "INCORRECT ERROR LOG KEY.";
    }
}
