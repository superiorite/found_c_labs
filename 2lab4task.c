#include <stdio.h>
#include <stdarg.h>
#include <math.h>

double geometricMean(double n, ...);
float integerDegree(float a, int b);


int main()
{
    printf("%f \n", geometricMean(4, 2.1, 5.11, 10.7, 5.7));
    printf("%f \n", integerDegree(5, 2));
    return 0;
}

//NAN isnan()
double geometricMean(double n, ...)
{
    double result = 1;
    va_list factor;
    va_start(factor, n);
    for(int i=0;i<n; i++)
    {

        result *= va_arg(factor, double);
    }
    va_end(factor);
    return pow(result, (1./n));
}

float integerDegree(float a, int b)
{
    if (b > 0)  return a*integerDegree(a, b-1);
    if (b < 0)  return 1.0 / integerDegree(a, -b);
    return 1;
}
