//implementation file for Soda.h

#include <iostream>
#include <string>
#include "Soda.h"

using namespace std;

//accessor functions definitions
string Soda::getType() {	//returns the type of soda based on the int value stored in typeSoda
	return typesSoda[typeSoda];
}
string Soda::getBrand() {	//returns the brand of the drink
	return brand;
}
string Soda::getDiet() {	//returns diet if the bool is true and regular if it is false
	try {
		if (diet == true) {
			return "Diet";
		}
		else if (diet == false) {
			return "regular";
		}
		else {
			throw invalid_argument("diet not set");
		}
	}
	catch(invalid_argument& e){
		cout << e.what() << endl;
	}
}
void Soda::toString() {	//prints the information from the base class and Soda class info
	Beverage::toString();
	cout << "Type: " << getType() << endl << getBrand() << endl << getDiet() << endl;
}

//mutator function definitions
Soda::Soda(int thisType, string thisBrand, int thisDiet) {	//uses the mutator function to set type of soda, brand, and diet-regular
	setType(thisType);
	setBrand(thisBrand);
	setDiet(thisDiet);
}
Soda::Soda() {		//default constructor set to regular Coca Cola coke
	typeSoda = 1;
	brand = "Coca Cola";
	diet = false;
}
void Soda::setType(int newType) {	//sets the int value for soda to correspond with typesSoda array
	typeSoda = newType;
}
void Soda::setBrand(string newBrand) {	//sets the brand of soda
	brand = newBrand;
}
void Soda::setDiet(int newDiet) {	//sets the diet bool to true if 1 and to false if 2
	try {
		if (newDiet == 1) {
			diet = true;
		}
		else if (newDiet == 2) {
			diet = false;
		}
		else {	//excdeption is thrown if value is invalid
			throw invalid_argument("Diet value not set");
		}
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl;
	}
}