#pragma once
#include "LogLevel.h"
class ILogObserver
{
public:
    virtual void update(LogLevel*, int) = 0;
};

