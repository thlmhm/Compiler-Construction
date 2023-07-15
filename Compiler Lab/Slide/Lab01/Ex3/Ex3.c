#include <stdio.h>
#include "charcode.h"
#include "charcode.c"
int main()
{
    extern CharCode charCodes[];
    int lines = 0, letters = 0, digits = 0;
    FILE *f;
    char c;
    printf("Enter name of file to read: ");
    char fileName[50];
    scanf("%s", fileName);
    f = fopen(fileName, "r");
    if (f == NULL)
        printf("Cannot open file!");
    do
    {
        c = fgetc(f);
        if (charCodes[c] == CHAR_LETTER)
        {
            letters++;
        }
        else if (charCodes[c] == CHAR_DIGIT)
        {
            digits++;
        }
        else if (c == '\n' || c == EOF)
        {
            lines++;
        }
    } while (c != EOF);

    printf("Number of line: %d \n", lines);
    printf("Number of letter: %d \n", letters);
    printf("Number of digit: %d \n", digits);
    fclose(f);
    return 0;
}