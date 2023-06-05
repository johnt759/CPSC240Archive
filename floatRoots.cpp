// This program uses float operations to
// find the roots via the quadratic formula.
#include<iostream>
using namespace std;
float a, b, c, x1, x2, minusOne = -1, two = 2, minusFour = -4;

int main()
{
	cout << "To see the two real roots of aX^2+bX+c=0, ";
	cout << "enter the a, b, and c values: ";
	cin >> a >> b >> c;
	_asm
	{
		fld b;			// st[0] = b
		fld minusOne;	// st[0] = -1, st[1] = b
		fmul;			// st[0] = -b
		fld b;			// st[0] = b, st[1] = -b
		fld b;			// st[0] = b, st[1] = b, st[2] = -b
		fmul;			// st[0] = b^2, st[1] = -b
		fld a;			// st[0] = a, st[1] = b^2, st[2] = -b
		fld minusFour;	// st[0] = -4, st[1] = a, st[2] = b^2, st[3] = -b
		fmul;			// st[0] = -4a, st[1] = b^2, st[2] = -b
		fld c;			// st[0] = c, st[1] = -4a, st[2] = b^2, st[3] = -b
		fmul;			// st[0] = -4ac, st[1] = b^2, st[2] = -b
		fadd;			// st[0] = (b^2)-4ac, st[1] = -b
		fsqrt;			// st[0] = sqrt((b^2)-4ac), st[1] = -b
		fadd;			// st[0] = -b+sqrt((b^2)-4ac)
		fld a;			// st[0] = a, st[1] = -b+sqrt((b^2)-4ac)
		fld two;		// st[0] = 2, st[1] = a, st[2] = -b+sqrt((b^2)-4ac)
		fmul;			// st[0] = 2a, st[1] = -b+sqrt((b^2)-4ac)
		fdiv;			// st[0] = (-b+sqrt((b^2)-4ac))/2a
		fstp x1;

		fld b;			// st[0] = b
		fld minusOne;	// st[0] = -1, st[1] = b
		fmul;			// st[0] = -b
		fld b;			// st[0] = b, st[1] = -b
		fld b;			// st[0] = b, st[1] = b, st[2] = -b
		fmul;			// st[0] = b^2, st[1] = -b
		fld a;			// st[0] = a, st[1] = b^2, st[2] = -b
		fld minusFour;	// st[0] = -4, st[1] = a, st[2] = b^2, st[3] = -b
		fmul;			// st[0] = -4a, st[1] = b^2, st[2] = -b
		fld c;			// st[0] = c, st[1] = -4a, st[2] = b^2, st[3] = -b
		fmul;			// st[0] = -4ac, st[1] = b^2, st[2] = -b
		fadd;			// st[0] = (b^2)-4ac, st[1] = -b
		fsqrt;			// st[0] = sqrt((b^2)-4ac), st[1] = -b
		fsub;			// st[0] = -b-sqrt((b^2)-4ac)
		fld a;			// st[0] = a, st[1] = -b-sqrt((b^2)-4ac)
		fld two;		// st[0] = 2, st[1] = a, st[2] = -b-sqrt((b^2)-4ac)
		fmul;			// st[0] = 2a, st[1] = -b-sqrt((b^2)-4ac)
		fdiv;			// st[0] = (-b-sqrt((b^2)-4ac))/2a
		fstp x2;
	}
	cout << "X1=" << x1 << endl;
	cout << "X2=" << x2 << endl;
	system("pause");
	return 0;
}