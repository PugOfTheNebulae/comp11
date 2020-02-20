/* Exhibit.cpp
* Implementation file for Exhibits
* Author: Alyssa Rose
* Date: November 15, 2018
*/

#include <iostream>
#include <string>

#include "Exhibit.h"
#include "AnimalArrayList.h"

using std::endl;


const int ORIGIN = 1;
const int DIET = 2;
const int EAR_SIZE = 3;
const int TYPE = 4;
const int NAME = 5;

Exhibit::Exhibit (std::string name, int attribute, std::string attribute_val)
{
	name_ex = name;
	AnimalArrayList animal_ex;
	attr = attribute;
	attr_val = attribute_val;
}

bool Exhibit::in_exhibit (Animal animal1)
{
	if (attr == ORIGIN) {
		if (animal1.origin == attr_val)
			return true;
		else
			return false;
	}

	if (attr == DIET) {
		std::cout << "error" << endl;
		if (animal1.diet == attr_val){
			std::cout << "cerr" << endl;
			return true;
		}
		else
			return false;
	}

	if (attr == EAR_SIZE){
		if (animal1.ear_size == attr_val)
			return true;
		else
			return false;
	}
	
	if (attr == TYPE){
		if (animal1.type == attr_val)
			return true;
		else
			return false;
	}

	if (attr == NAME){
		if (animal1.name == attr_val)
			return true;
		else
			return false;
	}
	return false;
}

void Exhibit::add_ex(Animal animal1)
{
	animal_ex.add(animal1);
}

bool Exhibit::contains(std::string n)
{
	for (int i = 0; i < animal_ex.get_num_animals(); i++){
		if (((animal_ex.get_animal_at(i)).name) == n)
			return true;
	}
	return false;
}

void Exhibit::print_ex()
{
	std::cout << "Exhibit: " << name_ex << endl;
	std::cout << "Characteristic: " <<attr << endl; 
	std::cout << "Characteristic Value: " << attr_val << endl;
	for (int i = 0; i < animal_ex.get_num_animals(); i++){
		std::cout << "---- Animal: " << animal_ex.get_animal_at(i).name << endl;
	}

}