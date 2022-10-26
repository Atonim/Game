#pragma once
class IMessage
{
public:
	virtual const char* get_message(int key) = 0;
};

