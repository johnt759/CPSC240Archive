#include <iostream>
using namespace std;

int main()
{
	int n1, n2, sum;

	cout << "Enter the 2 numbers: ";
	cin >> n1 >> n2;

	// Assembly language code below
	_asm
	{
		mov eax, n1;	// eax = n1
		add eax, n2;	// eax = n1 + n2
		mov sum, eax;	// sum = eax
	}
	cout << "The sum of " << n1 << " and " << n2 << " is " << sum << ".\n";

	system("pause");
	return 0;
}