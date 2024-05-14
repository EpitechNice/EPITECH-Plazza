// user.cpp
#include "user.hpp"
#include "manager.hpp"

void User::takeOrder(const std::string& order) {
    Manager::getInstance().receiveOrder(order);
}
