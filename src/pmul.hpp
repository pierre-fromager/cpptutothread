
#ifndef MYTHREAD_PMUL_HPP
#define MYTHREAD_PMUL_HPP

#include <mutex>
#include "message.hpp"

namespace tutothreads
{

typedef std::mutex Mtx;

class Pmul
{

public:
    explicit Pmul(double &cpt, Message &msgman);
    ~Pmul();
    void task(double acc);

private:
    double &m_cpt;
    Mtx mtx;
    Message &m_msgman;
};

} // namespace mythreads

#endif