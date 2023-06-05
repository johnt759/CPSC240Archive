// This assembly program uses a stack structure
// to compute the operations of float numbers.
// Let e = a(b-cd).
#include<iostream>
using namespace std;
float a = 2.3, b = 4.2, c = 1.6, d = 2.1, e;

int main()
{
	_asm
	{
		fld a;	// st[0] = a
		fld b;	// st[0] = b, st[1] = a
		fld c;	// st[0] = c, st[1] = b, st[2] = a
		fld d;	// st[0] = d, st[1] = c, st[2] = b, st[3] = a
		fmul;	// st[0] = cd, st[1] = b, st[2] = a
		fsub;	// st[0] = b-cd, st[1] = a
		fmul;	// st[0] = a(b-cd)
		fstp e;	// e = a(b-cd)
	}
	cout << "The result is " << e << endl;
	system("pause");
	return 0;
}