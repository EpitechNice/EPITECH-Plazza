/*                                                                                      *
 * EPITECH PROJECT - Sun, May, 2024                                                     *
 * Title           - EPITECH-Plazza                                                     *
 * Description     -                                                                    *
 *     Process                                                                          *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  *
 *                                                                                      *
 *             ███████╗██████╗ ██╗████████╗███████╗ ██████╗██╗  ██╗                     *
 *             ██╔════╝██╔══██╗██║╚══██╔══╝██╔════╝██╔════╝██║  ██║                     *
 *             █████╗  ██████╔╝██║   ██║   █████╗  ██║     ███████║                     *
 *             ██╔══╝  ██╔═══╝ ██║   ██║   ██╔══╝  ██║     ██╔══██║                     *
 *             ███████╗██║     ██║   ██║   ███████╗╚██████╗██║  ██║                     *
 *             ╚══════╝╚═╝     ╚═╝   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝                     *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  */

#include "Process.hpp"

namespace Plazza
{
    Process::Process():
        _pid(0), _running(false)
    {
        this->_running = false;
        this->_pid = fork();

        if (this->_pid == -1)
            throw_exception(Flint::Exceptions::ForkFailedError, "Fork failed.");
        //In child processus
        if (this->_pid == 0) {
            this->_running = false;
            this->_type = processType::CHILD;
            std::cout << "New child: " << Flint::Colors::F_PURPLE << getpid() << Flint::Colors::RESET << std::endl;
        } else {
        //In parent processus
            this->_running = true;
            this->_type = processType::PARENT;
        }
    }

    Process::~Process()
    {
        if (this->_running)
            this->killPid();
    }

    void Process::wait(void)
    {
        int return_value;
        if (this->_running) {
            if (waitpid(this->_pid, &return_value, 0) <= 0)
                throw_exception(Flint::Exceptions::InvalidReturnCodeError, "Awaited return code 0 but got " + std::to_string(return_value));
            this->_running = false;
        }
    }

    void Process::killPid(void)
    {
        if (this->_running) {
            kill(this->_pid, SIGUSR2);
            this->_running = false;
        }
    }

    processType Process::getType() const
    {
        return this->_type;
    }
}