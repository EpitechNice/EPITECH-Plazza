/*                                                                                      *
 * EPITECH PROJECT - Tue, May, 2024                                                     *
 * Title           - Visual Studio Live Share (Workspace)                               *
 * Description     -                                                                    *
 *     Core                                                                             *
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

#include "Core.hpp"

namespace Plazza
{
    Core::Core(int argc, char **argv)
    {
        try {
            Parsing::get().parse(argc, argv);
        } catch (const Flint::Exceptions::Exception& e) {
            std::cerr << catch_exception(e) << std::endl;
            exit(84);
        }

        std::cout << "Multiplier time: " << Parsing::get().getMultiplierTime() << std::endl;
        std::cout << "Nb cooks: " << Parsing::get().getNbCooks() << std::endl;
        std::cout << "Replace time: " << Parsing::get().getReplaceTime() << std::endl;
    }

    void Core::usage(void)
    {}
}