#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int nextNumbers(int a, int b, int* ar2);
int checkNumber(int a, int* ar2);
int ar1[] = { 5,132,7,48,12,123, -1111, 1, 2, 3, 98, 90, 99, 3276};
int ar2[] = { 234,1,75,432,3,466,67};
int n = sizeof(ar2) / sizeof(*ar2);

int main()
{
    int* p = NULL;
    int result;
    p = (int*)malloc(sizeof(ar1));
    if (p == NULL)
        return 0;
    for (int i = 0; i < sizeof(ar1) / sizeof(*ar1); ++i)
    {
        int current = ar1[i];
        p[i] = ar1[i] + checkNumber(ar1[i], ar2);
    }
    for (int i = 0; i < sizeof(ar1) / sizeof(*ar1); ++i) printf("%d \n", *(p + i));

    free(p);
    return 0;
}

int checkNumber(int a, int* ar2)
{
    for (int i = 0; i < n; ++i) {
        if (a == *(ar2 + i)) {
            return a;
        }
    }
    return nextNumbers(a + 1, a - 1, ar2);
}
int nextNumbers(int a, int b, int* ar2)
{
    for (int i = 0; i < n; ++i) {
        if (a == *(ar2 + i)) {
            return a;
        }
        if (b == *(ar2 + i)) {
            return b;
        }
    }
    return nextNumbers(a + 1, b - 1, ar2);
}
