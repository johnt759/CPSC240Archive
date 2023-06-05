// This program reads in each pin as a 4-digit
// hexadecimal number and checks if the total
// digits is an even number.
#include<iostream>
using namespace std;

short pin1 = 0xBEEF, pin2 = 0xFADE, pin3 = 0xCABE, temp;
short isEvenID;		// Will be used to determine whether pin is even or not
short counter = 0;	// Use counter as a for loop increment variable

void evenID()
{
	cout << hex << isEvenID << " is a valid ID for the family\n";
}

void oddID()
{
	cout << hex << isEvenID << " is not a valid ID for the family\n";
}

int main()
{
	_asm
	{		
		mov ax, pin1;		// ax = pin1
		mov cx, 0;			// Let cx be the sum
		mov dx, 0;			// dx = 0
	firstTest:
		cmp dx, 4;			// Cmp dx to 4
		Jnl firstSum;		// Jump to firstSum if dx !< 4
		mov bx, ax;			// bx = ax
		and bx, 0x000f;		// bx = bx & 0x000f
		add cx, bx;			// cx += bx
		shr ax, 4;			// Right shift ax by 4
		mov temp, ax;		// temp = ax
		inc dx;				// dx++;
		mov ax, temp;		// ax = temp
		Jmp firstTest;		// Loop back to firstTest
	firstSum:
		test cx, 1;			// Test the cx to 1 with AND condition
		Jz isEven;			// Jump to isEven if cx % 2 == 0
		Jmp isNotEven;		// Jump to isNotEven if otherwise
	isEven:
		mov ax, pin1;		// ax = pin1
		mov isEvenID, ax;
		call evenID;		// Call the evenID function
		Jmp endFirst;
	isNotEven:
		mov ax, pin1;		// ax = pin1
		mov isEvenID, ax;
		call oddID;			// Call the oddID function
		Jmp endFirst;
		
	// Restore default values, but change ax to a new pin
	endFirst:
		mov ax, pin2;		// ax = pin2
		mov cx, 0;			// Let cx be the sum
		mov dx, 0;			// dx = 0
	secondTest:
		cmp dx, 4;			// Cmp dx to 4
		Jnl secondSum;		// Jump to secondSum if dx !< 4
		mov bx, ax;			// bx = ax
		and bx, 0x000f;		// bx = bx & 0x000f
		add cx, bx;			// cx += bx
		shr ax, 4;			// Right shift ax by 4
		mov temp, ax;		// temp = ax
		inc dx;				// dx++;
		mov ax, temp;		// ax = temp
		Jmp secondTest;		// Loop back to secondTest
	secondSum:
		test cx, 1;			// Test the cx to 1 with AND condition
		Jz isEven2;			// Jump to isEven2 if cx % 2 == 0
		Jmp isNotEven2;		// Jump to isNotEven2 if otherwise
	isEven2:
		mov ax, pin2;		// eax = pin2
		mov isEvenID, ax;
		call evenID;		// Call the evenID function
		Jmp endSecond;
	isNotEven2:
		mov ax, pin2;		// eax = pin2
		mov isEvenID, ax;
		call oddID;			// Call the oddID function
		Jmp endSecond;

	// Restore default values, but change ax to a new pin
	endSecond:
		mov ax, pin3;		// ax = pin3
		mov cx, 0;			// Let cx be the sum
		mov dx, 0;			// dx = 0
	thirdTest:
		cmp dx, 4;			// Cmp dx to 4
		Jnl thirdSum;		// Jump to thirdSum if dx !< 4
		mov bx, ax;			// bx = ax
		and bx, 0x000f;		// bx = bx & 0x000f
		add cx, bx;			// cx += bx
		shr ax, 4;			// Right shift ax by 4
		mov temp, ax;		// temp = ax
		inc dx;				// dx++;
		mov ax, temp;		// ax = temp
		Jmp thirdTest;		// Loop back to thirdTest
	thirdSum:
		test cx, 1;			// Test the cx to 1 with AND condition
		Jz isEven3;			// Jump to isEven3 if cx % 2 == 0
		Jmp isNotEven3;		// Jump to isNotEven3 if otherwise
	isEven3:
		mov ax, pin3;		// ax = pin3
		mov isEvenID, ax;
		call evenID;		// Call the evenID function
		Jmp endProgram;
	isNotEven3:
		mov ax, pin3;		// ax = pin3
		mov isEvenID, ax;
		call oddID;			// Call the oddID function
		Jmp endProgram;
	endProgram:
	}
	system("pause");
	return 0;
}