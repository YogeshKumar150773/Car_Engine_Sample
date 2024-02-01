#ifndef EMPTYCONTAINEREXCEPTION_H
#define EMPTYCONTAINEREXCEPTION_H

#include <stdexcept>
#include <cstring>

class EmptyContainerException
{
private:
    char *_msg;

public:
    EmptyContainerException() = delete;
    ~EmptyContainerException() = default;
    EmptyContainerException(const EmptyContainerException &) = default;
    EmptyContainerException(EmptyContainerException &&) = default;
    EmptyContainerException &operator=(const EmptyContainerException &) = default;
    EmptyContainerException &operator=(EmptyContainerException &&) = delete;
    explicit EmptyContainerException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        (strcpy(_msg, msg));
    }

    virtual const char *what() { return _msg; }
};

#endif // EMPTYCONTAINEREXCEPTION_H
