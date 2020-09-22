#include <stdio.h>
#pragma warning (disable: 4996)

//typedef  unsigned  char  integer_t;
//typedef  unsigned  short  integer_t;
typedef  unsigned  int  integer_t;
//typedef  unsigned  long  integer_t;
//typedef  unsigned  long  long integer_t;
typedef unsigned long long MaxInt;

integer_t Process(integer_t Number) {
	integer_t ReverseNumber;
	ReverseNumber = ((Number & 0x5555555555555555) << 1) | ((Number >> 1) & 0x5555555555555555);
	ReverseNumber = ((ReverseNumber & 0x3333333333333333) << 2) | ((ReverseNumber >> 2) & 0x3333333333333333);
	ReverseNumber = ((ReverseNumber & 0x0F0F0F0F0F0F0F0F) << 4) | ((ReverseNumber >> 4) & 0x0F0F0F0F0F0F0F0F);
	return ReverseNumber;
}

int Length(integer_t Number, integer_t ReverseNumber) {
	int i = 0, j = 0;
	while (Number != 0) {
		Number = Number / 10;
		i++;
	}
	while (ReverseNumber != 0) {
		ReverseNumber = ReverseNumber / 10;
		j++;
	}
	if (i < j)
		i = j;
	return i;
}

void BinTran(integer_t Number)
{
	int i;
	MaxInt a = 1;
	for (i = sizeof(Number) * 8 - 1; i >= 0; i--) {
		a = 1;
		if (Number & (a << i))printf("1");
		else printf("0");
		if (i % 8 == 0)
			printf(" ");
	}

}

int main(void) {
	MaxInt Number, ReverseNumber;
	int length;
	do {
		printf("Input number:  ");
		scanf("%llu", &Number);
		ReverseNumber = Process((integer_t)Number);
		length = Length((integer_t)Number, ReverseNumber);
		printf("Your input:    %*llu =  0x%0*llX = ", length, (MaxInt)Number, sizeof(Number) * 2, (MaxInt)Number);
		BinTran((integer_t)Number);
		printf("\n");
		printf("New number:    %*llu =  0x%0*llX = ", length, ReverseNumber, sizeof(ReverseNumber) * 2, (MaxInt)ReverseNumber);
		BinTran((integer_t)ReverseNumber);
		printf("\n\n");
	} while (Number != 0);
	return 0;
}