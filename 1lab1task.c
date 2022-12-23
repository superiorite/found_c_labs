#include <conio.h>
#include <stdio.h>
#include "string.h"
#include "math.h"
#include "limits.h"
#include "stdlib.h"

void MultiplesOf(int digit);
void JustANumber(int digit);
void IndividualDigits(int digit);
void Powers(unsigned int digit);
void SumOfNumbers(int digit);
long int Factorial(long int digit);

void main(int argc, char** argv) {
	if (argc != 3) {
		printf("You must enter a number and a flag!");
		exit(0);	
	}
	int number = PositiveNumber(argv[1]);
	if ((!strcmp(argv[2], "-h") || !strcmp(argv[2], "/h")))
		if (number > 100)
		{
			puts("Enter different number, which is lower than 100");
			exit(0);
		}
		else if (number == 0)
		{
			puts("Division by 0 is not allowed");
			exit(0);
		}
		else MultiplesOf(number);
	else if (!strcmp(argv[2], "-p") || !strcmp(argv[2], "/p"))
		JustANumber(number);
	else if (!strcmp(argv[2], "-s") || !strcmp(argv[2], "/s"))
		IndividualDigits(number);
	else if ((!strcmp(argv[2], "-e") || !strcmp(argv[2], "/e")) && (number <= 10))
		if (number > 10)
		{
			puts("Enter different number, which is lower than 10");
			exit(0);
		}
		else Powers(number);
	else if (!strcmp(argv[2], "-a") || !strcmp(argv[2], "/a"))
		SumOfNumbers(number);
	else if (!strcmp(argv[2], "-f") || !strcmp(argv[2], "/f"))
		printf("%li\n", Factorial(number));
	else puts("Incorrect flag");
}

int PositiveNumber(char* s) {
	int n = 0;
	int current = atoi(s);
	if (current == 0) return n;
	if (current < 0) {
		puts("It is negative number\n");
		exit(0);
	}
	for (int i = 0; s[i] != '\0'; i++) {
		if (n > UINT_MAX / 10) {
			puts("Overflow error, try lower number\n");
			exit(0);
		}
		if (s[i] - '0' < 0 || s[i] - '9' > 9) {
			puts("Not a number\n");
			exit(0);
		}
		n = n * 10 + (s[i] - '0');
	}
	if (n == 0) {
		puts("It is negative number\n");
		exit(0);
	}
	return n;
}

void MultiplesOf(int digit)
{
	int flag = 0;
	for (int i = 0; i <= 100; ++i)
	{
		if ((i % digit) == 0)
		{
			printf("%d\n", i);
			flag = 1;
		}
	}
	if (flag == 0) puts("Matching numbers not found");
}

void JustANumber(int digit)
{
	int flag = 0;
	if (digit == 1) puts("The number 1 is neither a prime nor a composite number");
	else if (digit > 1)
	{
		for (int i = 2; i < sqrt(digit); i++)
			if (digit % i == 0)
			{
				puts("Composite number");
				flag = 1;
				break;
			}
		if (flag == 0) puts("Simple number");
	}
}

void IndividualDigits(int digit)
{
	int k, i, m;
	int* arr;

	k = digit;
	m = 0;

	while (k != 0)      
	{
		k = k / 10;
		m++;
	}

	arr = (int*)malloc(m * sizeof(int));

	for (i = 0; i < m; i++)
	{
		arr[i] = digit % 10;      
		digit = digit / 10;       
	}

	for (i = m - 1; i >= 0; i--)
		printf("%d  ", arr[i]);

	printf("\n");
}

void Powers(unsigned int digit) {
	unsigned int tmp;
	for (int i = 1; i < 11; i++) {
		tmp = 1;
		for (int j = 0; j < digit; j++) {
			if (i > 8 && j > 8) {
				printf("%llu ", (unsigned long long) (tmp *= (i)));
			}
			else {
				printf("%d ", tmp *= (i));
			}
		}
		printf("\n");
	}
}

void SumOfNumbers(int digit)
{
	if (digit > (UINT_MAX * 2) / digit - 1) {
		printf("Overflow error!\n");
		exit(0);
	}
	printf("%d\n", (digit*(digit+1))/2);
}

long int Factorial(long int digit)
{
	if (digit == 0 || digit == 1) return 1;
	return digit * Factorial(digit - 1);
}
