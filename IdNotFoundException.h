#ifndef IDNOTFOUNDEXCEPTION_H
#define IDNOTFOUNDEXCEPTION_H

#include <cstring>
#include <stdexcept>

class IdNotFoundException
{
private:
    char *_msg;

public:
    IdNotFoundException() = delete;
    ~IdNotFoundException() = default;
    IdNotFoundException(const IdNotFoundException &) = default;
    IdNotFoundException(IdNotFoundException &&) = default;
    IdNotFoundException &operator=(const IdNotFoundException &) = default;
    IdNotFoundException &operator=(IdNotFoundException &&) = delete;
    explicit IdNotFoundException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        (strcpy(_msg, msg));
    }

    virtual const char *what() { return _msg; }
};

#endif // IDNOTFOUNDEXCEPTION_H
