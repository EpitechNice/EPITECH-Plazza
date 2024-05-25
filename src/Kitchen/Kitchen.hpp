/*                                                                                      *
 * EPITECH PROJECT - Fri, May, 2024                                                     *
 * Title           - EPITECH-Plazza                                                     *
 * Description     -                                                                    *
 *     Kitchen                                                                          *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  *
 *                                                                                      *
 *         ░        ░       ░░        ░        ░        ░░      ░░  ░░░░  ░             *
 *         ▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒  ▒▒▒▒  ▒             *
 *         ▓      ▓▓▓       ▓▓▓▓▓  ▓▓▓▓▓▓▓  ▓▓▓▓      ▓▓▓  ▓▓▓▓▓▓▓        ▓             *
 *         █  ███████  ██████████  ███████  ████  ███████  ████  █  ████  █             *
 *         █        █  ███████        ████  ████        ██      ██  ████  █             *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  */

#ifndef KITCHEN_HPP
    #define KITCHEN_HPP

    #include "includes.hpp"
    #include "../Chef/Chef.hpp"

namespace Plazza
{
    enum class PizzaType {
        Regina      = 1 << 0,
        Margarita   = 1 << 1,
        Americana   = 1 << 2,
        Fantasia    = 1 << 3
    };

    enum class PizzaSize {
        S           = 1 << 0,
        M           = 1 << 1,
        L           = 1 << 2,
        XL          = 1 << 3,
        XXL         = 1 << 4
    };

    enum class Ingredients {
        Dough       = 1 << 0,
        Tomato      = 1 << 1,
        Gruyere     = 1 << 2,
        Ham         = 1 << 3,
        Mushrooms   = 1 << 4,
        Eggplant    = 1 << 5,
        GoatCheese  = 1 << 6,
        ChiefLove   = 1 << 7,
        Steak       = 1 << 8
    };

    class Kitchen: Flint::Inspection<Kitchen>
    {
        private:
            std::mutex _mutex;
            std::thread _monitorThread;
            pid_t _pid;

            double _multiplierCooking;
            std::vector<Chef> _chefs;
            int _restockTime;

            std::map<Ingredients, int> _ingredientsStock;

            bool _running;
            bool _toClose;

            void monitorActivity();

        public:
            Kitchen(double multiplierCooking, int numChefs, int restockTime);
            ~Kitchen();

            bool isAvailable(const std::map<Ingredients, int>& requiredIngredients);
            void preparePizza(const std::string& name, const std::string& size);
            int checkCooksStatus();
            int checkIngredients();
            int calculateCookingTime(const std::string& name, const std::string& size);
            void restockIngredients();

            void startMonitoring(); // Démarrer la surveillance
            void stopMonitoring(); // Arrêter la surveillance

            std::string getIngredientName(Ingredients ingredient);
            bool getClose();

            void displayStatus();

            std::string str() const;
    };
}

#endif // KITCHEN_HPP
