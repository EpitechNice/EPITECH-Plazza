/*                                                                                      *
 * EPITECH PROJECT - Sun, May, 2024                                                     *
 * Title           - Visual Studio Live Share (Workspace)                               *
 * Description     -                                                                    *
 *     Chef                                                                             *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  *
 *                                                                                      *
 *       _|_|_|_|  _|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|_|    _|_|_|  _|    _|           *
 *       _|        _|    _|    _|        _|      _|        _|        _|    _|           *
 *       _|_|_|    _|_|_|      _|        _|      _|_|_|    _|        _|_|_|_|           *
 *       _|        _|          _|        _|      _|        _|        _|    _|           *
 *       _|_|_|_|  _|        _|_|_|      _|      _|_|_|_|    _|_|_|  _|    _|           *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  */

#ifndef CHEF_HPP
    #define CHEF_HPP

    #include "includes.hpp"

namespace Plazza
{
    class Chef: public Flint::Inspection<Chef>
    {
        private:
            std::size_t _id;

            const std::size_t _maxPizzaCount = 2;
            std::deque<std::tuple<Plazza::PizzaType, Plazza::PizzaSize, std::size_t>> _pizzas;
            std::mutex _pizzaToDo;
            bool _keepRunning;

            std::thread _thread;

        public:
            Chef(std::size_t id);
            ~Chef() = default;

            static void run(Chef* self);

            void start();
            void stop();

            void addPizza(std::pair<Plazza::PizzaType, Plazza::PizzaSize> pizza);
            bool isAvailable() const;
            std::string getType(Plazza::PizzaType type) const;
            std::string getSize(Plazza::PizzaSize size) const;
            int getId() const;


    };
}


#endif
