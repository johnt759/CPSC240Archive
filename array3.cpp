#include<iostream>
using namespace std;
// This is the same program just like array2.cpp,
// except only the specified elements in the array
// position are used to find the total.
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
		add esi, 24;	// esi += 24
	forLoop:
		cmp i, 3;		// Compare i to 3
		Je done;		// Jump to done if i == 3
		add eax, [esi];	// eax += b[2][]
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