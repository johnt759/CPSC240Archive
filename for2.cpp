// This program reads in the user input and
// via for loop, processes it in a sum.
#include <iostream>
using namespace std;

int i, total, num;

void askData()
{
	cout << "Enter 7 numbers: ";
}

void readData()
{
	cin >> num;
}

int main()
{
	_asm
	{
		call askData;	// Call the askData function
		mov eax, 0;		// eax = 0
		mov i, 1;		// i = 1
	forLoop:
		cmp i, 7;		// compare i to 7
		Jnle exitLoop;	// Jump to exitLoop if i !<= 7
		call readData;	// Call the readData function
		add eax, num;	// eax += num
		inc i;			// i++
		Jmp forLoop;	// Jump back to forLoop
	exitLoop:
		mov total, eax;	// total = eax
	}
	cout << "The total is " << total << endl;
	system("pause");
	return 0;
}