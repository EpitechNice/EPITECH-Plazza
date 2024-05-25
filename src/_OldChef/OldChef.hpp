/*                                                                                      *
 * EPITECH PROJECT - Fri, May, 2024                                                     *
 * Title           - EPITECH-Plazza                                                     *
 * Description     -                                                                    *
 *     Chef                                                                             *
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

#ifndef OLD_CHEF_HPP
    #define OLD_CHEF_HPP

    #include "includes.hpp"
    #include "../Protocol/PizzaPool.hpp"

namespace Plazza
{
    class Chef: public Flint::Inspection<Chef>
    {
        private:
            int _id;
            int _numPizzasInProgress;
            std::mutex _mutex;

            bool _keepRunning;

            std::thread _thread;

            std::pair<Plazza::PizzaType, Plazza::PizzaSize> _currentPizza;
            std::pair<Plazza::PizzaType, Plazza::PizzaSize> _nextPizza;

            std::shared_ptr<Plazza::PizzaPool> _pool;

        public:
            Chef(int id, std::shared_ptr<Plazza::PizzaPool> pool);
            ~Chef() = default;

            void cook(const std::string& name, const std::string& size, int cookingTime, std::shared_ptr<Plazza::PizzaPool> pool);

            static void runThread(Chef* self);

            void takeOrder();
            bool isAvailable() const;

            int getId() const;
            int getNumPizzasInProgress() const;

            void setNumPizzasInProgress(int num);

            std::string str() const;
    };
}

#endif // CHEF_HPP
