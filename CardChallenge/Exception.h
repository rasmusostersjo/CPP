#ifndef EXCEPTION_H
#define EXCEPTION_H

// Libraries
#include "DefaultValues.h"
#include <stdexcept>        // runtime_error
#include <string>           // string

class write_error : public std::runtime_error {
public:
    
    /** (Default) constructor
     *
     * @param what_arg      Error message.
     */
    write_error(const std::string& what_arg = WRITE_ERROR);
};

class read_error : public std::runtime_error {
public:
    
    /** (Default) constructor
     *
     * @param what_arg      Error message.
     */
    read_error(const std::string& what_arg = READ_ERROR);
};

#endif // EXCEPTION_H
