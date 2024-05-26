/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, May, 2024                                                     *
 * Title           - Plazza                                                             *
 * Description     -                                                                    *
 *     Kitchen                                                                          *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *             ███████╗██████╗ ██╗████████╗███████╗ ██████╗██╗  ██╗                     *
 *             ██╔════╝██╔══██╗██║╚══██╔══╝██╔════╝██╔════╝██║  ██║                     *
 *             █████╗  ██████╔╝██║   ██║   █████╗  ██║     ███████║                     *
 *             ██╔══╝  ██╔═══╝ ██║   ██║   ██╔══╝  ██║     ██╔══██║                     *
 *             ███████╗██║     ██║   ██║   ███████╗╚██████╗██║  ██║                     *
 *             ╚══════╝╚═╝     ╚═╝   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝                     *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#ifndef INCLUDED_KITCHEN_HPP
    #define INCLUDED_KITCHEN_HPP

    #include "includes.hpp"
    #include "../Chef/Chef.hpp"
    #include "../Protocol/PizzaPool.hpp"
    #include "../Mutex/Mutex.hpp"
namespace Plazza
{
    class Kitchen: public Flint::Inspection<Kitchen>
    {
        private:
            Plazza::Mutex _mutex;
            Plazza::Mutex _keepRunnin;
            std::thread _monitorThread;

            double _multiplierCooking;
            std::vector<std::shared_ptr<Plazza::Chef>> _chefs;
            int _restockTime;

            std::map<Ingredients, int> _ingredientsStock = {
                {Plazza::Ingredients::Dough, 5},
                {Plazza::Ingredients::Tomato, 5},
                {Plazza::Ingredients::Gruyere, 5},
                {Plazza::Ingredients::Ham, 5},
                {Plazza::Ingredients::Mushrooms, 5},
                {Plazza::Ingredients::Eggplant, 5},
                {Plazza::Ingredients::GoatCheese, 5},
                {Plazza::Ingredients::ChiefLove, 5},
                {Plazza::Ingredients::Steak, 5},
            };

            bool _running;
            bool _toClose;

            std::shared_ptr<Plazza::PizzaPool> _pool;

            static Kitchen* instance;

            std::size_t _nbPizzaKitchen;

            void monitorActivity();

        public:
            Kitchen(double multiplierCooking, int numChefs, int restockTime);
            ~Kitchen();

            static void sighandler(int);

            bool shouldClose() const;
    void stop();
            bool isAvailable(const std::map<Ingredients, int>& requiredIngredients);
            bool preparePizza(std::string name, std::string size);
            int checkCooksStatus();
            bool checkIngredients();
            int calculateCookingTime(const std::string& name, const std::string& size);
            void restockIngredients();
            static void _restockIngredients(Kitchen* self, std::chrono::milliseconds sleepTime);
            void reducIngredients(const std::map<Ingredients, int>& ingredients);

            void startMonitoring(); // Démarrer la surveillance
            void stopMonitoring(); // Arrêter la surveillance

            std::string getIngredientName(Ingredients ingredient);
            bool getClose();

            void displayStatus();
            void waitDeath();

            std::string str() const;
    };
}

#endif // KITCHEN_HPP

// namespace Plazza
// {
//     class Kitchen: public Flint::Inspection<Kitchen>
//     {
//         private:
//             bool _running;

//             double _multiplierCooking;
//             int _restockTime;

//             std::vector<std::shared_ptr<Plazza::Chef>> _chefs;

//             std::map<Ingredients, int> _ingredientsStock = {
//                 {Plazza::Ingredients::Dough, 5},
//                 {Plazza::Ingredients::Tomato, 5},
//                 {Plazza::Ingredients::Gruyere, 5},
//                 {Plazza::Ingredients::Ham, 5},
//                 {Plazza::Ingredients::Mushrooms, 5},
//                 {Plazza::Ingredients::Eggplant, 5},
//                 {Plazza::Ingredients::GoatCheese, 5},
//                 {Plazza::Ingredients::ChiefLove, 5},
//                 {Plazza::Ingredients::Steak, 5},
//             };

//             Mutex _mutex;

//         public:
//             Kitchen(double multiplierCooking, int numChefs, int restockTime);
//             ~Kitchen();


//             bool isAvailable(const std::map<Ingredients, int>& requiredIngredients);
//             std::string getIngredientName(Ingredients ingredient);
//             void displayStatus();

//             void waitDeath();

//             std::string str() const;
//     };

// }
// #endif
