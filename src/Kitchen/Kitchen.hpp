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
    #include "../Process/Process.hpp"

namespace Plazza
{
    class Kitchen: public Flint::Inspection<Kitchen>
    {
        private:
            bool _running;
            // Plazza::Process _process;

            double _multiplierCooking;
            int _restockTime;

            std::vector<std::shared_ptr<Plazza::Chef>> _chefs;

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

            std::mutex _isOver;

        public:
            Kitchen(double multiplierCooking, int numChefs, int restockTime);
            ~Kitchen() = default;


            bool isAvailable(const std::map<Ingredients, int>& requiredIngredients);
            std::string getIngredientName(Ingredients ingredient);
            void displayStatus();

            void waitDeath();

            std::string str() const;
    };

}
#endif
