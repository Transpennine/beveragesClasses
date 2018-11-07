//EnergyDrink class is derived from Beverage class
#pragma once
#include<iostream>
#include<string>
#include "beverage.h"

using namespace std;

class EnergyDrink : public Beverage {
private:
	string stimulantType[5] = { " ", "Caffeine", "Taurine", "Ginseng", "Guarana" };
	int stimulantDrink;
	string brand;
	bool carbonated;
public:
	//accessor function prototypes
	string getStimulant();	//returns the string value of the stimulant
	string getBrand();		//returns the string value stored in brand member
	string getCarbonated();	//returns the string definition of the 
	virtual void toString();		//returns the info stored in the base class as well as EnergyDrink specific info

	//mutator function prototypes
	EnergyDrink(int, string, int);	//parametarized constructor sets stimulant type, brand, and carbonated/non-carbonated
	EnergyDrink();				//default constructor
	void setStimulantType(int);	//changes the int for stimulant type - to coincide with the array string value
	void setBrand(string);		//changes the brand of the drink
	void setCarbonated(int);	//changes carbonated member to true(1) or false(2) based on user input.
};