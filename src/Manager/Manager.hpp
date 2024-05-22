#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <string>
#include <vector>
#include <mutex>
#include "../Kitchen/Kitchen.hpp"
#include "includes.hpp"

class Manager: Flint::Inspection<Manager>
{
    private:
        std::mutex mtx;
        std::vector<Kitchen *> kitchens;
        int numChefs = 3;
        int restockTime;
        Manager() {}
        static Manager instance;

    public:
        static Manager& getInstance();
        void receiveOrder(const std::string& order);
        void manageKitchens();
        void preparePizza(const std::string& pizza);
        void setNumChefs(int num);
        void setRestockTime(int time);

        std::string str() const;
};

#endif // MANAGER_HPP
