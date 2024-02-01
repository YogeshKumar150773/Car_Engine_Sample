#ifndef NOMATCHINGINSTANCEEXCEPTION_H
#define NOMATCHINGINSTANCEEXCEPTION_H

#include <cstring>
#include <stdexcept>

class NoMatchingInstanceException
{
private:
    char *_msg;

public:
    NoMatchingInstanceException() = delete;
    ~NoMatchingInstanceException() = default;
    NoMatchingInstanceException(const NoMatchingInstanceException &) = default;
    NoMatchingInstanceException(NoMatchingInstanceException &&) = default;
    NoMatchingInstanceException &operator=(const NoMatchingInstanceException &) = default;
    NoMatchingInstanceException &operator=(NoMatchingInstanceException &&) = delete;
    explicit NoMatchingInstanceException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        (strcpy(_msg, msg));
    }

    virtual const char *what() { return _msg; }
};

#endif // NOMATCHINGINSTANCEEXCEPTION_H
