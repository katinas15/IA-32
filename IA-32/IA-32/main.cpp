#include <stdio.h>

int main() {
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
}