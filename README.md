# Cpp tuto thread

Ce projet est un tutoriel montrant comment utiliser les threads en c++11.  
On utilisera la méthode de vérouillage par mutex disponible dans la STL(librairie standard).  
Cette dernière n'est pas la meilleure en terme de performance mais il faut bien commencer par quelque part.  
La programmation parallèle est un vaste sujet qui fait apparaître la notion de concurence.  
Pour se réprésenter la notion de concurence il faut aborder la différence entre un code bloquant(synchrone) et un code non bloquant (aynchrone).  

## Build

* make (compile les source dans ./build/demo).
* make check (vérifie le source).

## Run

* ./build/demo

## Historique

C et C++ sont nativement bloquants comme beaucoup d'autres langages compilés.  
La différence se fera par l'utilisation de bibliothèques tièrces liées au parallélisme.  
La concurence nécessite la mise en place de mécanismes particuliers lors de l'implémentation du code.  
Reprendre un projet implémenté dans une thread unique(main) et le tranformer en projet multithreads peut s'avérer couteux.

### Synchrone

Un code synchrone force le processeur à attendre la fin d'un block d'instructions pour engager la suide du déroulement du programme.  

### Asynchrone

Un code asynchrone s'exécute sans attendre la fin de son exécution, on passe au prochain block d'instructions directement.  

### Arbitrage

Dans le cadre d'une execution asynchrone, deux blocks d'instructions peuvent atteindre une même variable en même temps car les processus sont lancés en parallèles, donc en même temps.  
Il faut donc mettre en place un arbitre pour déterminer si l'un des processus peut ou non modifier la variable.  
Dans ce tuto l'arbitre s'appelle Mutex qui a pour fonctionnalité de verrouiler une ressource(variable) quand il la traite et de la dévérouiller quand il a terminé.  

## Librairies

### c++11

* TBB.
* fopenmp (permet de rendre un code synchrone en asynchrone de façon implicite).

### c++17

* Parallel STL (simplifie la gestion de la concurence et des threads).

## Conclusion

Implémenter un calcul parallèle demande un petit effort qui sera grandement récompensé en terme de performance.  
Comme nous l'avons évoqué dans la section Librairies, plusieurs choix sont possibles.  
Les Mutex ayant leurs limites en terme de performance on se tournera vers d'autres techniques appelées "Lock-Free" à savoir basées sur un système d'arbitrage sans verrous.
