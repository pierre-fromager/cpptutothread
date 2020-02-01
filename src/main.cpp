
/**
 * @file main.cpp
 * @author pierre fromager (info@pier-infor.fr)
 * 
 * @brief introduction aux threads avec objets en c++11 (// programming)
 * 
 * Objectifs :
 * + Utiliser 2 objets : un additionneur et un multiplicateur
 * + Séparer les traitements commutatifs des non commutatifs afin de préserver le résultat
 * 
 * Moyens :
 * + 2 pools de threads avec chacun 2 thread / pool
 * + 2 exécution de pool distinct
 * 
 * Vérifications :
 * + lancer le programme plusieurs fois et comparer le déroulement
 * 
 * @version 0.1
 * @date 2020-02-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <thread>
#include <vector>
#include "message.hpp"
#include "padd.hpp"
#include "pmul.hpp"
#include <assert.h>

using namespace tutothreads;

typedef typename std::thread Thread;
typedef typename std::vector<Thread> ThreadPool;

// thread initiale programme principal
int main()
{

  // ma valeur de départ utilisée par nos threads
  double v = 1;
  const double expected = 40;

  // Les instances partagés dans les threads
  Message msg;    // Messager
  Padd a(v, msg); // Additioneur utilise v + msg en référence
  Pmul m(v, msg); // Multiplicateur utilise v + msg en référence

  // définition pool pour tâches d'opérations commutatives
  ThreadPool pnc = {};
  pnc.push_back(Thread(&Padd::task, &a, 10)); // +10
  pnc.push_back(Thread(&Padd::task, &a, -3)); // -3
  for (Thread &tnc : pnc)
    tnc.join();

  // définition pool pour tâches d'opérations non commutatives
  ThreadPool pco = {};
  pco.push_back(Thread(&Pmul::task, &m, 10)); // *10
  pco.push_back(Thread(&Pmul::task, &m, .5)); // /2
  for (Thread &tco : pco)
    tco.join();

  msg.add("Valeur finale " + std::to_string(v));
  msg.display();
  assert(v == expected);

  return 0;
}