
#include "padd.hpp"

using namespace tutothreads;

Padd::Padd(int &cpt, Message &msgman) : m_cpt(cpt), m_msgman(msgman)
{
}

Padd::~Padd()
{
}

void Padd::task(int acc)
{
    m_msgman.add("Padd tâche entrée");
    m_msgman.add("Padd tâche avant v : " + std::to_string(m_cpt));
    mtx.lock();   // on vérouille
    m_cpt += acc; // on traite
    mtx.unlock(); // on dévérouille
    m_msgman.add("Padd tâche après v : " + std::to_string(m_cpt));
    m_msgman.add("Padd tâche sortie");
}