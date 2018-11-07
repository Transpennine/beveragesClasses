#pragma once
#include <iostream>
#include <string>

using namespace std;

class Beverage {
private: 
	string name;
	string description;
	int servingSize;
	int calories;
	float price;
public:
	//accessor function prototypes
	string getName(); //returns the name of the beverage
	string getDescription(); //returns the description of the beverage
	void toString();		//returns the complete description of the drink
	int getServingSize();	//returns the serving size (format-oz)
	int getCalories();		//returns the amount of calories in the drink
	float getPrice();		//returns the price of the drink
	//mutator function prototypes
	Beverage(string, string, int, int, float);	//parametarized constructor - creates the beverage with all attributes
	Beverage();	//default constructor prototype
	void setName(string);	//changes the name of the beverage
	void setDescription(string);	//changes the description of the beverage
	void setServingSize(int);		//changes the serving size of the beverage (format - oz)
	void setCalories(int);			//changes the amount of calories in the beverage
	void setPrice(float);			//changes the price of the drink
};