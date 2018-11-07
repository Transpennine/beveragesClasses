//header file containing class Tea
#pragma once
#include <iostream>
#include <string>
#include "beverage.h"

using namespace std;

class Tea : public Beverage {
private:
	string teaTypes[6] = { " ", "Black", "Oolong", "Green", "Herbal", "Chai" };	//array of available tea types - strings with the null first member to correspond to the numeric identifiers
	int teaType;	//numeric identifier for tea type to coincide with the string values in the teaTypes array
	bool temp;		//hot(true-1 in selection)/cold(false-2 in selection);
	bool creamer;	//creamer(true)-no creamer(false)
	bool sweetener;	//sweet(true)-unsweet(false)
	bool lemon;		//with lemon(true)-no lemon(false)
public:
	//accessor function prototypes
	string getType();	//function returning the type of tea
	string getTemp();	//function returning the temperature of the tea (hot/cold)
	string getCreamer();//function returning creamer/no creamer
	string getSweetener();	//function returning sweet/unsweet
	string getLemon();	//function returning lemon/no lemon
	void toString();	//funciton returning tea info + base class Beverage info
	//mutator function prototypes
	Tea(int, int, int, int, int);	//parametarized constructor setting private members
	Tea();	//default constructor
	void setType(int);	//change the type of the tea
	void setTemp(int);	//change the temperature of the tea
	void setCreamer(int);	//change creamer/no creamer
	void setSweetener(int);	//change sweet/unsweet
	void setLemon(int);		//change lemon/no lemon
};
