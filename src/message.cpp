
#include "message.hpp"

using namespace tutothreads;

Message::Message()
{
    init();
}

Message::~Message()
{
    init();
}

void Message::init()
{
    m_messages.clear();
}

void Message::add(const std::string &msg)
{
    mtx.lock();                                                       // on vérouille
    m_messages.push_back(std::to_string(microtime()) + " -> " + msg); // on traite
    mtx.unlock();                                                     // on dévérouille
}

void Message::display()
{
    for (std::string msg : m_messages)
    {
        std::cout << msg << std::endl;
    }
}

double Message::microtime()
{
    return (double(
                std::chrono::duration_cast<std::chrono::microseconds>(
                    std::chrono::system_clock::now().time_since_epoch())
                    .count()) /
            double(1000000));
}