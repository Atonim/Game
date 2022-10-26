#pragma once
#include "ILogObserver.h"
#include "IMessage.h"
class ILogSubject
{
public:
    virtual void attach(ILogObserver* observer) = 0;
    virtual void detach(ILogObserver* observer) = 0;
    virtual void notify(IMessage* message, int key) = 0;
};

