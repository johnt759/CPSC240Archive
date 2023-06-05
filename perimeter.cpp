#include<iostream>
using namespace std;

int main()
{
	int a = 10,
		b = 15,
		c = 7,
		rPerim,
		sPerim,
		tPerim;

	// Assembly language code below
	_asm
	{
		// calculate the rectangle's perimeter
		mov eax, a;			// eax = a
		add eax, b;			// eax = a + b
		add eax, eax;		// eax = 2a + 2b
		mov rPerim, eax;	// rPerim = eax
		// calculate the triangle's perimeter
		mov eax, a;			// eax = a
		add eax, b;			// eax = a + b
		add eax, c;			// eax = a + b + c
		mov tPerim, eax;	// tPerim = eax
		// calculate the square's perimeter
		mov eax, c;			// eax = c
		add eax, eax;		// eax = 2c
		add eax, eax;		// eax = 4c
		mov sPerim, eax;	// sPerim = eax
	}

	// Display the perimeter
	cout << "Rectangle Perimeter: " << rPerim << endl;
	cout << "Square Perimeter: " << sPerim << endl;
	cout << "Triangle Perimeter: " << tPerim << endl;

	system("pause");
	return 0;
}