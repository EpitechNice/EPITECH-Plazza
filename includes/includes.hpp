/*
** EPITECH PROJECT, 2024
** Cpp-Project-Template
** File description:
** main
*/

#ifndef INCLUDED_INCLUDES_HPP
    #define INCLUDED_INCLUDES_HPP

    #include "Flint.hpp"

namespace Plazza
{
    enum class PizzaType {
        Regina      = 1 << 0,
        Margarita   = 1 << 1,
        Americana   = 1 << 2,
        Fantasia    = 1 << 3
    };

    enum class PizzaSize {
        S           = 1 << 0,
        M           = 1 << 1,
        L           = 1 << 2,
        XL          = 1 << 3,
        XXL         = 1 << 4
    };

    enum class Ingredients {
        Dough       = 1 << 0,
        Tomato      = 1 << 1,
        Gruyere     = 1 << 2,
        Ham         = 1 << 3,
        Mushrooms   = 1 << 4,
        Eggplant    = 1 << 5,
        GoatCheese  = 1 << 6,
        ChiefLove   = 1 << 7,
        Steak       = 1 << 8
    };
}

#endif
