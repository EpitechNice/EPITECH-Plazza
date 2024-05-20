#include "User.hpp"
#include "Manager.hpp"

void User::takeOrder(const std::string& order) {
    Manager::getInstance().receiveOrder(order, nbrChefs);
}
