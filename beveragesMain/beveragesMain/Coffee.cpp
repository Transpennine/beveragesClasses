#include <iostream>
#include <string>
#include "Coffee.h"
#include "beverage.h"
using namespace std;

//accessor funciton definitions
string Coffee::getIced() {	//function checks boolean value. If true - iced/ if false - not iced
	try {
		if (iced == true) {
			return "Iced";
		}
		else if (iced == false) {
			return "Not iced";
		}
		else {
			throw invalid_argument("Iced/Not Iced not set");
		}
	}
	catch (invalid_argument& e) {	//exception is thrown if value ommitted
		cout << e.what() << endl;
	}
}
string Coffee::getCaffeine() {	//function returns "caffeinated" if member set to true and "decaf" if member set to false. 
	try {
		if (caffeine == true) {
			return "Caffeinated";
		}
		else if (caffeine == false) {
			return "Decaf";
		}
		else {
			throw invalid_argument("Caffein level not set");	//exception is set if the bool is not formatted
		}
	}
	catch (invalid_argument& e) {
		cout << e.what();
	}
}
string Coffee::getCreamer() {	//function returns "no creamer" if the bool is false (2) and "creamer added" if the bool is true (1)
	try {
		if (creamer == true) {
			return "Creamer added";
		}
		else if (creamer == false) {
			return "No creamer";
		}
		else {	//invalid argument exception is thrown if the bool is not set
			throw invalid_argument("Creamer is not set");
		}
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl;
	}
}
string Coffee::getSweetener() {	//function returns "sweetener added" if sweetener is true and "sweetener not added" if sweetener is false
	try {
		if (sweetener == true) {
			return "Sweetener added";
		}
		else if (sweetener == false) {
			return "Sweetener not added";
		}
		else {	//exception is thrown if the bool is not set
			throw invalid_argument("sweetener not set");
		}
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl;
	}
}
string Coffee::getRoast() {	//function returns the matching member of the roastTypes array
	return roastTypes[roastType];
}

//mutator function definitions
Coffee::Coffee(int iced, int caffeinated, int creamer, int sweet, int roast) {
	setIce(iced);
	setCaffeine(caffeinated);
	setCreamer(creamer);
	setSweetener(sweet);
	setRoastType(roast);
}
Coffee::Coffee() {
	iced = false;
	caffeine = true;
	creamer = false;
	sweetener = false;
	roastType = 2;
}
void Coffee::setIce(int ifIce) {	//function sets coffee type to iced if user chooses 1 and not iced if user chooses iced
	try {
		if (ifIce == 1) {
			iced = true;
		}
		else if (ifIce == 2) {
			iced = false;
		}
		else {	//exception is thrown if the number is neither 1 nor 2
			throw invalid_argument("Coffee can be iced (1) or not iced (2)");
		}
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl;
	}
}
void Coffee::setCaffeine(int ifCaffein) {	//function changes caffeine member to true if 1 is selected and to false if 2 is selected
	try {
		if (ifCaffein == 1) {
			caffeine = true;
		}
		else if (ifCaffein == 2) {
			caffeine = false;
		}
		else {
			throw invalid_argument("Caffeine not set");	//exception is thrown if one of two legal numbers are not selected
		}
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl;
	}
}
void Coffee::setCreamer(int ifCreamer) {	//function sets creamer value to true if 1 is selected and to false if 0 is selected
	try {
		if (ifCreamer == 1) {
			creamer = true;
		}
		else if (ifCreamer == 2) {
			creamer = false;
		}
		else {	//exception is thrown if neither one of the valid arguments is selected
			throw invalid_argument("Creamer value not set");
		}
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl;
	}
}
void Coffee::setSweetener(int ifSweet) {	//function sets the value of "sweetener" member to true if 1 is selected and to false if 2 is selected
	try {
		if (ifSweet == 1) {
			sweetener = true;
		}
		else if (ifSweet == 2) {
			sweetener = false;
		}
		else {		//exception is thrown if an illegal value is selected
			throw invalid_argument("Sweetener value not set");
		}
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl;
	}
}
void Coffee::setRoastType(int newRoast) {	//sets the value of "roastType" member to an integer. The integer will hava a matching string in the roastTypes array
	roastType = newRoast;	
}
void Coffee::toString() {	//this function prints info from Beverage class and additional info from Coffee class
	Beverage::toString();
	cout << endl << getIced() << endl << getCaffeine() << endl << getCreamer() << endl << getSweetener() << endl;
	cout << "Roast Type: " << getRoast() << endl;
}