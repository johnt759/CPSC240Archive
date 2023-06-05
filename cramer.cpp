// This program uses Cramer's Rule in order
// to find X and Y in systems of equations.
#include <iostream>
using namespace std;

short a, b, c, d, e, f, x, y, z;

int main()
{
	cout << "This program solves the system\n";
	cout << "\taX + bY = c\n";
	cout << "\tdX + eY = f\n";
	cout << "Enter the values of a, b, and c: ";
	cin >> a >> b >> c;
	cout << "Enter the values of d, e, and f: ";
	cin >> d >> e >> f;
	_asm
	{
		// Let z be a temporary variable when solving for x and y.
		mov ax, a;	// ax = a
		mov bx, e;	// bx = e
		imul bx;	// ax = ae
		mov cx, b;	// cx = b
		mov dx, d;	// dx = d
		imul dx;	// cx = bd
		sub ax, cx;	// ax = ae - bd
		mov z, ax;	// z = ax

		mov ax, a;	// ax = a
		mov bx, f;	// bx = f
		imul bx;	// ax = af
		mov cx, c;	// cx = c
		mov dx, d;	// dx = d
		imul dx;	// cx = cd
		sub ax, cx;	// ax = af - cd
		idiv z;		// ax = (af - cd) / (ae - bd)
		mov y, ax;	// y = ax

		mov ax, c;	// ax = c
		mov bx, e;	// bx = e
		imul bx;	// ax = ce
		mov cx, b;	// cx = b
		mov dx, f;	// dx = f
		imul dx;	// cx = bf
		sub ax, cx;	// ax = ce - bf
		idiv z;		// ax = (ce - bf) / (ae - bd)
		mov x, ax;	// x = ax
	}
	cout << "X = " << x << endl;
	cout << "Y = " << y << endl;
	system("pause");
	return 0;
}