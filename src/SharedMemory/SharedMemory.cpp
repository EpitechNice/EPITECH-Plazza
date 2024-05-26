/*                                                                                      *
 * EPITECH PROJECT - Mon, May, 2024                                                     *
 * Title           - EPITECH-Plazza                                                     *
 * Description     -                                                                    *
 *     SharedMemory                                                                     *
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

#include "SharedMemory.hpp"

namespace Plazza
{
    SharedMemory::SharedMemory(std::string name, size_t size)
    {
        this->_name = name;
        this->_size = size;
        this->_fd = shm_open(this->_name.c_str(), O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
        ftruncate(this->_fd, this->_size);
        this->_pool = static_cast<Plazza::SharedData*>(mmap(0, this->_size, PROT_READ | PROT_WRITE, MAP_SHARED, this->_fd, 0));
    }

    SharedMemory::~SharedMemory()
    {
        munmap(this->_pool, this->_size);
        close(this->_fd);
    }

    void SharedMemory::updateData(SharedData& newData)
    {
        memcpy(this->_pool, &newData, this->_size);
    }

    Plazza::SharedData* SharedMemory::getData() const
    {
        return this->_pool;
    }

}