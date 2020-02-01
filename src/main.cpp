
/**
 * @file main.cpp
 * @author pierre fromager (info@pier-infor.fr)
 * 
 * @brief introduction aux threads en c++11 (// programming)
 * 
 * Objectifs :
 * + Utiliser 2 objets : un additionneur et un multiplicateur
 * + Séparer les traitements commutatifs des non commutatifs afin de préserver le résultat
 * 
 * Moyens :
 * + 2 pools de threads avec chacun 2 thread / pool
 * + 2 exécution de pool distinct
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

typedef std::thread Thread;
typedef std::vector<Thread> ThreadPool;

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

  // définition pool pour les tâches des opérations commutatives
  ThreadPool pnc = {};
  pnc.push_back(std::thread(&Padd::task, &a, 10)); // ajouter 10
  pnc.push_back(std::thread(&Padd::task, &a, -3)); // soustrait 3
  for (std::thread &tnc : pnc)
    tnc.join();

  // définition pool pour les tâches de traitement des opérations non commutatives
  ThreadPool pco = {};
  pco.push_back(std::thread(&Pmul::task, &m, 10)); // multiplier x10
  pco.push_back(std::thread(&Pmul::task, &m, .5)); // diviser x2
  for (std::thread &tco : pco)
    tco.join();

  // le résultat est toujours 40
  msg.add("Valeur finale " + std::to_string(v));
  msg.display();
  assert(v == expected);

  return 0;
}