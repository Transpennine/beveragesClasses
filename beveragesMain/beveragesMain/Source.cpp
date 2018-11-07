//
//
//
//

#include <iostream>
#include <string>
#include <vector>
#include "beverage.h"
#include "Coffee.h"
#include "Tea.h"
#include "Soda.h"
#include "EnergyDrink.h"

using namespace std;

void checkInput();	//function will check if the input is valid and discard it if it is not

//Functions used for the base Beverage class
string nameDrink();			//Beverage: function prototype for naming the drink
string describeDrink();		//Beverage: function prototype for describing the drink
int newServingSize();		//Beverage: function prototype for getting the size of the serving
int caloriesNum();			//Beverage: function prototype for getting the amount of calories in the drink
float priceBeverage();		//Beverage: funciton prototype for getting the price of the drink

//Functions used for creating Coffee drinks
int icedCoffee();			//Coffee: function prototype for iced coffee
int caffeinatedCoffee();	//Coffee: function prototype for caffeinated/decaf
int addSweet();				//Coffee, Tea: function prototype for sweet coffee
int addCreamer();			//Coffee, Tea: function prototype for creamer in coffee
int coffeeRoast();			//Coffee: function prototype for setting the roast of coffee

//Functions used for creating Tea drinks
//Use addSweet() and addCreamer functions from Coffee class to add sweetener and creamer
int teaType();				//Tea: function prototype for the type of tea
int teaTemp();				//Tea: function prototype for tea temperature
int lemonTea();				//Tea: funcition prototype for lemon in tea

//Functions used for creating Soda drinkg
int sodaType();				//Soda: function prototype for the type of soda
string newBrand();			//Soda: function prototype for the brand of soda
int sodaDiet();				//Soda: function prototype for the diet/regular selection

//Functions used for creating Energy Drinks
//Use newBrand() from Soda class to set brand
int energyType();			//EnergyDrink: function prototype for selecting the type of stimulant in the energy drink
int energyCarb();			//EnergyDrink: function prototype for selecting if a drink is carbonated or not

int main() {
	int selector = 0;	//this int will be the index for selector - if 1, the do-while loop will continue.
	vector <Beverage*> newMenu;
	Beverage *drink;
	cout << "Welcome to the Hydration Station! Time to create the menu!" << endl;
	do {
		int newBeverage = 0;
		while (newBeverage == 0  || (newBeverage != 1 && newBeverage != 2 && newBeverage != 3 && newBeverage != 4)) {	//this section will provide the choice of drink to the user and check and record an int value
			cout << "Select what beverage you would like to add:" << endl;
			cout << "1 - Coffee beverage" << endl << "2 - Tea" << endl << "3 - Soda" << endl << "4 - Energy Drink" << endl;
			cin >> newBeverage;
			checkInput();
			if (newBeverage == 1) {	//this section will prompt the user to select Coffee features to create a coffee drink
				int iced = icedCoffee();	//iced-not iced
				int caffeinated = caffeinatedCoffee();	//caffeine-decaf
				int creamer = addCreamer();	//creamer-no creamer
				int sweet = addSweet();		//sweet-not sweet
				int roast = coffeeRoast();		//selecting the roast type
				Coffee newCup(iced, caffeinated, creamer, sweet, roast);	//coffee object is created
				drink = &newCup;
				newCup.setName(nameDrink());	//assigning the name
				newCup.setDescription(describeDrink());	//setting description
				newCup.setServingSize(newServingSize());//setting serving size
				newCup.setCalories(caloriesNum());		//setting calories
				newCup.setPrice(priceBeverage());		//setting price
				newMenu.push_back(drink);		//adding the object to the Beveraes vector
			}
			else if (newBeverage == 2) {
				int type = teaType();	//select type of tea
				int temperature = teaTemp();	//select temperature
				int lemon = lemonTea();	//lemon-no lemon in tea
				int creamerTea = addCreamer();	//creamer-no creamer
				int sweetTea = addSweet();		//sweet-unsweet
				Tea cupTea(type, temperature, creamerTea, sweetTea, lemon);	//create Tea object with set numbers
				drink = &cupTea;
				cupTea.setName(nameDrink());	//assigning the name
				cupTea.setDescription(describeDrink());	//setting description
				cupTea.setServingSize(newServingSize());	//setting serving size
				cupTea.setCalories(caloriesNum());		//setting calories
				cupTea.setPrice(priceBeverage());		//setting price
				newMenu.push_back(drink);		//adding the object to the Beverages vector
			}
			else if (newBeverage == 3) {
				int typeOfSoda = sodaType();				//setting the type of soda
				string brandOfSoda = newBrand();			//setting the brand
				int ifDietSoda = sodaDiet();				//setting diet/regular
				Soda newSoda(typeOfSoda, brandOfSoda, ifDietSoda);	//creating Soda object
				newSoda.setName(nameDrink());	//assigning the name
				newSoda.setDescription(describeDrink());	//setting drink description
				newSoda.setServingSize(newServingSize());	//setting serving size
				newSoda.setCalories(caloriesNum());			//setting calories
				newSoda.setPrice(priceBeverage());			//setting price
				drink = &newSoda;
				newMenu.push_back(drink);
			}
			else if (newBeverage == 4) {
				int newStim = energyType();			//setting the type of stimulant
				string brandOfEnergy = newBrand();	//setting the brand
				int newCarb = energyCarb();			//setting carb/still 
				EnergyDrink newEnergyDrink(newStim, brandOfEnergy, newCarb);	//creating EnergyDrink object
				drink = &newEnergyDrink;
				newEnergyDrink.setName(nameDrink());	//assigning the name
				newEnergyDrink.setDescription(describeDrink());	//setting drink description
				newEnergyDrink.setServingSize(newServingSize());	//setting serving size
				newEnergyDrink.setCalories(caloriesNum());			//setting calories
				newEnergyDrink.setPrice(priceBeverage());			//setting price
				newMenu.push_back(drink);
			}
		}
		cout << "Would you like to add one more drink? Enter 1 if yes, any other number if no." << endl; 
		cin >> selector;
		checkInput();
	} while (selector == 1);
	cin.ignore();
	for (int i = 0; i < newMenu.size(); i++) {
		newMenu.at(i)->toString();
	}


	return 0;
}

