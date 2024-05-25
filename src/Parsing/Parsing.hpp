/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, May, 2024                                                     *
 * Title           - Plazza                                                             *
 * Description     -                                                                    *
 *     Parsing                                                                          *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *         ░        ░       ░░        ░        ░        ░░      ░░  ░░░░  ░             *
 *         ▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒  ▒▒▒▒  ▒             *
 *         ▓      ▓▓▓       ▓▓▓▓▓  ▓▓▓▓▓▓▓  ▓▓▓▓      ▓▓▓  ▓▓▓▓▓▓▓        ▓             *
 *         █  ███████  ██████████  ███████  ████  ███████  ████  █  ████  █             *
 *         █        █  ███████        ████  ████        ██      ██  ████  █             *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#ifndef INCLUDED_PARSING_HPP
    #define INCLUDED_PARSING_HPP

    #include "includes.hpp"

namespace Plazza
{
    class Parsing: public Flint::Inspection<Parsing>
    {
        private:
            double _multiplierTime = 0;
            std::size_t _nbCooks = 0;
            std::size_t _refillTime = 0;
            Parsing() = default;

        public:
            ~Parsing() = default;
            static Parsing& get();

            void parse(int argc, char** argv);

            double getMultiplierTime() const;
            int getNbCooks() const;
            std::size_t getRefillTime() const;

            std::string str() const;
    };
}

#endif
