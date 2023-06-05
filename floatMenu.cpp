// The program is similar to menu.cpp, except that float
// arithmetic is involved along with 2 decimal digits.
#include<iostream>
using namespace std;
float priceSoda = 2.25, priceWater = 1.75, priceTenInch = 3.45, priceTwelveInch = 5.25;
float numDrinks, numSandwiches, totalBill;
char choiceDrink;
short choiceSandwich;
float a, b;

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
	cout << " Soda(S)-----------------------------$2.25\n";
	cout << " Water(W)----------------------------$1.75\n";
	cout << "Sandwiches\n";
	cout << " 10 inches---------------------------$3.45\n";
	cout << " 12 inches---------------------------$5.25\n";
	_asm
	{
		call getInput;				// Call the getInput function
		Jmp compareDrink;			// Jump to compareDrink
	compareDrink:
		cmp choiceDrink, 's';		// Compare choiceDrink to 's'
		Je sodaDrink;				// Jump to sodaDrink if choiceDrink == 's'
		cmp choiceDrink, 'w';		// Compare choiceDrink to 'w'
		Je waterDrink;				// Jump to waterDrink if choiceDrink == 'w'
	sodaDrink:
		fld numDrinks;				// st[0] = numDrinks
		fld priceSoda;				// st[0] = priceSoda, st[1] = numDrinks
		fmul;						// st[0] = priceSoda * numDrinks
		fstp a;						// a = priceSoda * numDrinks
		Jmp compareSandwich;		// Jump to compareSandwich
	waterDrink:
		fld numDrinks;				// st[0] = numDrinks
		fld priceWater;				// st[0] = priceWater, st[1] = numDrinks
		fmul;						// st[0] = priceWater * numDrinks
		fstp a;						// a = priceWater * numDrinks
		Jmp compareSandwich;		// Jump to compareSandwich
	compareSandwich:
		cmp choiceSandwich, 10;		// Compare choiceSandwich to 10
		Je inchesTen;				// Jump to inchesTen if choiceSandwich == 10
		cmp choiceSandwich, 12;		// Compare choiceSandwich to 12
		Je inchesTwelve;			// Jump to inchesTwelve if choiceSandwich == 12
	inchesTen:
		fld numSandwiches;			// st[0] = numSandwiches
		fld priceTenInch;			// st[0] = priceTenInch, st[1] = numSandwiches
		fmul;						// st[0] = priceTenInch * numSandwiches
		fstp b;						// b = priceTenInch * numSandwiches
		Jmp totalPrice;				// Jump to totalPrice
	inchesTwelve:
		fld numSandwiches;			// st[0] = numSandwiches
		fld priceTwelveInch;		// st[0] = priceTwelveInch, st[1] = numSandwiches
		fmul;						// st[0] = priceTwelveInch * numSandwiches
		fstp b;						// b = priceTwelveInch * numSandwiches
		Jmp totalPrice;				// Jump to totalPrice
	totalPrice:
		fld a;						// st[0] = a
		fld b;						// st[0] = b, st[1] = a
		fadd;						// st[0] = a + b
		fstp totalBill;				// totalBill = a + b
		call display;
	}
	system("pause");
	return 0;
}