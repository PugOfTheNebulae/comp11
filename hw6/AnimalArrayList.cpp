/* AnimalArrayList.cpp
*  implementation file for the AnimalArrayList class
*  Author: Alyssa Rose
*  Date: November 15 2018
*/

#include <iostream>

#include "AnimalArrayList.h"

AnimalArrayList::AnimalArrayList()
{
       animals = new Animal[INITIAL_CAPACITY];
       num_animals = 0;
       capacity = INITIAL_CAPACITY;
}

AnimalArrayList::~AnimalArrayList()
{
        delete [] animals;
        animals = NULL;
}

void AnimalArrayList::add(Animal a)
{
	if (num_animals == capacity){
		expand();
		animals[num_animals] = a;
		num_animals++;
	}
	else { 
		animals[num_animals] = a;
		num_animals++;
	}
}
int AnimalArrayList::get_num_animals()
{
        return num_animals;
}

Animal AnimalArrayList::get_animal_at(int index)
{
        return animals[index];
}

void AnimalArrayList::expand()
{
        int new_capacity = (capacity * 2) + 2;
        Animal *new_animals = new Animal[new_capacity];
        for (int i = 0; i < num_animals; i++){
                new_animals[i] = animals[i];
        }
        delete [] animals;
        animals = new_animals;
        capacity = new_capacity;

}
