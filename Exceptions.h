// Exceptions.h
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class ResourceLoadingException : public std::exception {
public:
    explicit ResourceLoadingException(const std::string& message) : msg(message) {}
    const char* what() const noexcept override { return msg.c_str(); }

private:
    std::string msg;
};

class ResourceNotFoundException : public std::exception {
public:
    explicit ResourceNotFoundException(const std::string& message) : msg(message) {}
    const char* what() const noexcept override { return msg.c_str(); }

private:
    std::string msg;
};

#endif // EXCEPTIONS_H
