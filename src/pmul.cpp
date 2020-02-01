
#include "pmul.hpp"

using namespace tutothreads;

Pmul::Pmul(double &cpt, Message &msgman) : m_cpt(cpt), m_msgman(msgman)
{
}

Pmul::~Pmul()
{
}

void Pmul::task(double acc)
{
    m_msgman.add("Pmul tâche entrée");
    m_msgman.add("Pmul tâche avant v : " + std::to_string(m_cpt));
    mtx.lock(); // on vérouille
    m_cpt *= acc; // on traite
    mtx.unlock(); // on dévérouille
    m_msgman.add("Pmul tâche après v : " + std::to_string(m_cpt));
    m_msgman.add("Pmul tâche sortie");
}