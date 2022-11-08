#include "InfoMessage.h"

const char* InfoMessage::get_message(int key)
{
	switch (key) {
	case DEATH:
		return "[INFO] Hero died.";
	case DAMAGE:
		return "[INFO] Hero has been damaged.";
	case HEAL:
		return "[INFO] Hero has been healed.";
	case KEY:
		return "[INFO] Hero found a key.";
	case PRAYING:
		return "[INFO] Hero was praying to Gods.";
	case CELL:
		return "[INFO] Cell reacted to Hero and changed.";
	case VICTORY:
		return "[INFO] All keys have been found.";
	default:
		return "INCORRECT INFO LOG KEY.";
	}
}
