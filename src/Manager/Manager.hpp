/*                                                                                      *
 * EPITECH PROJECT - Fri, May, 2024                                                     *
 * Title           - EPITECH-Plazza                                                     *
 * Description     -                                                                    *
 *     Manager                                                                          *
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

#ifndef MANAGER_HPP
    #define MANAGER_HPP

    #include "includes.hpp"
    #include "../Kitchen/Kitchen.hpp"

namespace Plazza
{
    class Manager: Flint::Inspection<Manager> {
    private:
        std::mutex _mutex;
        std::vector<std::shared_ptr<Kitchen>> _kitchenList;
        int _numChefs = 3;
        int _restockTime;

    public:
        Manager() : _numChefs(0), _restockTime(0) {}
        ~Manager() = default;

        void receiveOrder(const std::string& order);
        void manageKitchens();
        void preparePizza(const std::string& pizza);
        void displayStatus();

        void setNumChefs(int num);
        void setRestockTime(int time);

        std::string str() const;
    };
}

#endif // MANAGER_HPP