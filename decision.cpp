#include <iostream>
using namespace std;

int main()
{
	short a, b, c, max;

	cout << "Enter the 3 numbers: ";
	cin >> a >> b >> c;
	_asm
	{
		mov ax, a;	// ax = a
		mov bx, b;	// bx = b
		cmp ax, b;	// compare ax and b
		Jng testBC;	// jump to testBC if ax !> b
	testC:
		cmp ax, c;	// compare ax and c
		Jng testBC;	// jump to testBC if ax !> c
	maxA:
		mov cx, a;	// cx = a
		Jmp display;
	testBC:
		cmp bx, c;	// Compare bx and c
		Jnge maxC;	// jump to maxC if bx !> c
	maxB:
		mov cx, b;	// cx = b
		Jmp display;
	maxC:
		mov cx, c;	// cx = c
		Jmp display;
	display:
		mov max, cx;	// max = cx
	}
	cout << "Maximum number: " << max << endl;
	system("pause");
	return 0;
}