#include <iostream>
using namespace std;

int main()
{
	// This program asks the user to enter the temperature
	// in fahrenheit and converts it to celcius.
	short f, c, five = 5, nine = 9;
	cout << "Enter temperature in Fahrenheit: ";
	cin >> f;
	_asm
	{
		mov ax, f;	// ax = f
		sub ax, 32;	// ax = f - 32
		imul five;	// ax = 5(f - 32)
		idiv nine;	// ax = 5(f - 32) / 9
		mov c, ax;	// c = ax
	}
	cout << f << "F is " << c << "C\n";
	system("pause");
	return 0;
}