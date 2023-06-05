// The do-while loop is demonstrated in assembly code.
#include <iostream>
using namespace std;

char ans;

void displayMessage()
{
	cout << "Happy Valentine's Day!\n" << "Continue? (y/n) ";
	cin >> ans;
}

int main()
{
	_asm
	{
	doLoop:
		call displayMessage;	// Call the displayMessage function
		cmp ans, 'y';			// compare ans to 'y'
		Jne exitLoop;			// Jump to exitLoop if ans != 'y'
		Jmp doLoop;				// Jump back to doLoop
	exitLoop:
	}
	cout << "Bye!";
}