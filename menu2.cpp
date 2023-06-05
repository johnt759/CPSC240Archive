// This program is similar to menu.cpp, except that
// the jump conditions are used to make decisions based
// on the user's input.
#include<iostream>
using namespace std;

short priceSoda = 2, priceWater = 1, priceTenInch = 3, priceTwelveInch = 5;
short numCustomers, numDrinks, numSandwiches, totalBill;
char choiceDrink;
short choiceSandwich, i;
short a, b;	// Temporary variables to hold the values

void display()
{
	cout << "Your total bill = $" << totalBill << endl;
}

void getInput()
{
	cout << "How many drinks? ";
	cin >> numDrinks;
	cout << " What kind of drink(S = Soda, W = Water)? ";
	cin >> choiceDrink;
	cout << "How many sandwiches? ";
	cin >> numSandwiches;
	cout << " What size of sandwich(10/12 inches)? ";
	cin >> choiceSandwich;
}

int main()
{
	cout << "----------7-11 Convenient Store----------\n";
	cout << "Drinks\n";
	cout << " Soda(S)-------------------------------$2\n";
	cout << " Water(W)------------------------------$1\n";
	cout << "Sandwiches\n";
	cout << " 10 inches-----------------------------$3\n";
	cout << " 12 inches-----------------------------$5\n";
	cout << "Enter the number of customers: ";
	cin >> numCustomers;
	_asm
	{
		mov i, 0;					// i = 0
		mov ax, i;					// ax = i
		mov bx, 0;					// bx = 0
	forLoop:
		cmp numCustomers, ax;		// Compare ax to numCustomers
		Jng exitLoop;				// Jump to exitLoop if numCustomers !>= ax
		call getInput;				// Call the getInput function
		Jmp compareDrink;			// Jump to compareDrink
	compareDrink:
		cmp choiceDrink, 's';		// Compare choiceDrink to 's'
		Je sodaDrink;				// Jump to sodaDrink if choiceDrink == 's'
		cmp choiceDrink, 'w';		// Compare choiceDrink to 'w'
		Je waterDrink;				// Jump to waterDrink if choiceDrink == 'w'
	sodaDrink:
		mov ax, numDrinks;			// ax = numDrinks
		mov bx, priceSoda;			// bx = priceSoda
		imul bx;					// ax = numDrinks * priceSoda
		mov a, ax;					// a = ax
		Jmp compareSandwich;		// Jump to compareSandwich
	waterDrink:
		mov ax, numDrinks;			// ax = numDrinks
		mov bx, priceWater;			// bx = priceWater
		imul bx;					// ax = numDrinks * priceWater
		mov a, ax;					// a = ax
		Jmp compareSandwich;		// Jump to compareSandwich
	compareSandwich:
		cmp choiceSandwich, 10;		// Compare choiceSandwich to 10
		Je inchesTen;				// Jump to inchesTen if choiceSandwich == 10
		cmp choiceSandwich, 12;		// Compare choiceSandwich to 12
		Je inchesTwelve;			// Jump to inchesTwelve if choiceSandwich == 12
	inchesTen:
		mov ax, numSandwiches;		// ax = numSandwiches
		mov bx, priceTenInch;		// bx = priceTenInch
		imul bx;					// ax = numSandwiches * priceTenInch
		mov b, ax;					// b = ax
		Jmp totalPrice;				// Jump to totalPrice
	inchesTwelve:
		mov ax, numSandwiches;		// ax = numSandwiches
		mov bx, priceTwelveInch;	// bx = priceTwelveInch
		imul bx;					// ax = numSandwiches * priceTwelveInch
		mov b, ax;					// b = ax
		Jmp totalPrice;				// Jump to totalPrice
	totalPrice:
		mov ax, a;					// ax = a
		mov bx, b;					// bx = b
		add ax, bx;					// ax = a + b
		mov totalBill, ax;			// totalBill = ax
		call display;				// Call the display function
		mov ax, i;					// ax = i
		inc ax;						// ax++
		mov i, ax;					// i = ax
		Jmp forLoop;				// Jump back to whileLoop
	exitLoop:
	}
	system("pause");
	return 0;
}