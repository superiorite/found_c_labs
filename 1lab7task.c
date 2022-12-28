/*
Заполнить массив фиксированного размера случайными числами.
Реализовать поиск максимального и минимального элементов,
поменять местами максимальный и минимальный элементы массива.
*/
/*Кондратюк Владислав М8О-211Б-21*/

#include <stdio.h>

int searchMax(int array[]); // Поиск максимума в массиве
int searchMin(int array[]); // Поиск минимума в массиве
void replaceMaxMin(int array[]); // Меняем места минимума и максимума в массиве

int main()
{
	int array[10] = { 0 };
	for (int i = 0; i < 10; i++) array[i] = rand() % 100; // Заполнение массива случайными числами
	for (int i = 0; i < 10; i++) printf("%d\t", array[i]);
	puts("\nMaximum in array: ");
	printf("%d", searchMax(array));
	puts("\nMinimum in array: ");
	printf("%d\n", searchMin(array));
	replaceMaxMin(array);
	for (int i = 0; i < 10; i++) printf("%d\t", array[i]);
	return 0;
}

int searchMax(int array[])
{
	int m = array[0];
	for (int i = 1; i < 10; i++)
	{
		if (m < array[i]) m = array[i];
	}
	return m;
}

int searchMin(int array[])
{
	int m = array[0];
	for (int i = 1; i < 10; i++)
	{
		if (m > array[i]) m = array[i];
	}
	return m;
}

void replaceMaxMin(int array[])
{
	int minimum = searchMin(array);
	int maximum = searchMax(array);
	int imax = 0;
	int imin = 0;
	for (int i = 1; i < 10; i++)
	{
		if (array[i] == maximum) imax = i;
		if (array[i] == minimum) imin = i;
	}
	array[imax] = minimum;
	array[imin] = maximum;
}
