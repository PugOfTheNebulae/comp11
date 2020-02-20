/*
 *  Author: Alyssa Rose
 *  Date: 11-9-2018
 *
 *  Purpose: Combines AnimalArrayList class and Exhibit class
 *          into one file to create a zoo that sorts animals
 *          into exhibits based on shared attricutes
 *
 *  Known bugs: none noticed; however findAnimal could've 
                been modified to take in just the name
                of the animal instead of an Animal struct
 *
 *  Testing performed: checked that the correct exhibit was
                        printed when an animal name was typed
                        in, and made sure that "quit" exited 
                        the program correctly without printing
                        "Animal Not Found"
 */
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "AnimalArrayList.h"
#include "Exhibit.h"

using namespace std;
int const   ZOO_SIZE = 3;

void initializeZoo(string filename, AnimalArrayList *list);
void fillExhibits(Exhibit *exhibits[ZOO_SIZE], AnimalArrayList *list);
void printZoo(Exhibit *exhibits[ZOO_SIZE]);
void findAnimal(Animal a, Exhibit *exhibits[ZOO_SIZE]);

int main()
{
    AnimalArrayList *list = new AnimalArrayList;
    initializeZoo("animals.db", list);
    Exhibit *exhibits[ZOO_SIZE];
    exhibits[0] = new Exhibit("Vegans", 2, "herbivore");
    exhibits[1] = new Exhibit("Carcass Consumer", 2, "carnivore");
    exhibits[2] = new Exhibit("Flexible Foodies", 2, "omnivore");
    fillExhibits(exhibits, list);
    printZoo(exhibits);

    std::string input = " ";
    while (true){
        std::cin >> input;
        if (input == "quit")
            return 0;
        for (int i = 0; i < ZOO_SIZE; i++){
            if (exhibits[i]->contains(input)){
                exhibits[i]->print_ex();
            }
        }
    }

    for (int i = 0; i < ZOO_SIZE; i++)
        delete exhibits[i];

}

/*  initializeZoo
 *
 *  Reads animal data from the given file, and stores it in the array list
 *
 *  Parameters:  Filename to read data from, a list to store the animals in
 *  Outputs:     None
 *  Effects:     Fills the passed list with animals, adding them to the back
 */
void initializeZoo(string filename, AnimalArrayList *list)
{
        ifstream file;
        Animal   a;

        file.open(filename);
        
        if (not file.is_open()) {
            std::cerr << "File " << filename << " could not be opened!" 
                      << std::endl;
            exit(1);
        }

        file >> a.name >> a.origin >> a.diet >> a.ear_size >> a.type;
        while (not file.eof()) {
            list->add(a);
            file >> a.name >> a.origin >> a.diet >> a.ear_size >> a.type;
        }
        file.close();
}

/*  fillExhibits
 *
 *  Fills the exhibits with the correct animals
 *
 *  Parameters:  array of pointers to exhibits and a pointer to 
                 an AnimalArrayList
 *  Outputs:     None
 *  Effects:     Adds animals to their exhibits
 */
void fillExhibits(Exhibit *exhibits[ZOO_SIZE], AnimalArrayList *list)
{
    //sort based on diet
    for (int i = 0; i < (list -> get_num_animals()); i++){
        for (int j = 0; j < ZOO_SIZE; j++){
            if (exhibits[j]->in_exhibit(list->get_animal_at(i))){
                exhibits[j]->add_ex(list->get_animal_at(i));
            }
        }

    }
}

/*  printZoo
 *
 *  Prints out info about the exhibit and the animals contained in it
 *
 *  Parameters:  exhibits array
 *  Outputs:     None
 *  Effects:     prints out the exhibit info and the animals
 */
void printZoo(Exhibit *exhibits[ZOO_SIZE])
{
    for (int i = 0; i < ZOO_SIZE; i++){
        exhibits[i]->print_ex();

    }
}

/*  findAnimal
 *
 *  finds the exhibit that the animal is in and prints it
 *
 *  Parameters:  Animal struct and exhibits 
 *  Outputs:     None
 *  Effects:     prints out the exhibit that the animal is in
 once it finds the animal
 */
void findAnimal(Animal a, Exhibit *exhibits[ZOO_SIZE])
{
    for (int i = 0; i < ZOO_SIZE; i++){
        if (exhibits[i]->contains(a.name))
            exhibits[i]->print_ex();
    }

}
