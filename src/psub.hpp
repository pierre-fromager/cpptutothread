
#ifndef MYTHREAD_PSUB_HPP
#define MYTHREAD_PSUB_HPP

#include <mutex>
#include "message.hpp"

namespace tutothreads
{

typedef std::mutex Mtx;

class Psub
{

public:
    explicit Psub(int &cpt, Message &msgman);
    ~Psub();
    void task(int acc);

private:
    int &m_cpt;
    Mtx mtx;
    Message &m_msgman;
};

} // namespace mythreads

#endif