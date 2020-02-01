
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
    explicit Padd(double &cpt, Message &msgman);
    ~Padd();
    void task(double acc);

private:
    double &m_cpt;
    Mtx mtx;
    Message &m_msgman;
};

} // namespace mythreads

#endif