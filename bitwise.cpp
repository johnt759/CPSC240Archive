// This program uses various bitwise relational
// operators to compare each values.
// The and, or, and not operators are used below.
#include <iostream>
using namespace std;

short a = 3, b = 5, c;

int main()
{
	_asm
	{
		mov ax, a;	// ax = a
		and ax, b;	// ax = ax & b
		mov c, ax;	// c = ax & b
	}

	_asm
	{
		mov ax, a;	// ax = a
		or ax, b;	// ax = ax | b
		mov c, ax;	// c = ax | b
	}

	_asm
	{
		mov ax, a;	// ax = a
		not ax;		// ax = ~a
		mov c, ax;	// c = ~a
	}

	cout << c << endl;
	system("pause");
	return 0;
}