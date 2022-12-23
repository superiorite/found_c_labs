#include <stdio.h>
#include <math.h>
#include <string.h>

#define EPS 1e-7

float InputValidation(char* s);
int Multiplicity(int a, int b);
int RightTriangle(int a, int b, int c);
double QuadraticEquation(float a, float b, float c);
double FindX(double b, double a, double d);

void main(int argc, char** argv) {

    if ((!strcmp(argv[1], "-q") || !strcmp(argv[1], "/q"))) {
        if (argc != 5) {
            printf("You must enter a three numbers and a flag!");
            exit(0);
        }
        QuadraticEquation(InputValidation(argv[2]), InputValidation(argv[3]), InputValidation(argv[4]));
    }
    else if ((!strcmp(argv[1], "-m") || !strcmp(argv[1], "/m"))) {
        if (argc != 4) {
            printf("You must enter a two numbers and a flag!");
            exit(0);
        }
        int a = InputValidation(argv[2]);
        int b = InputValidation(argv[3]);
        if ((a == 0) || (b == 0)) {
            puts("Enter negative or positive numbers");
            exit(0);
        }
        int res = Multiplicity(a, b);
        res ? printf("%d is not multyply %d", a, b) : printf("Yes %d is a multiple of %d", a, b);
    }
    else if ((!strcmp(argv[1], "-t") || !strcmp(argv[1], "/t"))) {
        if (argc != 5) {
            printf("You must enter a three numbers and a flag!");
            exit(0);
        }
        int res = RightTriangle(InputValidation(argv[2]), InputValidation(argv[3]), InputValidation(argv[4]));
        res ? printf("Yes it can be a right triangle") : printf("No it cant be a right triangle");
    }
    else puts("Something went wrong, try again");
}


float InputValidation(char* s) {
    float res = 0;
    int afterdot = 0;
    float stepen = 1;
    int neg = 0;
    if (*s == '-') {
        s++;
        neg = 1;
    }
    while (*s) {
        if (afterdot) {
            stepen = stepen / 10;
            res = res + (*s - '0') * stepen;
        }
        else {
            if (*s == '.' || *s == ',')
                afterdot++;
            else
                res = res * 10.0 + (*s - '0');
        }
        s++;
    }
    if (neg) return -res;
    else    return  res;
}

double FindX(double b, double a, double d) {
    return (b + d) / (2 * a);
}

double QuadraticEquation(float a, float b, float c) {
    float arr[3] = { a, b, c };
    double disc = 0;
    for (int i = 0; i < 3; i++) {
        a = arr[i];
        b = arr[(i + 1) % 3];
        c = arr[(i + 2) % 3];
        disc = b * b - 4 * a * c;
        if (Checker(disc) && Checker(arr[i])) {
            disc = sqrt(disc);
            printf("The answer for %lf*x^2 + %lf*x + %lf = 0 is x1 = %lf, x2 = %lf\n", a, b, c, FindX(b, a, disc), FindX(b, a, -disc));
        }
        else {
            printf("The equation %lf*x^2 + %lf*x + %lf = 0 has no roots\n", a, b, c);
        }
        disc = c * c - 4 * a * b;
        if (Checker(disc) && arr[i] != 0) {
            disc = sqrt(disc);
            printf("The answer for %lf*x^2 + %lf*x + %lf = 0 is x1 = %lf, x2 = %lf\n", a, c, b, FindX(c, a, disc), FindX(c, a, -disc));
        }
        else {
            printf("The equation %lf*x^2 + %lf*x + %lf = 0 has no roots\n", a, c, b);
        }
    }
}

int Checker(double d) {
    if (d < EPS) {
        return 0;
    }
    return 1;
}

int Multiplicity(int a, int b) {
	if ((a % b) == 0) return 0;
	else return 1;
}

int RightTriangle(int a, int b, int c) {
	if (a * a == b * b + c * c || b * b == c * c + a * a || c * c == a * a + b * b) return 1;
	else return 0;
}
