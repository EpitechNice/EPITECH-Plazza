// kitchen.hpp
#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include <map>
#include <mutex>
#include "Chef.hpp"

enum class PizzaType {
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};

enum class PizzaSize {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

enum class Ingredients {
    Dough = 1,
    Tomato = 2,
    Gruyere = 4,
    Ham = 8,
    Mushrooms = 16,
    Eggplant = 32,
    GoatCheese = 64,
    ChiefLove = 128,
    Steak = 256
};

class Kitchen {
private:
    std::mutex mtx;
    std::map<Ingredients, int> ingredientsStock;
    std::vector<Chef> chefs;

public:
    Kitchen();
    bool isAvailable(const std::string& size, const std::map<Ingredients, int>& requiredIngredients);
    void preparePizza(const std::string& name, const std::string& size, int multiplier);
    int checkCooksStatus();
    int checkIngredients();
    int calculateCookingTime(const std::string& name, const std::string& size, int multiplier);
};

#endif // KITCHEN_HPP
