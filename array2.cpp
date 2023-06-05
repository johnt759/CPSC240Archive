#include<iostream>
using namespace std;
// This program is like array.cpp, but this time
// a 2-D array is utilized, so the operations will
// be the same as the previous, albeit with some changes.
int b[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int i;
int total;

int main()
{
	_asm
	{
		mov eax, 0;		// eax = 0
		mov i, 0;		// i = 0
		lea esi, [b];	// esi = [b]
	forLoop:
		cmp i, 9;		// Compare i to 9
		Je done;		// Jump to done if i == 9
		add eax, [esi];	// eax += b[][]
		add esi, 4;		// esi += 4
		inc i;			// i++
		Jmp forLoop;
	done:
		mov total, eax;	// total = eax
	}
	cout << "Total of the 2-D array: " << total << endl;
	system("pause");
	return 0;
}