#include <iostream>
using namespace std;

int main()
{
	short numDrinks, numSandwich, priceTotal;
	short priceDrinks = 2, priceSandwich = 4;

	// Display the information and ask the user for input.
	cout << "----------MENU----------\n";
	cout << "Drinks----------------$2\n";
	cout << "Sandwich--------------$4\n";
	cout << "How many drinks? ";
	cin >> numDrinks;
	cout << "How many sandwiches? ";
	cin >> numSandwich;

	_asm
	{
		mov ax, numDrinks;		// ax = numDrinks
		imul priceDrinks;		// dx:ax = priceDrinks * numDrinks
		mov bx, ax;				// bx = priceDrinks * numDrinks
		mov ax, numSandwich;	// ax = numSandwich
		imul priceSandwich;		// dx:ax = priceSandwich * numSandwich
		add ax, bx;				// ax = (priceDrinks * numDrinks) + (priceSandwich * numSandwich)
		mov priceTotal, ax;		// priceTotal = ax
	}

	cout << "Your total bill $" << priceTotal << endl;
	system("pause");
	return 0;
}