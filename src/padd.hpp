
#ifndef MYTHREAD_PADD_HPP
#define MYTHREAD_PADD_HPP

#include <mutex>
#include "message.hpp"

namespace tutothreads
{

typedef std::mutex Mtx;

class Padd
{

public:
    explicit Padd(int &cpt, Message &msgman);
    ~Padd();
    void task(int acc);

private:
    int &m_cpt;
    Mtx mtx;
    Message &m_msgman;
};

} // namespace mythreads

#endif