void checkInput() {	//this function checks input for extraction fail, puts it back in the operating mode, and clears illegal input
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid input. Try again." << endl;
	}
}

//Declaration of functions for the base Beverage class
string nameDrink() {	//this function returns the name of the drink (string)
	string newName;
	cout << "Enter the name of you drink: " << endl;
	getline(cin, newName);		//getting the whole line including the spaces
	return newName;
}
string describeDrink() {	//this function returns the string - description of the drink
	string newDescription;
	cout << "Enter the description of the drink: " << endl;
	getline(cin, newDescription);
	return newDescription;
}
int newServingSize() {	//this function prompts the user for the serving size in oz and returns the legal input
	int servingNum = -10;
	while (servingNum < 0) {
		cout << "Enter the serving size of your drink in oz: " << endl;
		cin >> servingNum;	//checking funciton to make sure the input is legal
		checkInput();
	}
	cin.ignore();
	return servingNum;
}
int caloriesNum() {		//this funciton prompts for, checks, and returns the integer-number of calories in the drink
	int newCalories = -10;
	while (newCalories < 0) {
		cout << "Enter the amount of calories in your drink: " << endl;
		cin >> newCalories;
		checkInput();
	}
	cin.ignore();
	return newCalories;
}
float priceBeverage() {	//this function prompts user for, checks, and returns a legal int-amount price in dollars
	float newPrice = -20;
	while (newPrice < 0) {
		cout << "Enter the price for your item in dollars (omit the dollar sign): " << endl;
		cin >> newPrice;
		checkInput();
	}
	cin.ignore();
	return newPrice;
}

//Declaration of functions for the Coffee class
int icedCoffee() {	//function asks user if ice is needed in coffee. 1 if yes, 2 if no.
	int ifIced = 0;	
	while (ifIced == 0 || (ifIced != 1 && ifIced != 2)) {
		cout << "Would you like to add ice to the coffee? Press 1 if yes, 2 if no" << endl;
		cin >> ifIced;
		checkInput();
	}
	cin.ignore();
	return ifIced;
}
int caffeinatedCoffee() {	//this function asks the user if the drink contains caffeine
	int caffeine = 0;
	while (caffeine == 0 || (caffeine != 1 && caffeine != 2)) {
		cout << "Does your coffee contain caffeine? 1 - yes, 2 - no." << endl;
		cin >> caffeine;
		checkInput();
	}
	cin.ignore();
	return caffeine;
}
int addCreamer() {	//function asks user if the drink should contain creamer. 1 - yes, 2 - no. 
	int creamer = 0;
	while (creamer == 0 || (creamer != 1 && creamer != 2)) {
		cout << "Would you like to add creamer? 1 - yes, 2 - no" << endl;
		cin >> creamer;
		checkInput();	//checking and correcting input.
	}
	cin.ignore();	//discarding extra characters in cache
	return creamer;
}
int addSweet() {	//function asks if user wants to add sweetener. 1 - yes, 2 - no. Checks for valid input
	int sweet = 0;
	while (sweet == 0 || (sweet != 1 && sweet != 2)) {
		cout << "Would you like to add sweetener? 1 - yes, 2 - no." << endl;
		cin >> sweet;
		checkInput();
	}
	cin.ignore();
	return sweet;
}
int coffeeRoast() {	//function prompts user to select from the suggested values for roast type, checks input, and returns the entered value
	int roastType = 0;
	cout << "There are 5 roast types available: " << endl << "1 - Light" << endl << "2 - Medium" << endl << "3 - Dark" << endl << "4 - French Roast" << endl << "5 - Espresso" << endl;
	while (roastType == 0 || (roastType != 1 && roastType != 2 && roastType != 3 && roastType != 4 && roastType != 5)) {
		cout << "Select your roast type (1-5): " << endl;
		cin >> roastType;
		checkInput();
	}
	cin.ignore();
	return roastType;
}

