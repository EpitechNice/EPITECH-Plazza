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
        this->count = 1;
        std::string filename = ".fifo";
        std::string name = "";
        while (access((filename + name).c_str(), 0) != -1)
            name += "~";
        int fd = mkfifo((filename + name).c_str(), 0666);
        if (fd == -1) {
            throw_exception(Flint::Exceptions::FIFOCreationError, "Error creating FIFO");
        }
        __gnu_cxx::stdio_filebuf<char> filebuf(fd, )
    }
}