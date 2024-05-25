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
    #include "../Process/Process.hpp"
    #include "../Protocol/PizzaPool.hpp"

namespace Plazza
{
    class Kitchen: public Flint::Inspection<Kitchen>
    {
        private:
            std::mutex _mutex;
            std::thread _monitorThread;
            Process _process;

            double _multiplierCooking;
            std::vector<std::shared_ptr<Plazza::Chef>> _chefs;
            int _restockTime;

            std::map<Ingredients, int> _ingredientsStock;

            bool _running;
            bool _toClose;

            std::shared_ptr<Plazza::PizzaPool> _pool;

            static Kitchen* instance;

            std::size_t _nbPizzaKitchen;

            void monitorActivity();

        public:
            Kitchen(double multiplierCooking, int numChefs, int restockTime, Plazza::Process process);
            ~Kitchen();

            static void sighandler(int);

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
