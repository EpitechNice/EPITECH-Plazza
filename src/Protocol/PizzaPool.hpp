/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, May, 2024                                                     *
 * Title           - Plazza                                                             *
 * Description     -                                                                    *
 *     PizzaPool                                                                        *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       ▄▀▀█▄▄▄▄  ▄▀▀▄▀▀▀▄  ▄▀▀█▀▄    ▄▀▀▀█▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▄▄▄▄   ▄▀▀▄ ▄▄             *
 *      ▐  ▄▀   ▐ █   █   █ █   █  █  █    █  ▐ ▐  ▄▀   ▐ █ █    ▌ █  █   ▄▀            *
 *        █▄▄▄▄▄  ▐  █▀▀▀▀  ▐   █  ▐  ▐   █       █▄▄▄▄▄  ▐ █      ▐  █▄▄▄█             *
 *        █    ▌     █          █        █        █    ▌    █         █   █             *
 *       ▄▀▄▄▄▄    ▄▀        ▄▀▀▀▀▀▄   ▄▀        ▄▀▄▄▄▄    ▄▀▄▄▄▄▀   ▄▀  ▄▀             *
 *       █    ▐   █         █       █ █          █    ▐   █     ▐   █   █               *
 *       ▐        ▐         ▐       ▐ ▐          ▐        ▐         ▐   ▐               *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#ifndef INCLUDED_PIZZAPOOL_HPP
    #define INCLUDED_PIZZAPOOL_HPP

    #include "includes.hpp"

namespace Plazza
{
    class PizzaPool: public Flint::Inspection<PizzaPool>
    {
        private:
            std::deque<std::pair<Plazza::PizzaType, Plazza::PizzaSize>> _todo;
            std::deque<std::pair<Plazza::PizzaType, Plazza::PizzaSize>> _done;

            // Those will NOT be used as "normal" mutex :
            // We will also use them to block functions while no pizza are asked
            std::mutex _pizzaToDo;     // Used to block the startDoPizza util a pizza is asked
            std::mutex _pizzaToReturn; // Used to block the getPizzaDone util a pizza is made

        public:
            PizzaPool();
            ~PizzaPool();

            std::pair<Plazza::PizzaType, Plazza::PizzaSize> startDoPizza();
            void pizzaDone(std::pair<Plazza::PizzaType, Plazza::PizzaSize> pizza);

            void askForPizza(std::pair<Plazza::PizzaType, Plazza::PizzaSize> pizza);
            std::pair<Plazza::PizzaType, Plazza::PizzaSize> getPizzaDone();

            // std::string str() const;
    };
}

#endif
