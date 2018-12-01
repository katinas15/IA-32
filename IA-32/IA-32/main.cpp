#include <stdio.h>
void decToBin(int num) {
	while (num != 0)
	{
		int rem = num % 2;
		num /= 2;
		printf("%d",rem);
	}
	printf("\n");
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