// Once again, the code is like
// float.cpp and float2.cpp, but the
// equation will be x = -b+sqrt(4ac).
#include<iostream>
using namespace std;
float a = 2, b = 3, c = 5, four = 4, minusOne = -1, x;

int main()
{
	_asm
	{
		fld b;			// st[0] = b
		fld minusOne;	// st[0] = -1, st[1] = b
		fmul;			// st[0] = -b
		fld four;		// st[0] = 4, st[1] = -b
		fld a;			// st[0] = a, st[1] = 4, st[2] = -b
		fmul;			// st[0] = 4a, st[1] = -b
		fld c;			// st[0] = c, st[1] = 4a, st[2] = -b
		fmul;			// st[0] = 4ac, st[1] = -b
		fsqrt;			// st[0] = sqrt(4ac), st[1] = -b
		fadd;			// st[0] = -b+sqrt(4ac)
		fstp x;			// x = -b+sqrt(4ac)
	}
	cout << "The answer is " << x << endl;
	system("pause");
	return 0;
}