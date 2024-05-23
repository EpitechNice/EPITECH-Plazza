/*                                                                                      *
 * EPITECH PROJECT - Fri, May, 2024                                                     *
 * Title           - EPITECH-Plazza                                                     *
 * Description     -                                                                    *
 *     Manager                                                                          *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  *
 *                                                                                      *
 *       ▄▀▀█▄▄▄▄  ▄▀▀▄▀▀▀▄  ▄▀▀█▀▄    ▄▀▀▀█▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▄▄▄▄   ▄▀▀▄ ▄▄             *
 *      ▐  ▄▀   ▐ █   █   █ █   █  █  █    █  ▐ ▐  ▄▀   ▐ █ █    ▌ █  █   ▄▀            *
 *        █▄▄▄▄▄  ▐  █▀▀▀▀  ▐   █  ▐  ▐   █       █▄▄▄▄▄  ▐ █      ▐  █▄▄▄█             *
 *        █    ▌     █          █        █        █    ▌    █         █   █             *
 *       ▄▀▄▄▄▄    ▄▀        ▄▀▀▀▀▀▄   ▄▀        ▄▀▄▄▄▄    ▄▀▄▄▄▄▀   ▄▀  ▄▀             *
 *       █    ▐   █         █       █ █          █    ▐   █     ▐   █   █               *
 *       ▐        ▐         ▐       ▐ ▐          ▐        ▐         ▐   ▐               *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  */


#include "Manager.hpp"

namespace Plazza
{
    Manager Manager::_instance;

    Manager& Manager::getInstance()
    {
        return _instance;
    }

//TODO : Review
    void Manager::receiveOrder(const std::string& order)
    {
        std::stringstream ss(order);
        std::string token;

        if (order == "status") {
            this->displayStatus();
            return;
        }
        while (std::getline(ss, token, ';')) {
            this->preparePizza(token);
            this->manageKitchens();
        }
    }

    void Manager::manageKitchens()
    {
        const auto waitTime = std::chrono::seconds(10);

        for (auto& kitchen : this->_kitchenList) {
            if (kitchen->checkCooksStatus() == 1 && kitchen->checkIngredients() == 1) {
                std::this_thread::sleep_for(waitTime);
                kitchen->restockIngredients();
            }
        }
    }

    void Manager::preparePizza(const std::string& pizza)
    {
        std::string name;
        std::string size;
        int quantity = 1;
        int multiplier;
        std::stringstream ss(pizza);
        std::map<Ingredients, int> requiredIngredients = {{Ingredients::Dough, 0}};
        bool pizzaPrepared = false;

        ss >> name >> size;
        if (ss.peek() == 'x') {
            ss.ignore();
            ss >> quantity;
        }
        ss >> multiplier;

        if (name == "Margarita") {
            requiredIngredients = {{Ingredients::Dough, 1}, {Ingredients::Tomato, 1}, {Ingredients::Gruyere, 1}};
        } else if (name == "Regina") {
            requiredIngredients = {{Ingredients::Dough, 1}, {Ingredients::Tomato, 1}, {Ingredients::Gruyere, 1}, {Ingredients::Ham, 1}, {Ingredients::Mushrooms, 1}};
        } else if (name == "Americana") {
            requiredIngredients = {{Ingredients::Dough, 1}, {Ingredients::Tomato, 1}, {Ingredients::Gruyere, 1}, {Ingredients::Steak, 1}};
        } else if (name == "Fantasia") {
            requiredIngredients = {{Ingredients::Dough, 1}, {Ingredients::Tomato, 1}, {Ingredients::Gruyere, 1}, {Ingredients::Eggplant, 1}, {Ingredients::GoatCheese, 1}, {Ingredients::ChiefLove, 1}};
        } else {
            std::cout << "Unknown pizza type." << std::endl;
            return;
        }
        for (int i = 0; i < quantity; ++i) {
            for (auto& kitchen : this->_kitchenList) {
                if (kitchen->isAvailable(requiredIngredients)) {
                    kitchen->preparePizza(name, size, multiplier);
                    pizzaPrepared = true;
                    break;
                }
            }
            if (!pizzaPrepared) {
                this->_kitchenList.emplace_back(std::make_shared<Kitchen>(this->_numChefs));
                this->_kitchenList.back()->preparePizza(name, size, multiplier);
            }
        }
    }

    void Manager::setNumChefs(int num)
    {
        this->_numChefs = num;
    }

    void Manager::setRestockTime(int time)
    {
        this->_restockTime = time;
    }

    void Manager::displayStatus()
    {
        int kitchenNumber = 1;

        for (const auto& kitchen : this->_kitchenList) {
            std::cout << "Kitchen " << kitchenNumber << " Status:" << std::endl;
            kitchen->displayStatus();
            kitchenNumber++;
        }
    }

    std::string Manager::str() const
    {
        return make_str(display_attr(_numChefs) << ", " << display_attr(_restockTime));
    }
}