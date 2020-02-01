
#include "psub.hpp"

using namespace tutothreads;

Psub::Psub(int &cpt, Message &msgman) : m_cpt(cpt), m_msgman(msgman)
{
}

Psub::~Psub()
{
}

void Psub::task(int acc)
{
    m_msgman.add("Psub tâche entrée");
    m_msgman.add("Psub tâche avant v : " + std::to_string(m_cpt));
    mtx.lock(); // on vérouille
    m_cpt -= acc; // on traite
    mtx.unlock(); // on dévérouille
    m_msgman.add("Psub tâche après v : " + std::to_string(m_cpt));
    m_msgman.add("Psub tâche sortie");
}