#include <iostream>
using namespace std;

int main()
{
	// Divide 358 into individuals numbers and then
	// add all of them to acquire the sum.
	// Also use the hundred and ten as the variables
	// and the d values to hold the numbers.
	short n = 358, r, hundred = 100, ten = 10, d3, d2, d1;

	_asm
	{
		mov ax, n;		// ax = n
		cwd;			// dx:ax = n
		idiv hundred;	// ax = 3, dx = 58
		mov d3, ax;		// d3 = 3
		mov ax, dx;		// ax = 58
		cwd;			// dx:ax = 58
		idiv ten;		// ax = 5, dx = 8
		mov d2, ax;		// d2 = 5
		mov ax, dx;		// ax = 8
		mov d1, ax;		// d1 = 8
		add ax, d2;		// ax = 8 + 5
		add ax, d3;		// ax = 8 + 5 + 3
		mov r, ax;		// r = ax
	}

	cout << "The sum of the digits in 358 is " << r << endl;

	system("pause");
	return 0;
}