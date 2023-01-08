#include <stdio.h>
int ThreeProd(int* a, int* b, int* c){
	int ans;
	_asm {
		mov eax, a;
		mov edx, 0;
		mul b;
		mul c;
		mov ans, eax;
	}
	return ans;
}
int main()
{
	//define variables
	int a, b, c;
	printf("Enter Number 1: ");
	scanf_s("%d", &a);
	printf("Enter Number 2: ");
	scanf_s("%d", &b);
	printf("Enter Number 3: ");
	scanf_s("%d", &c);
	// in scanf_s it is necessary to
	//specifiy length
	int result = ThreeProd(&a, &b, &c);
	printf("Product is %d", result);
	return 0;
}