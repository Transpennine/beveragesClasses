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

int main() {
	int ice;
	string name;
	cout << "Ice?";
	cin >> ice;
	cin.ignore();
	cout << "Name?";
	getline(cin, name);
	Coffee newCoffee(ice);
	cout << newCoffee.getIced();
	newCoffee.setName(name);
	cout << newCoffee.getName();

	return 0;
}