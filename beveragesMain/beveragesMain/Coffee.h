#pragma once
#include <iostream>
#include "beverage.h"
#include <string>
#include <vector>
using namespace std;
string roastTypes[6] = { "Light", "Medium", "Dark", "French", "Espresso" };	//array of available roast types
class Coffee : public Beverage {
private: 
	bool iced;	//ice(true)-no ice(false)
	bool caffeine;	//caffeinated(true)-decaf(false)
	bool creamer;	//creamer(true)-no creamer(false)
	bool sweetener;	//sweetener(true)-no sweetener(false)
	string flavor;	//flavor description
	int roastType;
public:
	//accessor function prototypes
	string getIced();	//function returns string definition of iced/not iced
	string getCaffeine();	//function returns string definition of caffein/decaf
	string getCreamer();	//function returns string definition of creamer/no creamer
	string getSweetener();//function returns string definition of sweet/unsweet
	string getFlavor();	//funciton returns flavor
	string getRoast();	//returns the type of roast
	void coffeeToString();	//returns the complete description of the drink
	//mutator function prototypes
	Coffee(int);	//constructor for the coffee drink
	void setIce(int);	//change iced/not iced
	void setCaffeine(int);	//change caffeinated/decaf
	void setCreamer(int);	//change creamer/no creamer
	void setSweetener(int);//change sweetener/unsweet
	void setFlavor(string);	//define flavor
	void setRoastType(int);	//set roast type
	
};
