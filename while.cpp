// This program utilizes a while loop in assembly code.
#include<iostream>
using namespace std;

int counter = 0;	// Keep track on how many words in a sentence.
char c;				// Needed to inspect each character

void askFor()
{
	cout << "Enter a sentence: ";
}

void readChar()
{
	c = cin.get();
}

void displayTotal()
{
	cout << "Number of words: " << counter << endl;
}

int main()
{
	_asm
	{
		call askFor;		// Call the askFor function
	whileLoop:
		call readChar;		// Call the readChar function
		cmp c, '\n';		// Compare c to newline
		Je exitLoop;		// Jump to exitLoop if c == '\n'
		cmp c, ' ';			// Compare c to empty character
		Jne whileLoop;		// Jump to whileLoop if c != ' '
		inc counter;		// counter++
		Jmp whileLoop;		// Jump back to whileLoop
	exitLoop:
		call displayTotal;	// Call the displayTotal function
	}
	system("pause");
	return 0;
}