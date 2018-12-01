#include <stdio.h>
#include <string>
#include <iostream>

void decToBin(int num) {
	using namespace std;
	string a;
	while (num > 0)
	{
		a.insert(0, to_string(num % 2));
		num /= 2;
	}
	cout << "c++ = " << a << endl;
}

int main() {
	int num = 1234;
	decToBin(num);
	__asm {
		push eax
		push ebx
		push ecx
		push edx
		//-------------------------



		//-------------------------
		pop eax
		pop ebx
		pop ecx
		pop edx
	}
	getchar();
}
