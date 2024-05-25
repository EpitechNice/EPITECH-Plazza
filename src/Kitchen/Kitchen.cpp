/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, May, 2024                                                     *
 * Title           - Plazza                                                             *
 * Description     -                                                                    *
 *     Kitchen                                                                          *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       _|_|_|_|  _|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|_|    _|_|_|  _|    _|           *
 *       _|        _|    _|    _|        _|      _|        _|        _|    _|           *
 *       _|_|_|    _|_|_|      _|        _|      _|_|_|    _|        _|_|_|_|           *
 *       _|        _|          _|        _|      _|        _|        _|    _|           *
 *       _|_|_|_|  _|        _|_|_|      _|      _|_|_|_|    _|_|_|  _|    _|           *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "Kitchen.hpp"

namespace Plazza
{
    Kitchen::Kitchen(double multiplierCooking, int numChefs, int restockTime)
    {
        this->_multiplierCooking = multiplierCooking;
        this->_restockTime = restockTime;
        for (int i = 0; i < numChefs; i++) {
            this->_chefs.push_back(std::make_shared<Plazza::Chef>(i));
        }
        std::lock_guard<std::mutex> lock(this->_mutex.getMutex());
    }

    Kitchen::~Kitchen()
    {}

    bool Kitchen::isAvailable(const std::map<Ingredients, int>& requiredIngredients)
    {
        std::lock_guard<std::mutex> lock(this->_mutex.getMutex());
        // if (this->_toClose)
        //     return false;
        bool enoughIngredients = true;

        for (const auto& ingredient : requiredIngredients) {
            if (this->_ingredientsStock[ingredient.first] < ingredient.second) {
                enoughIngredients = false;
                break;
            }
        }
        return enoughIngredients;
    }

    std::string Kitchen::getIngredientName(Ingredients ingredient)
    {
        switch (ingredient) {
            case Ingredients::Dough:
                return "Dough";
            case Ingredients::Tomato:
                return "Tomato";
            case Ingredients::Gruyere:
                return "Gruyere";
            case Ingredients::Ham:
                return "Ham";
            case Ingredients::Mushrooms:
                return "Mushrooms";
            case Ingredients::Eggplant:
                return "Eggplant";
            case Ingredients::GoatCheese:
                return "GoatCheese";
            case Ingredients::ChiefLove:
                return "ChiefLove";
            case Ingredients::Steak:
                return "Steak";
            default: return "Unknown ingredient";
        }
    }

    void Kitchen::displayStatus()
    {
        std::cout << "\tCooks status:" << std::endl;
        for (const auto& chef : this->_chefs) {
            std::cout << "\t\tChef " << chef->getId() << ": " << (chef->isAvailable() ? "Available" : "Busy") << std::endl;
        }

        std::cout << "\tIngredients stock:" << std::endl;
        for (const auto& ingredient : this->_ingredientsStock) {
            std::cout << "\t\t" << this->getIngredientName(ingredient.first) << ": " << ingredient.second << std::endl;
        }
    }

    std::string Kitchen::str() const
    {
        return make_str(display_attr(_running) << ", " << display_attr(_multiplierCooking) << ", " << display_attr(_restockTime));
    }

    void Kitchen::waitDeath()
    {
        std::lock_guard<std::mutex> lock(this->_mutex.getMutex());
    }
}

