#ifndef EXCEPTION_H
#define EXCEPTION_H

// Libraries
#include "Constants.h"
#include <stdexcept>        // runtime_error
#include <string>           // string

class write_error : public std::runtime_error {
public:
    
    /** (Default) constructor
     *
     * @param what_arg      An error message.
     */
    write_error(const std::string& what_arg = WRITE_ERROR);
};

class read_error : public std::runtime_error {
public:
    
    /** (Default) constructor
     *
     * @param what_arg      An error message.
     */
    read_error(const std::string& what_arg = READ_ERROR);
};

#endif // EXCEPTION_H
