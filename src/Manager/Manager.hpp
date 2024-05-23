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
    #include "../Serveur/Serveur.hpp"


namespace Plazza
{
    class Manager: Flint::Inspection<Manager> {
    private:
        static Manager _instance;
        std::mutex _mutex;
        std::vector<std::shared_ptr<Kitchen>> _kitchenList;
        int _numChefs = 3;
        int _restockTime;
        Manager() : _numChefs(0), _restockTime(0) {}

    public:
        static Manager& getInstance();

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