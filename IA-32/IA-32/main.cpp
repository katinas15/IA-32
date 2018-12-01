#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

void decToBin(int num) {
	using namespace std;
	string a;
	while (num > 0)
	{
		a.insert(0, to_string(num % 2));
		num /= 2;
	}
	cout << "c++      = " << a << endl;
}

std::vector<int> result;
int temp;
void pushBinary() {
	result.push_back(temp);
}

int main(int argc, char** argv) {

	if (argc < 2) {
		printf("Error! Missing parameters");
			return 0;
	}

	int num = atoi(argv[1]);
	
	decToBin(num);
	__asm {
		push eax
		push ebx
		push ecx
		push edx
		//---------------------------------------------------------------------------------------------

		mov eax, num				//eax = num
		xor edx, edx				//edx = 0,			kitaip neveikia dalyba
		cmp eax,0					
			jle end					//jump jeigu skaicius mazesnis arba lygus 0
		mov ebx, eax				//ebx = eax

		start:
			mov eax, ebx			//ebx = eax,		perkeliama kad po operacijos nedingtu skaicius
			mov ecx, 2				//ecx = 2,			kad butu galima dalyba is 
			div ecx					//eax = num / 2,	dalyba is 2
			mov ecx, eax			//ecx = eax,		gautas dalybos skaicius perkeliamas i ecx
			imul ecx, 2				//ecx *= 2,			po dalybos gautas skaicius padauginamas is 2 
			sub ebx, ecx			//ebx = ebx - ecx,	gaunama liekana

			mov temp, ebx			//liekana perkeliama i int, kad butu galima ikelti i vector
			mov ebx, eax			//del kazkokiu priezasciu eax, ecx ir edx value pasikeicia -
									// - todel issaugau skaiciu i ebx kuris nepasikeicia
			call offset pushBinary	//liekana perkeliama i vector
			mov eax,0				//reikia pakeisti i 0 nes kitaip del neaiskiu priezasciu i kita value pasikeicia
			mov ecx,0
			mov edx,0
			cmp ebx, 0				//tikrina ar likes skaicius daugiau uz 0
				jg start			//jei ne nulis tesiama toliau
		end:	
		//---------------------------------------------------------------------------------------------
		pop eax
		pop ebx
		pop ecx
		pop edx
	}
	std::cout << "assembly = ";
	for (int i = result.size()-1; i >= 0; i--) {	//reikia isvesti atbuline tvarka
		std::cout<<result[i];
	}
}