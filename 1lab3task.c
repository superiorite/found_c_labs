/*
На вход программе, через аргументы командной строки, подается флаг
и путь к файлу. Флаг определяет действие с входным файлом. Флаг
начинается с символа “-” или “/”. Если флаг содержит символ “n” (то
есть nd, ni, ns, na), то результат сохраняется в файл, имя которого
является третьим аргументом. Если этого аргумента нет, то имя
выходного файла генерируется приписыванием к имени входного файла
префикса “out_”. Программа распознает следующие флаги:
i) -d необходимо исключить символы цифр из файла;
ii) -i необходимо в выходной файл написать, сколько раз в каждой
строке встречаются символы букв;
iii)-s необходимо в выходной файл написать, сколько раз в каждой
строке встречаются символы, отличные от символов цифр, символов
букв и символа пробела;
iv) -a необходимо заменить символы, отличные от цифр, их строковым
представлением ASCII-кода;
v) -f создать выходной файл таким образом, чтобы в каждой 
второй лексеме все буквы были переписаны в строчные, а также в
каждой пятой лексеме все символы были заменены на
эквивалентные им ASCII-коды.
*/
/*Кондратюк Владислав М8О-211Б-21*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



void deleteNum(FILE* fileIn, FILE* fileOut); // Функция удаления цифр
void countLetter(FILE* fileIn, FILE* fileOut); // Функция подсчета символов букв в строке 
void countNoLetterNumbersSpace(FILE* fileIn, FILE* fileOut); // Функция подсчета символов, отличных от букв, цифр, пробела
void asciiCodeNoNumbers(FILE* fileIn, FILE* fileOut); // Функция замены символов, отличных от цифр, их ASCII кодами
void charToLowerToAscii(FILE* fileIn, FILE* fileOut); // Функция замены второй лексемы в строчную, пятой лексемы в ASCII код

	
int main(int argc, char* argv[]) 
{
    FILE* fileIn = NULL;
    FILE* fileOut = NULL;
    int arglen = strlen(argv[1]);
    if (argc < 3 || arglen > 3)
    {
        puts("Incorrect input");
        exit(0);
    }
    if (argv[1][1] == 'n')
    {
        if (argc != 4)
        {
            puts("Wrong number of arguments");
            exit(0);
        }
        fileIn = fopen(argv[2], "r");
        fileOut = fopen(argv[3], "w");
        if ((fileIn == NULL) || (fileOut == NULL))
        {
            puts("Incorrect files");
            exit(0);
        }
        if (!strcmp(argv[1], "-nd") || (!strcmp(argv[1], "/nd"))) deleteNum(fileIn, fileOut);
        else if (!strcmp(argv[1], "-ni") || (!strcmp(argv[1], "/ni"))) countLetter(fileIn, fileOut);
        else if (!strcmp(argv[1], "-ns") || (!strcmp(argv[1], "/ns"))) countNoLetterNumbersSpace(fileIn, fileOut);
        else if (!strcmp(argv[1], "-na") || (!strcmp(argv[1], "/na"))) asciiCodeNoNumbers(fileIn, fileOut);
        else if (!strcmp(argv[1], "-na") || (!strcmp(argv[1], "/na"))) charToLowerToAscii(fileIn, fileOut);
        else puts("Wrong argument's input");

    }
    else
    {
        char* out = "out_";
        char* st = calloc(5 + strlen(argv[2]), 1);
        if (!st)
        {
            printf("Error: can't allocate memory");
            exit(1);
        }
        strcat(st, out);
        strcat(st, argv[2]);
        fileIn = fopen(argv[2], "r");
        fileOut = fopen(st, "w");
        if ((fileIn == NULL) || (fileOut == NULL))
        {
            puts("Incorrect files");
            exit(0);
        }
        if (!strcmp(argv[1], "-d") || (!strcmp(argv[1], "/d"))) deleteNum(fileIn, fileOut);
        else if (!strcmp(argv[1], "-i") || (!strcmp(argv[1], "/i"))) countLetter(fileIn, fileOut);
        else if (!strcmp(argv[1], "-s") || (!strcmp(argv[1], "/s"))) countNoLetterNumbersSpace(fileIn, fileOut);
        else if (!strcmp(argv[1], "-a") || (!strcmp(argv[1], "/a"))) asciiCodeNoNumbers(fileIn, fileOut);
        else if (!strcmp(argv[1], "-a") || (!strcmp(argv[1], "/a"))) charToLowerToAscii(fileIn, fileOut);
        else puts("Wrong argument's input");
        free(st);
    }

    fclose(fileIn);
    fclose(fileOut);

    return 0;
}

// Функция удаления цифр
void deleteNum(FILE* fileIn, FILE* fileOut) 
{
    int  ch;
    while ((ch = fgetc(fileIn)) != EOF) // Проверка на конец файла
    {
        if (!isdigit(ch)) fputc(ch, fileOut); // Если символ не число => записываем в выходной файл
    }
}

// Функция подсчета символов букв в строке
void countLetter(FILE* fileIn, FILE* fileOut)
{
    int ch;
    int count = 0;
    while ((ch = fgetc(fileIn)) != EOF) // Проверка на конец файла
    {
        if (ch != '\n' && isalpha(ch)) count++; // Является ли символ буквой, если да то увеличиваем счетчик
        else if (ch == '\n')
        {
            fprintf(fileOut, "%d\n", count); // Если строка закончилась, выводим кол-во букв и обнуляем счетчик
            count = 0;
        }
    }
}

// Функция подсчета символов, отличных от букв, цифр, пробела
void countNoLetterNumbersSpace(FILE* fileIn, FILE* fileOut)
{
    int ch;
    int count = 0;
    while ((ch = fgetc(fileIn)) != EOF) // Проверка на конец файла
    {
        if (ch != '\n' && !isalpha(ch) && !isdigit(ch) && ch != ' ') count++; // Если символ нам подходит, увеличиваем счетчик
        else if (ch == '\n')
        {
            fprintf(fileOut, "%d\n", count); // Если конец строки, записываем в выходной файл значение счетчика и обнуляем его
            count = 0;
        }
    }
}

// Функция замены символов, отличных от цифр, их ASCII кодами
void asciiCodeNoNumbers(FILE* fileIn, FILE* fileOut)
{
    int ch;
    while ((ch = fgetc(fileIn)) != EOF) // Проверка на конец файла
    {
        if (!isdigit(ch)) fprintf(fileOut, "%d", (int)ch); // Если символ цифра, записываем цифру в файл
        else fputc(ch, fileOut); // Иначе записываем ASCII код в файл
    }
}

// Функция замены второй лексемы в строчную, пятой лексемы в ASCII код
void charToLowerToAscii(FILE* fileIn, FILE* fileOut) 
{
    int ch;
    int count = 0;
    while ((ch = fgetc(fileIn)) != EOF) {
        if (ch == '\n' || ch == ' ') {
            fputc(ch, fileOut);
            count++;
        }
        else if (count % 10 == 0) {
            fputc(floor(ch), fileOut);
        }
        else if (count % 5 == 0) {
            fputc(ch, fileOut);
        }
        else if (count & 1 == 0) {
            fputc(floor(ch), fileOut);
        }
        else {
            fputc(ch, fileOut);
        }
    }
}
