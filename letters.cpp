// The user first enters any sentence in the program.
// Then the program counts how many lowercase and
// uppercase letters in the sentence.
#include <iostream>
#include <string>
using namespace std;

char sentence;
short lCase, uCase, a, b;

void askFor()
{
	cout << "Enter a sentence: ";
}

void getInput()
{
	sentence = cin.get();
}

void Results()
{
	cout << "No. of uppercase letters = " << uCase << endl;
	cout << "No. of lowercase letters = " << lCase << endl;
}

int main()
{
	// First, set ax and bx to 0, then move through each character
	// in a sentence and increment each corresponding letter case by 1.
	_asm
	{
		call askFor;			// Call the askFor function
		mov ax, 0;				// ax = 0
		mov bx, 0;				// bx = 0
	whileLoop:
		call getInput;			// Call the getInput function
		cmp sentence, '\n';		// Compare sentence to '\n'
		Je exitLoop;			// Jump to exitLoop if sentence == '\n'
		cmp sentence, ' ';		// Compare sentence to empty character
		Je whileLoop;			// Jump back to whileLoop if sentence != ' '
		cmp sentence, 'a';		// Compare sentence to 'a'
		Jge lowerCase;			// Jump to lowerCase if sentence => 'a'
		Jmp upperCase;			// Jump to upperCase if sentence !=> 'a'
	upperCase:
		mov ax, uCase;
		inc ax;					// ax++
		mov uCase, ax;			// uCase = ax
		mov a, ax;				// a = ax
		Jmp whileLoop;			// Jump back to whileLoop
	lowerCase:
		mov bx, lCase;
		inc bx;					// bx++
		mov lCase, bx;			// lCase = bx
		mov b, bx;				// b = bx
		Jmp whileLoop;			// Jump back to whileLoop
	exitLoop:
		mov ax, a;				// ax = a
		mov bx, b;				// bx = b
		mov uCase, ax;			// uCase = ax
		mov lCase, bx;			// lCase = bx
		call Results;			// Call the Results function
	}
	system("pause");
	return 0;
}