// The user enters any number for the total average
// until a -1 is inputted. That sentinel value exits
// the loop and returns the average.
#include<iostream>
using namespace std;

int i, num, sum, average;

void display()
{
	cout << "Enter your score (-1) to stop: ";
}

void getInput()
{
	cin >> num;
}

int main()
{
	_asm
	{
		mov sum, 0;				// sum = 0
		mov i, 0;				// i = 1
	whileLoop:
		call display;			// Call the function display
		call getInput;			// Call the function getInput
		cmp num, -1;			// Compare average to -1
		Je exitLoop;			// Jump to exitLoop if average == -1
		mov eax, sum;			// eax = sum
		add eax, num;			// sum += num
		mov sum, eax;			// sum = eax
		inc i;					// i++
		Jmp whileLoop;			// Jump back to whileLoop
	exitLoop:
		mov eax, sum;			// eax = sum
		mov edx, 0;				// edx = 0
		mov ebx, i;				// ebx = i
		idiv ebx;				// eax = eax / ebx
		mov average, eax;		// average = eax
	}
	cout << "Your average is " << average << endl;
	system("pause");
	return 0;
}