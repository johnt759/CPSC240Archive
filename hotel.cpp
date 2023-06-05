// This program simulates a hotel elevator and
// uses each 16-bit digit to determine which floor
// the elevator will stop at.
#include <iostream>
#include <bitset>				// Needed to convert to binary
using namespace std;
short registerAX = 0x910C;
short floorNum, tempAX, tempBX;

void displayRegister()
{
	std::bitset<16> a(registerAX);
	cout << "AX=" << a << endl;
}

void displayFloor()
{
	cout << "Elevator will stop at floors no. ";
}

void displayFloor2()
{
	cout << floorNum << " ";
}

void displayFloor3()
{
	cout << endl;
}

int main()
{
	_asm
	{
		call displayRegister;
		call displayFloor;
		mov ax, registerAX;	// ax = registerAX
		mov bx, 16;			// bx = 0
	forLoop:
		cmp bx, 0;				// Compare bx to 0
		Jng exitLoop;			// Jump to exitLoop if bx !> 0
		test ax, 0x8000;		// Use the AND-condition to test ax
		Jz nextLoop;			// Jump to nextLoop if it is zero
		mov tempAX, ax;			// tempEAX = ax
		mov floorNum, bx;		// floorNum = bx
		mov tempBX, bx;			// tempEBX = bx
		call displayFloor2;
		mov ax, tempAX;			// ax = tempAX
		mov bx, tempBX;			// bx = tempBX
	nextLoop:
		shl ax, 1;				// Left shift ax by 1
		dec bx;					// bx--;
		Jmp forLoop;
	exitLoop:
		call displayFloor3;
	}
	system("pause");
	return 0;
}