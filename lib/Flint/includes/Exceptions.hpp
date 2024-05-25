/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, Apr, 2024                                                     *
 * Title           - CppLib                                                             *
 * Description     -                                                                    *
 *     Exceptions                                                                       *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *             ███████╗██████╗ ██╗████████╗███████╗ ██████╗██╗  ██╗                     *
 *             ██╔════╝██╔══██╗██║╚══██╔══╝██╔════╝██╔════╝██║  ██║                     *
 *             █████╗  ██████╔╝██║   ██║   █████╗  ██║     ███████║                     *
 *             ██╔══╝  ██╔═══╝ ██║   ██║   ██╔══╝  ██║     ██╔══██║                     *
 *             ███████╗██║     ██║   ██║   ███████╗╚██████╗██║  ██║                     *
 *             ╚══════╝╚═╝     ╚═╝   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝                     *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#ifndef INCLUDED_FLINT_EXCEPTIONS_HPP
    #define INCLUDED_FLINT_EXCEPTIONS_HPP

    #include "Headers.hpp"
    #include "CxxABI.hpp"
    #include "Colors.hpp"
    #include "Preprocessor.hpp"

namespace Flint::Exceptions
{
    class Exception: public std::exception
    {
        protected:
            std::string _what;
            std::string _pretty;
            std::string _className;
            std::pair<std::pair<std::string, std::size_t>, std::string> _infos;
        public:
            Exception(std::string what = "An exception occured !",
                      std::pair<std::pair<std::string, std::size_t>, std::string> infos = {{"", 0}, ""});

            std::pair<std::pair<std::string, std::size_t>, std::string> getInfos() const;
            std::string getClassNameFromStackTrace(const std::vector<std::pair<std::string, std::size_t>>& stackTrace) const;
            std::string show(std::pair<std::pair<std::string, std::size_t>, std::string> infos) const;
            std::string display() const;
            const char* what() const noexcept override;
            friend std::ostream& operator<<(std::ostream& os, const Exceptions::Exception& obj);
    };

    class NotImplementedError: public Flint::Exceptions::Exception
    {
        public:
            NotImplementedError(std::string what = "Asked action haven't been implemented yet.",
                                std::pair<std::pair<std::string, std::size_t>, std::string> infos = {{"", 0}, ""}):
                Exception(what, infos)
            {}
    };

    class ParsingError: public Flint::Exceptions::Exception
    {
        public:
            ParsingError(std::string what = "Error while parsing.",
                         std::pair<std::pair<std::string, std::size_t>, std::string> infos = {{"", 0}, ""}):
                Exception(what, infos)
            {}
    };

    class ArgsFromExecError: public Flint::Exceptions::Exception
    {
        public:
            ArgsFromExecError(std::string what = "Error while executing program.",
                              std::pair<std::pair<std::string, std::size_t>, std::string> infos = {{"", 0}, ""}):
                Exception(what, infos)
            {}
    };

    class FIFOCreationError: public Flint::Exceptions::Exception
    {
        public:
            FIFOCreationError(std::string what = "Error while building FIFO.",
                              std::pair<std::pair<std::string, std::size_t>, std::string> infos = {{"", 0}, ""}):
                Exception(what, infos)
            {}
    };

    class ReadError: public Flint::Exceptions::Exception
    {
        public:
            ReadError(std::string what = "Error while reading from file.",
                              std::pair<std::pair<std::string, std::size_t>, std::string> infos = {{"", 0}, ""}):
                Exception(what, infos)
            {}
    };

    class WriteError: public Flint::Exceptions::Exception
    {
        public:
            WriteError(std::string what = "Error while writing to file.",
                              std::pair<std::pair<std::string, std::size_t>, std::string> infos = {{"", 0}, ""}):
                Exception(what, infos)
            {}
    };

    class InvalidCommandError: public Flint::Exceptions::Exception
    {
        public:
            InvalidCommandError(std::string what = "Command does not exists",
                              std::pair<std::pair<std::string, std::size_t>, std::string> infos = {{"", 0}, ""}):
                Exception(what, infos)
            {}
    };

    class NotFoundError: public Flint::Exceptions::Exception
    {
        public:
            NotFoundError(std::string what = "Requested ressource could not be found",
                              std::pair<std::pair<std::string, std::size_t>, std::string> infos = {{"", 0}, ""}):
                Exception(what, infos)
            {}
    };

    class ForkFailedError: public Flint::Exceptions::Exception
    {
        public:
            ForkFailedError(std::string what = "Error while running fork",
                              std::pair<std::pair<std::string, std::size_t>, std::string> infos = {{"", 0}, ""}):
                Exception(what, infos)
            {}
    };

    class InvalidReturnCodeError: public Flint::Exceptions::Exception
    {
        public:
            InvalidReturnCodeError(std::string what = "Return code was not equal to 0",
                              std::pair<std::pair<std::string, std::size_t>, std::string> infos = {{"", 0}, ""}):
                Exception(what, infos)
            {}
    };

    class LogicError: public Flint::Exceptions::Exception
    {
        public:
            LogicError(std::string what = "Logic error",
                              std::pair<std::pair<std::string, std::size_t>, std::string> infos = {{"", 0}, ""}):
                Exception(what, infos)
            {}
    };
}

#endif
