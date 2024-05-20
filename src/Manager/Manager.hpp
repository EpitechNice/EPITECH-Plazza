#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <string>
#include <vector>
#include <mutex>
#include "Kitchen.hpp"

class Manager {
private:
    std::mutex mtx;
    std::vector<Kitchen> kitchens;
    int numChefs;
    Manager() {}
    static Manager instance;

public:
    Manager() : numChefs(3) {}
    static Manager& getInstance();
    void receiveOrder(const std::string& order, int nbrChefs);
    void manageKitchens();
    void preparePizza(const std::string& pizza);
};

#endif // MANAGER_HPP
