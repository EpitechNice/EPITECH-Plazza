// user.hpp
#ifndef USER_HPP
#define USER_HPP

#include <string>

class User {
public:
    void takeOrder(const std::string& order);

private:
    int nbrChefs = 0;
};

#endif // USER_HPP
