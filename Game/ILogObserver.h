#pragma once
class ILogObserver
{
public:
    virtual void update(const char* message) = 0;
};

