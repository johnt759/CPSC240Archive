// The interrupt program checks the ax register and
// uses the bits to acquire the information from the PC.
#include <iostream>
#include <bitset>	// Needed to convert hex to bin
using namespace std;
short registerAX = 0xCE9C;
short numPrinters, numFloppy, sizeRAM;

void displayAX()
{
	// Convert hexadecimal to binary form
	std::bitset<16> a(registerAX);
	cout << "AX=" << a << endl;
}

void displayPrinter()
{
	cout << "Number of printers connected to computer: " << numPrinters << endl;
}

void displayFloppy()
{
	cout << "Number of floppy drives: " << numFloppy + 1 << endl;
}

void displayRAM()
{
	cout << "Size of RAM: " << sizeRAM << endl;
}

int main()
{
	_asm
	{
		call displayAX;			// Call the displayAX function
		mov ax, registerAX;
		mov bx, 0;
		mov cx, 0;

	// First, use bits 15 and 16 to determine the number of printers.
	first:
		shr ax, 14;				// Right shift ax by 14
		and ax, 0x0003;			// ax = ax & 0x0003
		mov numPrinters, ax;	// numPrinters = ax
		call displayPrinter;

		// Restore default ax and change bx and cx values
		mov ax, registerAX;
		mov bx, 0;
		mov cx, 0;
		Jmp second;

	// Next, use bits 7 and 8 to determine the number of floppy drives.
	second:
		shr ax, 6;				// Right shift ax by 6
		and ax, 0x0003;			// ax = ax & 0x0002
		add ax, bx;				// ax = ax + bx
		mov numFloppy, ax;		// numFloppy = ax
		call displayFloppy;

		// Restore default ax and change bx and cx values
		mov ax, registerAX;		// ax = registerAX
		mov bx, 16;				// bx = 16
		mov cx, 16;				// cx = 16
		Jmp third;

	// Finally, use bits 3 and 4 to determine the size of RAM.
	third:
		shr ax, 2;				// Right shift ax by 2
		and ax, 0x0003;			// ax = ax & 0x0003
		imul bx;				// ax = ax * bx
		add ax, cx;				// ax = cx + (ax * bx)
		mov sizeRAM, ax;		// sizeRAM = ax
		call displayRAM;
	}
	system("pause");
	return 0;
}