//Declaration of functions for the Tea class
int teaType() {	//function prompts user to select the type of tea and after checking input returns the integer
	int teaType = 0;
	cout << "There are 5 types of tea available: " << endl << "1 - Black" << endl << "2 - Oolong" << endl << "3 - Green" << endl << "4 - Herbal" << endl << "5 - Chai" << endl;
	while (teaType == 0 || (teaType != 1 && teaType != 2 && teaType != 3 && teaType != 4 && teaType != 5)) {
		cout << "Select your tea type (1-5): " << endl;
		cin >> teaType;
		checkInput();	//checking the data type of the input
	}
	cin.ignore();
	return teaType;
}
int teaTemp() {	//function prompts the user to choose hot or cold tea, checks input, and returns the entered value
	int setTemp = 0;
	while (setTemp == 0 || (setTemp != 1 && setTemp != 2)) {
		cout << "Would you like your tea hot? 1- yes, 2 - no." << endl;
		cin >> setTemp;
		checkInput();
	}
	cin.ignore();
	return setTemp;
}
int lemonTea() {	//function prompts user to select lemon in tea or no lemon, checks the value, and returns it
	int lemon = 0;
	while (lemon == 0 || (lemon != 1 && lemon != 2)) {
		cout << "Would you like to add lemon to the tea? 1 - yes, 2 - no. " << endl;
		cin >> lemon;
		checkInput();
	}
	cin.ignore();
	return lemon;
}

//Declaration of functions for the Soda class
int sodaType() {	//function prompts user to select type of soda and returns the legal value
	int newType = 0;
	cout << "There are 5 types of soda available: " << endl << "1 - Cola" << endl << "2 - Lemon-lime" << endl << "3 - Cherry" << endl << "4 - Root Beer" << endl;
	while(newType == 0 || (newType != 1 && newType != 2 && newType != 3 && newType != 4 && newType !=5)) {
		cout << "Select your soda type (1-5): " << endl;
		cin >> newType;
		checkInput();	//checking input for data type validity
	}
	cin.ignore();
	return newType;
}
string newBrand() {	//prompts the user to enter the brand of the soda and returns the entered string value
	string newBrand;
	cout << "Type the brand of the drink: " << endl;
	getline(cin, newBrand);
	return newBrand;
}
int sodaDiet() {	//prompts user to select 1 for diet soda and 2 for regular and returns a legal value
	int newDiet = 0;
	while (newDiet == 0 || (newDiet != 1 && newDiet != 2)) {
		cout << "Would you like diet soda? 1 - yes, 2 - no." << endl;
		cin >> newDiet;
		checkInput();
	}
	cin.ignore();
	return newDiet;
}

//Declaration of functions for the Energy Drink class
int energyType() {		//function prompts the user to select a value for stimulant type and returns a valid int
	int newEnergy = 0;
	cout << "There are 4 types of stimulants available for energy drinks: " << endl << "1 - Caffeine" << endl << "2 - Taurine" << endl << "3 - Ginseng" << endl << "4 - Guarana" << endl;
	while (newEnergy == 0 || (newEnergy != 1 && newEnergy != 2 && newEnergy != 3 && newEnergy != 4)) {
		cout << "Select your type of stimulant (1-4): " << endl;
		cin >> newEnergy;
		checkInput();
	}
	cin.ignore();
	return newEnergy;
}
int energyCarb() {	//function prompts for carbonated/still selection and returns a valid int
	int newCarb = 0;
	while (newCarb == 0 || (newCarb != 1 && newCarb != 2) ) {
		cout << "Would you like to create a carbonated drink? 1 - yes, 2 - no" << endl;
		cin >> newCarb;
		checkInput();
	}
	cin.ignore();
	return newCarb;
}