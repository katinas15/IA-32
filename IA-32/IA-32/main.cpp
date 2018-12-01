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

int main(/*int argc, char** argv*/) {

	/*if (argc < 2) {
		printf("Error! Missing parameters");
			return 0;
	}

	int num = int(argv[1]);*/
	int num = 16;
	std::string result;
	decToBin(num);
	__asm {
		push eax
		push ebx
		push ecx
		push edx
		push ax
		//-------------------------
		xor ax,ax		//ax = 0, nustatoma string pozicija
		mov eax, num
		xor edx, edx     //edx = 0,			kitaip neveikia dalyba
		cmp eax,0
			jle end //jump jeigu skaicius mazesnis arba lygus 0
		mov ebx, eax

		start:
			mov ebx,eax				//ebx = eax,		perkeliama kad po operacijos nedingtu skaicius
			mov ecx, 2				//ecx = 2,			kad butu galima dalyba is 
			div ecx					//eax = num / 2,	dalyba is 2
			mov ecx,eax				//ecx = eax,		gautas dalybos skaicius perkeliamas i ecx
			imul ecx,2				//ecx *= 2,			po dalybos gautas skaicius padauginamas is 2 
			sub ebx,ecx				//ebx = ebx - ecx,	gaunama liekana
			mov result[ax], ebx		//registras perkeliamas i string
			inc ax					//ax++ keiciama string pozicija
			cmp eax, 0				//tikrina ar likes skaicius daugiau uz 0
				jg start			//jei ne nulis tesiama toliau
			//mov edx,ebx
			//int 21h
		end:	
		//-------------------------
		pop eax
		pop ebx
		pop ecx
		pop edx
		pop ax
	}
	std::cout << "assembly = "<< result;
	getchar();
}