#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <string>
#include <vector>
#include <mutex>

class Manager {
private:
    std::vector<std::string> orders;
    std::mutex mtx;
    std::vector<Kitchen> kitchens;

    Manager() {}
    static Manager instance;

public:
    static Manager& getInstance();
    void receiveOrder(const std::string& order);
    void manageKitchens();
    void preparePizza(const std::string& pizza);
};

#endif // MANAGER_HPP
