#ifndef EXHIBIT_H
#define EXHIBIT_H

#include "AnimalArrayList.h"
#include <string>
#include <iostream>

class Exhibit
{
public:
	/*
	* Constructor
	*/
	Exhibit (std::string name, int attribute, std::string attribute_val);
	/*
	* Returns whether or not a given animal belongs in an exhibit
	*/
	bool in_exhibit (Animal animal1);

	/*
	* Adds a given animal to an exhibit
	*/
	void add_ex(Animal animal1);

	/*
	* Function that returns whether or not
	*an exhibit contains an animals with a given name
	*/
	bool contains(std::string n);

	/*
	* Prints out the info of an exhibit
	*/
	void print_ex();
	
private:
	AnimalArrayList animal_ex;
	std::string name_ex;
	int attr;
	std::string attr_val;
};
#endif
