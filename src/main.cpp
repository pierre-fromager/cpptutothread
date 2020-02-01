
/**
 * @file main.cpp
 * @author pierre fromager (info@pier-infor.fr)
 * 
 * @brief introduction aux threads en c++
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
#include "psub.hpp"

using namespace tutothreads;

typedef std::vector<std::thread> ThreadPool;

// thread initiale programme principal
int main()
{

  // ma valeur de départ
  int v = 10;

  // Les instances partagés dans les threads
  Message m;    // Messager
  Padd a(v, m); // Additioneur qui utilise la valeur et le messager en référence
  Psub s(v, m); // Soustracteur qui utilise la valeur et le messager en référence

  // on définit une pile de thread
  ThreadPool p = {};

  // on prépare les tâches de traitement dans 4 threads concurrentes
  p.push_back(std::thread(&Padd::task, &a, 10)); // ajouter 10
  p.push_back(std::thread(&Psub::task, &s, 3));  // enlever 3

  // on lance les tâches en // sans savoir par laquelle on commence
  for (std::thread &t : p)
  {
    t.join();
  }

  m.add("Valeur finale " + std::to_string(v));
  m.display(); // le résultat est toujours 17 car les tâches sont commutatives

  return 0;
}