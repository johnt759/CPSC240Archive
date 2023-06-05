#include <iostream>
using namespace std;

short total, i;

int main()
{
	_asm
	{
		mov ax, 0;	// ax = 0
		mov i, 1;	// i = 1
	forLoop:
		cmp i, 7;	// Is i <= 7?
		Jnle exitLoop;
		add ax, i;	// ax += i
		inc i;		// i++
		Jmp forLoop;
	exitLoop:
		mov total, ax;	// total = ax;
	}
	cout << total << endl;
	
	system("pause");
	return 0;
}