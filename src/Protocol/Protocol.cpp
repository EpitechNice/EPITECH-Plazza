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
        this->_readSize = 2048;
        this->_name = ".fifo";
        std::string name = "";
        while (access((this->_name + name).c_str(), 0) != -1)
            name += "~";
        this->_name += name;
        this->_file = mkfifo(this->_name.c_str(), 0666);
        if (this->_file == -1)
            throw_exception(Flint::Exceptions::FIFOCreationError, "Error creating FIFO file \"" + this->_name + "\"");
    }

    Protocol::Protocol(const std::string& filename)
    {
        this->_readSize = 2048;
        this->_name = filename;
        this->_file = mkfifo(this->_name.c_str(), 06666);
        if (this->_file == -1)
            throw_exception(Flint::Exceptions::FIFOCreationError, "Error creating FIFO file \"" + this->_name + "\"");
    }

    Protocol::~Protocol()
    {
        close(this->_file);
    }

    size_t Protocol::getReadSize() const
    {
        return this->_readSize;
    }

    void Protocol::setReadSize(size_t size)
    {
        this->_readSize = size;
    }

    std::string Protocol::Read(size_t size)
    {
        char buffer[size + 1];
        int result = read(this->_file, buffer, size);
        if (result == -1)
            throw_exception(Flint::Exceptions::ReadError, std::string("Error while reading ") + std::to_string(size) + " bytes from the file \"" + this->_name + "\"");
        if (result == 0)
            return "";
        return std::string(buffer);
    }

    void Protocol::Write(std::string data)
    {
        int result = write(this->_file, data.c_str(), data.size());
        if (result != data.size())
            throw_exception(Flint::Exceptions::WriteError, "Error while writing \"" + data + "\" to file \"" + this->_name + "\"");
    }

    const std::string& Protocol::getName() const
    {
        return this->_name;
    }

    std::ostream& operator<<(std::ostream& os, Protocol& obj)
    {
        os << obj.Read(obj.getReadSize());
        return os;
    }

    std::string Protocol::str() const
    {
        return make_str(display_attr(_file) << ", " << display_attr(_name) << ", " << display_attr(_readSize));
    }
}