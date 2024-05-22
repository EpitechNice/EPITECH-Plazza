#ifndef USER_HPP
#define USER_HPP

#include <string>
#include "includes.hpp"

class User: Flint::Inspection<User>
{
    public:
        User();
        void readCommand();

        std::string str() const;
};

#endif // USER_HPP
