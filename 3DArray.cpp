// This program is like 2DArray.cpp, except that a 3-D
// array will be used to read in the number of shirts by
// their color, size, and sleeve length.
#include<iostream>
using namespace std;
// The array goes in that order: [color][size][sleeve length].
// Medium size shirts are located at [][1][]
// Short sleeve shirts are located at [][][0]
// Red shirts are located at [0][][]
int a[3][3][2] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 };
int i, numShirts, numMedium, numShortSleeves, numRed;

void total()
{
	cout << "There are " << numShirts << " shirts in total.\n";
}

void medium()
{
	cout << "There are " << numMedium << " medium-sized shirts.\n";
}

void ShortSleeves()
{
	cout << "There are " << numShortSleeves << " short-sleeved shirts.\n";
}

void red()
{
	cout << "There are " << numRed << " red shirts.\n";
}

int main()
{
	_asm
	{
		mov eax, 0;
		mov i, 0;
		lea esi, [a];
	firstLoop:
		cmp i, 18;					// Compare i to 18
		Je endofFirst;				// Jump to endofFirst if i == 18
		add eax, [esi];				// eax += a[][][]
		add esi, 4;					// esi+=4
		inc i;						// i++
		Jmp firstLoop;
	endofFirst:
		mov numShirts, eax;			// numShirts = eax
		call total;
		// Restore default values for eax and i, but change the
		// starting position for the esi array.
		mov eax, 0;
		mov i, 0;
		lea esi, [a];
		add esi, 8;
	secondLoop:
		cmp i, 3;					// Compare i to 3
		Je endofSecond;				// Jump to endofSecond if i == 3
		add eax, [esi];				// eax += a[][1][0]
		add esi, 4;					// esi += 4
		add eax, [esi];				// eax += a[][1][1]
		add esi, 20;				// esi += 20
		inc i;						// i++
		Jmp secondLoop;
	endofSecond:
		mov numMedium, eax;			// numMedium = eax
		call medium;
		// Restore default values for eax and i, but change the
		// starting position for the esi array.
		mov eax, 0;
		mov i, 0;
		lea esi, [a];
	thirdLoop:
		cmp i, 9;					// Compare i to 9
		Je endofThird;				// Jump to endofThird if i == 9
		add eax, [esi];				// eax += a[][][0]
		add esi, 8;					// esi += 8
		inc i;						// i++
		Jmp thirdLoop;
	endofThird:
		mov numShortSleeves, eax;	// numShortSleeves = eax
		call ShortSleeves;
		// Restore default values for eax and i, but change the
		// starting position for the esi array.
		mov eax, 0;
		mov i, 0;
		lea esi, [a];
	fourthLoop:
		cmp i, 6;					// Compare i to 6
		Je endofFourth;				// Jump to endofFourth if i == 6
		add eax, [esi];				// eax += a[0][][]
		add esi, 4;					// esi += 4
		inc i;						// i++
		Jmp fourthLoop;
	endofFourth:
		mov numRed, eax;			// numRed = eax
		call red;
	}
	system("pause");
	return 0;
}