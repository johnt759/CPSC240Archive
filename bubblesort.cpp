// The array will be sorted in numerical order
// via the algorithm of bubble sorting.
#include<iostream>
using namespace std;
int a[5] = { 9, 3, 22, 8, 1 };
int i, j;

void displayArray()
{
	cout << "Original array a: ";
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void displayArray2()
{
	cout << "New array a: ";
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	_asm
	{
		call displayArray;
		mov eax, 0;			// eax = 0
		mov ebx, 0;			// ebx = 0
		lea esi, [a];		// esi = [a]
		mov i, 0;			// i = 0
	outerLoop:
		cmp i, 4;			// Compare i to 4
		Jg endProgram;		// Jump to endProgram if i > 4
		mov j, 0;			// j = 0 for each outer loop iteration
	innerLoop:
		cmp j, 4;			// Compare j to 4
		Je outerLoop2;		// Jump to outerLoop2 if j > 4
		mov eax, [esi];		// eax = [a]
		mov ebx, [esi+4];	// ebx = [a+4]
		cmp ebx, eax;		// Compare [a] to [a+4]
		Jg innerLoop2;		// Jump to innerLoop2 if [a] < [a+4]
		xchg eax, ebx;		// Swap [a] with [a+4]
		mov [esi], eax;		// [esi] = eax
		mov [esi+4], ebx;	// [esi+4] = ebx
	innerLoop2:
		add esi, 4;			// esi += 4
		inc j;				// j++
		Jmp innerLoop;
	outerLoop2:
		inc i;				// i++
		lea esi, [a];		// Move the 'pointer' back to a[0] and reload the array	
		Jmp outerLoop;
	endProgram:		
		call displayArray2;
	}
	system("pause");
	return 0;
}