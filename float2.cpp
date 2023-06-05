// This program is like float.cpp, except
// it converts fahrenheit to celsius.
#include<iostream>
using namespace std;
float five = 5, thirtyTwo = 32, nine = 9, F = 100, C;

int main()
{
	cout << "Temperature in F: " << F << endl;
	_asm
	{
		fld five;		// st[0] = 5
		fld F;			// st[0] = F, st[1] = 5
		fld thirtyTwo;	// st[0] = 32, st[1] = F, st[2] = 5
		fsub;			// st[0] = F-32, st[1] = 5
		fmul;			// st[0] = 5(F-32)
		fld nine;		// st[0] = 9, st[1] = 5(F-32)
		fdiv;			// st[0] = 5(F-32)/9
		fstp C;			// C = 5(F-32)/9
	}
	cout << "Temperature in C: " << C << endl;
	system("pause");
	return 0;
}