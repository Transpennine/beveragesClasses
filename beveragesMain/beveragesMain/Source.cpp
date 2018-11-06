//
//
//
//

#include <iostream>
#include <string>
#include <vector>
#include "beverage.h"
#include "Coffee.h"

using namespace std;

void checkInput();	//function will check if the input is valid and discard it if it is not

//Functions used for the base Beverage class
string nameDrink();			//Beverage: function prototype for naming the drink
string describeDrink();		//Beverage: function prototype for describing the drink
int newServingSize();		//Beverage: function prototype for getting the size of the serving
int caloriesNum();			//Beverage: function prototype for getting the amount of calories in the drink
int priceBeverage();		//Beverage: funciton prototype for getting the price of the drink

//Functions used for creating Coffee drinks
int icedCoffee();			//Coffee: function prototype for iced coffee
int caffeinatedCoffee();	//Coffee: function prototype for caffeinated/decaf
int sweetCoffee();			//Coffee: function prototype for sweet coffee
int creamerCoffee();		//Coffee: function prototype for creamer in coffee
int coffeeRoast();			//Coffee: function prototype for setting the roast of coffee


int main() {
	int iced = icedCoffee();
	int caffeinated = caffeinatedCoffee();
	int creamer = creamerCoffee();
	int sweet = sweetCoffee();
	int roast = coffeeRoast();
	Coffee newCup(iced, caffeinated, creamer, sweet, roast);
	newCup.coffeeToString();

	return 0;
}

void checkInput() {	//this function checks input for extraction fail, puts it back in the operating mode, and clears illegal input
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input. Try again." << endl;
	}
}

//Declaration of functions for the 

//Declaration of functions for the Coffee class
int icedCoffee() {	//function asks user if ice is needed in coffee. 1 if yes, 2 if no.
	int ifIced = 0;	
	while (ifIced == 0) {
		cout << "Would you like to add ice to the coffee? Press 1 if yes, 2 if no" << endl;
		cin >> ifIced;
		checkInput();
	}
	cin.ignore();
	return ifIced;
}
int caffeinatedCoffee() {	//this function asks the user if the drink contains caffeine
	int caffeine = 0;
	while (caffeine == 0) {
		cout << "Does your coffee contain caffeine? 1 - yes, 2 - no." << endl;
		cin >> caffeine;
		checkInput();
	}
	cin.ignore();
	return caffeine;
}
int creamerCoffee() {	//function asks user if the drink should contain creamer. 1 - yes, 2 - no. 
	int creamer = 0;
	while (creamer == 0) {
		cout << "Would you like to add creamer? 1 - yes, 2 - no" << endl;
		cin >> creamer;
		checkInput();	//checking and correcting input.
	}
	cin.ignore();	//discarding extra characters in cache
	return creamer;
}
int sweetCoffee() {	//function asks if user wants to add sweetener. 1 - yes, 2 - no. Checks for valid input
	int sweet = 0;
	while (sweet == 0) {
		cout << "Would you like to add sweetener to your coffee? 1 - yes, 2 - no." << endl;
		cin >> sweet;
		checkInput();
	}
	cin.ignore();
	return sweet;
}
int coffeeRoast() {
	int roastType = 0;
	cout << "There are 5 roast types available: " << endl << "1 - Light" << endl << "2 - Medium" << endl << "3 - Dark" << endl << "4 - French Roast" << endl << "Espresso" << endl;
	while (roastType == 0) {
		cout << "Select your roast type (1-4): ";
		cin >> roastType;
		checkInput();
	}
	cin.ignore();
	return roastType;
}