// This program reads in the array of shirts consisting
// of each color and determines how many are there
#include<iostream>
using namespace std;

// Number of medium shirts are at [2][].
// Number of blue shirts are at [][3].
int b[4][4] = { 10, 20, 30, 40, 20, 10, 40, 30, 5, 15, 20, 25, 30, 25, 20, 15 };
int i, numShirts, numMedium, numBlue;

void total()
{
	cout << "There are " << numShirts << " shirts in total.\n";
}

void medium()
{
	cout << "There are " << numMedium << " medium-sized shirts.\n";
}

void blue()
{
	cout << "There are " << numBlue << " blue shirts.\n";
}

int main()
{
	_asm
	{
		mov eax, 0;		// eax = 0
		mov i, 0;		// i = 0
		lea esi, [b];	// esi = [b]
	firstLoop:
		cmp i, 16;		// Compare i to 16
		Je endofFirst;	// Jump to endofFirst if i == 16
		add eax, [esi];	// eax += b[][]
		add esi, 4;		// esi += 4
		inc i;			// i++
		Jmp firstLoop;
	endofFirst:
		mov numShirts, eax;
		call total;
		// Restore default values for eax and i, but change
		// the starting position for the esi array.
		mov eax, 0;
		mov i, 0;
		lea esi, [b];
		add esi, 4;		// esi += 4
	secondLoop:
		cmp i, 4;		// Compare i to 4
		Je endofSecond;	// Jump to endofSecond if i == 4
		add eax, [esi];	// eax += b[][1]
		add esi, 16;	// esi += 16
		inc i;			// i++
		Jmp secondLoop;
	endofSecond:
		mov numMedium, eax;
		call medium;
		// Restore default values for eax and i, but change
		// the starting position for the esi array.
		mov eax, 0;
		mov i, 0;
		lea esi, [b];
		add esi, 32;	// esi += 32
	thirdLoop:
		cmp i, 4;		// Compare i to 4
		Je endofThird;	// Jump to endofThird if i == 4
		add eax, [esi];	// eax += b[2][]
		add esi, 4;		// esi += 4
		inc i;			// i++
		Jmp thirdLoop;
	endofThird:
		mov numBlue, eax;
		call blue;
	}
	system("pause");
	return 0;
}