
#ifndef MYTHREAD_MESSAGE_HPP
#define MYTHREAD_MESSAGE_HPP

#include <iostream>
#include <string>
#include <mutex>
#include <vector>
#include <chrono>

namespace tutothreads
{

typedef std::vector<std::string> Vstr;
typedef std::mutex Mtx;

class Message
{

public:
    explicit Message();
    ~Message();
    void add(std::string message);
    void display();
    void init();

private:
    double microtime();
    Vstr m_messages = {};
    Mtx mtx;
};

} // namespace mythreads

#endif