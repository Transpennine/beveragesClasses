//Soda class is derived from Beverage class - Beverage.h
#pragma once
#include <iostream>
#include <string> 
#include "beverage.h"

using namespace std;

class Soda : public Beverage {	
private:
	string typesSoda[6] = { " ", "Cola", "Lemon-lime", "Cherry", "Root Beer", "Ginger Ale" };	//string array contains values which will determine type and correspond to int stored in typeSoda
	int typeSoda;	//int to correspond with string value in TypesSoda
	string brand;	//contain the brand
	bool diet;		//contain diet(1-true) or regular(2-false)
public:
	//accessor function prototypes
	string getType();	//returns the string valu stored in typesSoda
	string getBrand();	//returns the brand
	string getDiet();	//returns string determining if the drink is diet
	void toString();	//returns the info stored in base object Beverage as well as info from Soda class

	//mutator function prototypes
	Soda(int, string, int);	//parametarized constructor sets type, brand, and diet value
	Soda();					//default constructor
	void setType(int);
	void setBrand(string);
	void setDiet(int);
};