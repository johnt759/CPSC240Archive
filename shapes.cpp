#include <iostream>
using namespace std;

int main()
{
	// The user enters the numbers as input and they
	// are used to find the perimter and area of the
	// triangle and rectangle.
	// pTriangle, pRectangle, aTriangle, and aRectangle stands
	// for triangle's perimeter, triangle's area, rectangle's
	// perimeter, and rectangle's area.
	int a, b, c, h, l, w, two = 2;
	int pTriangle, pRectangle, aTriangle, aRectangle;
	cout << "Enter the values of a, b, c, and h for the triangle: ";
	cin >> a >> b >> c >> h;
	cout << "Enter the length and width of the rectangle: ";
	cin >> l >> w;
	_asm
	{
		mov eax, a;				// eax = a
		add eax, b;				// eax = a + b
		add eax, c;				// eax = a + b + c
		mov pTriangle, eax;		// pTriangle = eax
		mov eax, l;				// eax = l
		add eax, l;				// eax = 2l
		add eax, w;				// eax = 2l + w
		add eax, w;				// eax = 2l + 2w
		mov pRectangle, eax;	// pRectangle = eax
		mov eax, c;				// eax = c
		imul h;					// eax = c * h
		idiv two;				// eax = (c * h) / 2
		mov aTriangle, eax;		// aTriangle = eax
		mov eax, l;				// eax = l
		imul w;					// eax = l * w
		mov aRectangle, eax;	// aRectangle = eax
	}
	cout << "Triangle\n";
	cout << "\tArea: " << aTriangle << endl;
	cout << "\tPerimeter: " << pTriangle << endl;
	cout << "Rectangle\n";
	cout << "\tArea: " << aRectangle << endl;
	cout << "\tPerimeter: " << pRectangle << endl;
	system("pause");
	return 0;
}