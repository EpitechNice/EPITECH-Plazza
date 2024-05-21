/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, May, 2024                                                     *
 * Title           - Plazza                                                             *
 * Description     -                                                                    *
 *     Protocol                                                                         *
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

#include "Protocol.hpp"

namespace Plazza
{
    Protocol::Protocol()
    {
        std::string filename = ".fifo";
        std::string name = "";
        while (access((filename + name).c_str(), 0) != -1)
            name += "~";
        this->_name = (filename + name);
        int this->_file = mkfifo((this->_name).c_str(), 0666);
        if (this->_file == -1)
            throw_exception(Flint::Exceptions::FIFOCreationError, "Error creating FIFO of name \"" + this->_name + "\"");
    }

    Protocol::Protocol(const std::string& filename)
    {
        this->_name = filename;
        this->_file = open(this->_name.c_str(), O_APPEND)
    }

    Protocol::~Protocol()
    {
        this->_count--;
        if (!this->_count) {
            close(this->_file);
            unlink(this->_name.c_str());
        }
    }
}