#pragma once
#include "ILogObserver.h"
#include "LogLevel.h"
class ILogSubject
{
public:
    virtual void attach(ILogObserver* observer) = 0;
    virtual void detach(ILogObserver* observer) = 0;
    virtual void notify(LogLevel* message, int key) = 0;
};

