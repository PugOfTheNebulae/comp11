/*
 *      HW 6: Zookeeper
 *      AnimalArrayList.cpp: Stores a dynamic array of Animals
 *      Author: William Scott
 *      Modified By: 
 *      Date: 7 November 2018
 */

#ifndef ANIMALARRAYLIST_H
#define ANIMALARRAYLIST_H

#include <string>

struct Animal
{
        std::string name; 
        std::string origin;     // Continents
        std::string diet;       // Carnivore, Herbivore, Omnivore
        std::string ear_size;   // Large, Medium, Small, None
        std::string type;       // Mammal, Reptile, Avian, Insect, Fish
};

class AnimalArrayList
{
public:
        /*
         * Default constructor
         */
        AnimalArrayList();

        /*
         * Frees heap-allocated memory associated with arraylist
         */
        ~AnimalArrayList();

        /*
         * Adds a to the back of the list.
         * Effects: may expand if necessary
         */
        void add(Animal a);

        /*
         * Returns the number of Animals currently stored
         */
        int get_num_animals();

        /*
         * Returns the Animal located at position index  
         */
        Animal get_animal_at(int index);

private:
        const static int INITIAL_CAPACITY = 4;

        Animal *animals;
        int     num_animals;
        int     capacity;
        /*
         * Doubles the capacity of the animals array
         */
        void expand();
};
#endif
