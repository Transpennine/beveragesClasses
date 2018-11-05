//implementation file for the base class of Beverages named in "beverage.h"
#include "beverage.h"

//accessor function definitions
string Beverage::getName() {	//returns the name of the drink
	return name;
}
string Beverage::getDescription() {	//returns description of the beverage
	return description;
}
string Beverage::toString() {	//returns the description of all attributes of Beverage class
	return getName();
}
int Beverage::getServingSize() {
	return servingSize;	//returns the serving size of the beverage (format to oz)
}
int Beverage::getCalories() {
	return calories;	//returns the amount of calories
}
float Beverage::getPrice() {
	return price;	//returns the price of the drink
}

//mutator funcsetion definitions
Beverage::Beverage() {
	name = " Heya";
}
Beverage::Beverage(string newName, string newDescription, int newServingSize, int newCalories, float newPrice) {
	setName(newName);
	setDescription(newDescription);
	setServingSize(newServingSize);
	setCalories(newCalories);
	setPrice(newPrice);
}	//the constructor takes the parameters for name, description, serving size, calories, and price and creates an object
void Beverage::setName(string newName) {
	name = newName;		//sets the name of the beverage to the string provided in the parameter
}
void Beverage::setDescription(string newDescription) {
	description = newDescription;		//sets the description of the beverage
}
void Beverage::setServingSize(int newServing) {
	servingSize = newServing;	//changes the serving size to the number specified in the parameter
}
void Beverage::setCalories(int newCalories) {
	calories = newCalories;	//changes the calories to the amount specified in the parameter
}
void Beverage::setPrice(float newPrice) {
	price = newPrice;	//changes the price to the number specified in the parameter
}