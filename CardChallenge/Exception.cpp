#include "Exception.h"

write_error::write_error(const std::string& what_arg)
    : std::runtime_error(what_arg)
{
}

read_error::read_error(const std::string& what_arg)
    : std::runtime_error(what_arg)
{
}
