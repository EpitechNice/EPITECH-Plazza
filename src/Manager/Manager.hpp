#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <vector>
#include <string>
#include "../Kitchen/Kitchen.hpp"


class Manager: Flint::Inspection<Manager> {
private:
    static Manager instance;
    std::mutex mtx;
    std::vector<Kitchen*> kitchens;
    int numChefs = 3;
    int restockTime;

    Manager() : numChefs(0), restockTime(0) {}

public:
    static Manager& getInstance();
    void receiveOrder(const std::string& order);
    void manageKitchens();
    void preparePizza(const std::string& pizza);
    void displayStatus();  // Ajout de cette méthode
    void setNumChefs(int num);
    void setRestockTime(int time);
    std::string str() const;
};

#endif // MANAGER_HPP