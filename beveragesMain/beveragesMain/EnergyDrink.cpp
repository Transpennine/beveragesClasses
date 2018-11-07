//implementation file for EnergyDrink.h
#include <iostream>
#include <string>
#include "EnergyDrink.h"

using namespace std;

//accessor functions definitions
string EnergyDrink::getStimulant() {	//returns the string value from stimulantType prototype based on the value stored in stimulantDrink
	return stimulantType[stimulantDrink];
}
string EnergyDrink::getBrand() {	//returns the brand string stored in the private member
	return brand;
}
string EnergyDrink::getCarbonated() {	//funciton checks the value stored in bool carbonated and returns the corresponding string description
	try {
		if (carbonated == true) {
			return "Carbonated";
		}
		else if (carbonated == false) {
			return "Still";
		}
		else {	//exception is thrown if value is illegal
			throw invalid_argument("Carbonated value not set");
		}
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl;
	}
}
void EnergyDrink::toString() {	//funciton prints info from base class Beverage and all available info from EnergyDrink class
	Beverage::toString();
	cout << "Stimulant type: " << getStimulant() << endl << getBrand() << endl << getCarbonated() << endl;
}

//mutator functions definitions
EnergyDrink::EnergyDrink(int thisType, string thisBrand, int thisCarb) {	//constructor runs the mutator functions based on user input to create EnergyDrink objects
	setStimulantType(thisType);
	setBrand(thisBrand);
	setCarbonated(thisCarb);
}
EnergyDrink::EnergyDrink() {	//default energy drink is Red Bull, carbonated, with Taurine
	stimulantDrink = 2;
	brand = "Red Bull";
	carbonated = true;
}
void EnergyDrink::setStimulantType(int newType) {	//sets the int private member stimulantSrink to the entered integer to correspond to the string array
	stimulantDrink = newType;
}
void EnergyDrink::setBrand(string newBrand) {	//records the brand name in brand member
	brand = newBrand;
}
void EnergyDrink::setCarbonated(int newCarb) {	//funciton assigns boolean value to carbonated member based on user-input parameter
	try {
		if (newCarb == 1) {
			carbonated = true;
		}
		else if (newCarb == 2) {
			carbonated = false;
		}
		else {
			throw invalid_argument("Carbonated value not set");
		}
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl;
	}
}