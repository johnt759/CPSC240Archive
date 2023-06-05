// This program uses bitwise operations to check which
// sprinklers are on and which are defective.
#include <iostream>
#include <bitset>
using namespace std;
short sampleNum = 0x6A2F;
short numOnes, defectiveNum, tempAX, tempCX;

void displayBin()
{
	// Convert hexadecimal to binary form
	std::bitset<16> a(sampleNum);
	cout << "AX=" << a << endl;
}

void numberSprinklers()
{
	// Count how many sprinklers are still functional
	// and return the number of sprinklers on.
	cout << numOnes << " sprinklers are ON\n";
}

void defective()
{
	// Count how many sprinklers are defective
	cout << "Defective sprinklers: ";
}

void whichDefective()
{
	cout << defectiveNum << " ";
}

void endOfDefective()
{
	cout << endl;
}

int main()
{
	_asm
	{
		// For the first part of the assembly code, display the binary value,
		// then locate how many 1's are there in said value.
		call displayBin;	// Call the displayBin function
		mov ax, sampleNum;	// ax = sampleNum
		mov bx, 0;			// bx = 0
		mov cx, 0;			// cx = 0
	forLoop:
		cmp cx, 16;			// Compare cx to 16
		Jnl exitFirstLoop;	// Jump to exitFirstLoop if cx !< 16
		test ax, 1;			// Use the AND condition to test ax to 1
							// In other words, is sampleNum % 2 == 1?
		Jz nextStep;		// Jump to nextStep if the modulus is 0
		inc bx;				// bx++
	nextStep:
		shr ax, 1;		// Right shift ax by 2
		inc cx;			// cx++
		Jmp forLoop;	// Jump back to forLoop
	exitFirstLoop:
		mov numOnes, bx;
		call numberSprinklers;

		// For this second part of the assembly code, call the defective
		// function first, then restore default values for eax and ecx
		call defective;
		mov ax, sampleNum;		// ax = sampleNum
		mov cx, 16;				// cx = 0
	forLoop2:
		cmp cx, 0;				// Compare cx to 0
		Jng exitSecondLoop;		// Jump to exitSecondLoop if cx !> 0
		test ax, 0x8000;		// Use the AND condition to test bit-15 of ax
		Jnz nextStep2;			// Jump to nextStep2 if the result isn't zero
		mov tempAX, ax;			// Save the ax to a temp variable
		mov defectiveNum, cx;
		mov tempCX, cx;			// Save cx to another temp variable
		call whichDefective;	// Print out each number
		mov ax, tempAX;			// Move the temp back to ax
		mov cx, tempCX;			// and also back to cx as well
	nextStep2:
		shl ax, 1;				// Left shift ax by 2
		dec cx;					// cx--
		Jmp forLoop2;			// Jump back to forLoop
	exitSecondLoop:
		call endOfDefective;	// 3 seperate functions needed for simplicity reasons
	}
	system("pause");
	return 0;
}