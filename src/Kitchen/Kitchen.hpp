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

    class Kitchen: Flint::Inspection<Kitchen>
    {
        private:
            std::mutex _mutex;
            std::thread _monitorThread;

            double _multiplierCooking;
            std::vector<Chef> _chefs;
            int _restockTime;

            std::map<Ingredients, int> _ingredientsStock;

            bool _running;

            void monitorActivity();

        public:
            Kitchen(double multiplierCooking, int numChefs, int restockTime);
            ~Kitchen();

            bool isAvailable(const std::map<Ingredients, int>& requiredIngredients);
            void preparePizza(const std::string& name, const std::string& size, int multiplier);
            int checkCooksStatus();
            int checkIngredients();
            int calculateCookingTime(const std::string& name, const std::string& size, int multiplier);
            void restockIngredients();

            void startMonitoring(); // Démarrer la surveillance
            void stopMonitoring(); // Arrêter la surveillance

            std::string getIngredientName(Ingredients ingredient);

            void displayStatus();

            std::string str() const;
    };
}

#endif // KITCHEN_HPP
