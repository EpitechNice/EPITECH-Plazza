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
        this->_running = true;
        this->_toClose = false;
        this->_multiplierCooking = multiplierCooking;
        this->_restockTime = restockTime;
        this->_nbPizzaKitchen = 0;
        this->_pool = std::make_shared<Plazza::PizzaPool>();
        for (int i = 0; i < numChefs; i++) {
            this->_chefs.push_back(std::make_shared<Plazza::Chef>(i));
        }
        this->startMonitoring();
        this->_keepRunnin.lock();
    }

    Kitchen::~Kitchen()
    {
        this->stopMonitoring();
    }

    bool Kitchen::isAvailable(const std::map<Ingredients, int>& requiredIngredients)
    {
        std::lock_guard<std::mutex> lock(this->_mutex.getMutex());
        if (this->_toClose)
            return false;
        bool enoughIngredients = true;

        for (const auto& ingredient : requiredIngredients) {
            if (this->_ingredientsStock[ingredient.first] < ingredient.second) {
                enoughIngredients = false;
                break;
            }
        }
        return enoughIngredients;
    }

    void Kitchen::reducIngredients(const std::map<Ingredients, int>& ingredients)
    {
        for (const auto& ingredient : ingredients) {
            auto it = this->_ingredientsStock.find(ingredient.first);
            if (it != this->_ingredientsStock.end()) {
                it->second -= ingredient.second;
            }
        }
    }

    bool Kitchen::preparePizza(std::string name, std::string size)
    {
        std::cout << "\tPreparing pizza " << name << " of size " << size << "..." << std::endl;
        int cookingTime = calculateCookingTime(name, size);
        bool pizzaAssigned = false;
        for (auto& chef : this->_chefs) {
            if (chef->isAvailable()) {
                chef->takeOrder();
                std::thread([=]() {
                    chef->cook(name, size, cookingTime);
                    }).detach(); // One time thread, no need for encapsulation
                this->_nbPizzaKitchen++;
                pizzaAssigned = true;
                break;
            }
        }
        if (!pizzaAssigned) {
            std::cout << "\tAll the chefs are busy. The pizza " << name << " of size " << size << " cannot be prepared at the moment." << std::endl;
        }
        return pizzaAssigned;
    }

    int Kitchen::checkCooksStatus()
    {
        for (auto& chef : this->_chefs) {
            if (chef->getNumPizzasInProgress() > 0) {
                return 0;
            }
        }
        return 1;
    }

    bool Kitchen::checkIngredients()
    {
        for (const auto& ingredient : this->_ingredientsStock) {
            if (ingredient.second < 1) {
                return true;
            }
        }
        return false;
    }

    int Kitchen::calculateCookingTime(const std::string& name, const std::string& size)
    {
        (void)size;
        int baseTime;

        if (name == "Margarita") {
            baseTime = 1;
        } else if (name == "Regina" || name == "Americana") {
            baseTime = 2;
        } else if (name == "Fantasia") {
            baseTime = 4;
        } else {
            baseTime = 0;
        }
        return baseTime * this->_multiplierCooking;
    }

    void Kitchen::restockIngredients()
    {
        std::chrono::milliseconds sleepTime(this->_restockTime);
        _restockIngredients(this, sleepTime);
    }

    void Kitchen::_restockIngredients(Kitchen* self, std::chrono::milliseconds sleepTime)
    {
        std::this_thread::sleep_for(sleepTime);
        std::lock_guard<Plazza::Mutex> lock(self->_mutex);
        if (self->_ingredientsStock[Ingredients::Dough] > 4 )
            return;
        self->_ingredientsStock[Ingredients::Dough] += 1;
        self->_ingredientsStock[Ingredients::Dough] += 1;
        self->_ingredientsStock[Ingredients::Tomato] += 1;
        self->_ingredientsStock[Ingredients::Gruyere] += 1;
        self->_ingredientsStock[Ingredients::Ham] += 1;
        self->_ingredientsStock[Ingredients::Mushrooms] += 1;
        self->_ingredientsStock[Ingredients::Eggplant] += 1;
        self->_ingredientsStock[Ingredients::GoatCheese] += 1;
        self->_ingredientsStock[Ingredients::ChiefLove] += 1;
        self->_ingredientsStock[Ingredients::Steak] += 1;
    }

    void Kitchen::monitorActivity(Kitchen* self)
    {
        std::size_t value;
        while (self->_running && !self->_toClose) {
            value = self->_nbPizzaKitchen;
            std::this_thread::sleep_for(std::chrono::seconds(5));
            if (value == self->_nbPizzaKitchen) {
                std::cout << "\rNo pizza done for 5 secs. Exiting...\n> " << std::flush;
                self->_keepRunnin.unlock();
                self->_toClose = true;
                self->_running = false;
            }
        }
    }

    bool Kitchen::shouldClose() const {
        return this->_toClose;
    }

    void Kitchen::stop() {
        this->_running = false;
        if (this->_monitorThread.joinable()) {
            this->_monitorThread.join();
        }
    }

    void Kitchen::startMonitoring()
    {
        this->_monitorThread.start(Kitchen::monitorActivity, this);
    }

    void Kitchen::stopMonitoring()
    {
        this->_running = false;
        if (this->_monitorThread.joinable()) {
            this->_monitorThread.join();
        }
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
        if (!this->_running) {
            std::cout << "\tKitchen is closed due to inactivity." << std::endl;
            return;
        }
        std::cout << "\tCooks status:" << std::endl;
        for (const auto& chef : this->_chefs) {
            std::cout << "\t\tChef " << chef->getId() + 1 << ": " << (chef->isAvailable() ? "Available" : "Busy") << std::endl;
        }

        std::cout << "\tIngredients stock:" << std::endl;
        for (const auto& ingredient : this->_ingredientsStock) {
            std::cout << "\t\t" << getIngredientName(ingredient.first) << ": " << ingredient.second << std::endl;
        }
    }

    void Kitchen::waitDeath()
    {
        this->_keepRunnin.lock();
    }

    std::string Kitchen::str() const
    {
        return make_str(display_attr(_running) << ", " << display_attr(_multiplierCooking) << ", " << display_attr(_restockTime));
    }
}
