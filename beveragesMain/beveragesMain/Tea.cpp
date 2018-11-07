//implementation file for Tea.h
#include <iostream>
#include <string>
#include "beverage.h"
#include "Tea.h"

using namespace std;

//accessor function definitions
string Tea::getType() {	//function returns the string description of the tea type matching the numeric id stored in teaType member
	return teaTypes[teaType];
}
string Tea::getTemp() {	//function checks boolean value and returns hot if true/cold if false
	try {
		if (temp == true) {
			return "Hot";
		}
		else if (temp == false) {
			return "Cold";
		}
		else {
			throw invalid_argument("Temperature not set");	//expression is thrown if an illegal value is stored
		}
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl;
	}
}
string Tea::getCreamer() {//function returns "no creamer" if the bool is false (2) and "creamer added" if the bool is true (1)
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
string Tea::getSweetener() {	//function returns "sweetener added" if sweetener is true and "sweetener not added" if sweetener is false
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
string Tea::getLemon() {	//function checks boolean value of "lemon" and returns Lemon added if true and No lemon if false
	try {
		if (lemon == true) {
			return "Lemon added";
		}
		else if (lemon == false) {
			return "No lemon";
		}
		else {
			throw invalid_argument("Lemon value not set");	//exeception is thrown if value is illegal
		}
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl;
	}
}
void Tea::toString() {	//function prints info from the base Beverage class and adds information from Tea class
	Beverage::toString();
	cout << getType() << endl << getTemp() << endl << getCreamer() << endl << getSweetener() << endl << getLemon() << endl;
}
//mutator function definitions
Tea::Tea(int type, int temp, int cream, int sweet, int lemon) {	//constructor takes integers and runs them through the mutator member functions
	setType(type);	//setting tea type
	setTemp(temp);	//setting temperature
	setCreamer(cream);	//setting creamer 
	setSweetener(sweet);//sweetener
	setLemon(lemon);	//setting lemon
}
Tea::Tea() {	//default constructor sets the tea to black, hot, no creamer, no sweetener, no lemon
	teaType = 1;
	temp = true;
	creamer = false;
	sweetener = false;
	lemon = false;
}
void Tea::setType(int newType) {	//function sets member teaType to the integer in parameter
	teaType = newType;
}
void Tea::setTemp(int newTemp) {	//input 1 sets true (hot); 2 sets false (cold)
	try {
		if (newTemp == 1) {
			temp = true;
		}
		else if (newTemp == 2) {
			temp = false;
		}
		else {
			throw invalid_argument("Temperature not set");	//illegal value throws an exception
		}
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl;
	}
}
void Tea::setCreamer(int newCreamer) { //function sets creamer value to true if 1 is selected and to false if 0 is selected
	try {
		if (newCreamer == 1) {
			creamer = true;
		}
		else if (newCreamer == 2) {
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
void Tea::setSweetener(int newSweetener) {	//function sets the value of "sweetener" member to true if 1 is selected and to false if 2 is selected
	try {
		if (newSweetener == 1) {
			sweetener = true;
		}
		else if (newSweetener == 2) {
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
void Tea::setLemon(int newLemon) {	//function checks user input and sets "lemon" true if 1 and false if 2
	try {
		if (newLemon == 1) {
			lemon = true;
		}
		else if (newLemon == 2) {
			lemon = false;
		}
		else {
			throw invalid_argument("Lemon value not set");	//illegal values are thrown
		}
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl;
	}
}