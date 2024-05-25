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
    #include "../Process/Process.hpp"

namespace Plazza
{
    class Manager: Flint::Inspection<Manager>
    {
        private:
            std::mutex _mutex;
            std::vector<std::shared_ptr<Kitchen>> _kitchenList;
            double _multiplierCooking;
            int _numChefs;
            int _restockTime;

        public:
            Manager(double multiplierCooking, int numChefs, int restockTime);
            ~Manager() = default;

            bool receiveOrder(const std::string& order);
            void manageKitchens();

            void createKitchen(void);
            void preparePizza(const std::string& pizza);
            void displayStatus();

            void setNumChefs(int num);
            void setRestockTime(int time);
            std::vector<std::string> strToWordArrayOnSteroid(const std::string& str, const std::string& delims) const;
            void stringToLower(std::string& str) const;

            std::string str() const;
    };
}

#endif // MANAGER_HPP