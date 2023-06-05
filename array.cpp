#include<iostream>
using namespace std;
// This is a simple assembly code that
// demonstrates using arrays via lea command.
// Here, the sum is acquired by looping through
// each element and adding them up.
int a[3] = { 5, 10, 15 };
int i;	// Let i be the loop counter.
int sum;

int main()
{
	_asm
	{
		mov eax, 0;		// eax = 0
		mov i, 0;		// i = 0
		lea esi, [a];	// esi =[a]
	forLoop:
		cmp i, 3;		// Compare i to 3
		Je done;		// Jump to done if i == 3
		add eax, [esi];	// eax += a[i]
		inc i;			// i++
		add esi, 4;		// esi += 4
		Jmp forLoop;
	done:
		mov sum, eax;	// sum = eax
	}
	cout << "The sum of the array is " << sum << endl;
	system("pause");
	return 0;
}