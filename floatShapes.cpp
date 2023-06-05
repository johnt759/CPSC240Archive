// The program is similar to shapes.cpp, except that
// float numbers will be used in finding perimeters
// and areas of the geometric shapes.
#include<iostream>
using namespace std;
float a, b, c, h, l, w, two = 2;
float pTri, aTri, pRec, aRec;

int main()
{
	cout << "Enter the values of a, b, c, and h for the triangle: ";
	cin >> a >> b >> c >> h;
	cout << "Enter the length and the width of the rectangle: ";
	cin >> l >> w;
	_asm
	{
		fld h;		// st[0] = h
		fld two;	// st[0] = 2, st[1] = h
		fdiv;		// st[0] = (h/2)
		fld c;		// st[0] = c, st[1] = (h/2)
		fmul;		// st[0] = (ch)/2
		fstp aTri;	// aTri = (ch)/2
		fld c;		// st[0] = c
		fld b;		// st[0] = b, st[1] = c
		fld a;		// st[0] = a, st[1] = b, st[2] = c
		fadd;		// st[0] = a+b, st[1] = c
		fadd;		// st[0] = a+b+c
		fstp pTri;	// pTri = a+b+c
		fld l;		// st[0] = l
		fld w;		// st[0] = w, st[1] = l
		fmul;		// st[0] = wl
		fstp aRec;	// aRec = wl
		fld l;		// st[0] = length
		fld two;	// st[0] = 2, st[1] = l
		fmul;		// st[0] = 2l
		fld w;		// st[0] = w, st[1] = 2l
		fld two;	// st[0] = 2, st[1] = w, st[2] = 2l
		fmul;		// st[0] = 2w, st[1] = 2l
		fadd;		// st[0] = 2w+2l
		fstp pRec;	// pRec = 2w+2l
	}
	cout << "Triangle\n";
	cout << "\tArea.................." << aTri << endl;
	cout << "\tPerimeter............." << pTri << endl;
	cout << "Rectangle\n";
	cout << "\tArea.................." << aRec << endl;
	cout << "\tPerimeter............." << pRec << endl;
	system("pause");
	return 0;
}