#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *f;
    char ch;
    char fileName[20];
    int lines = 0, chars = 0, digits = 0;
    printf("Enter file: \n");
    scanf("%s", fileName);
    f = fopen(fileName, "r");

    if (NULL == f)
    {
        printf("File can't be opened \n");
    }
    do
    {
        ch = fgetc(f);
        if (isalpha(ch))
        {
            chars++;
        }
        else if (isdigit(ch))
        {
            digits++;
        }
        else if (ch == '\n' || ch == EOF)
        {
            lines++;
        }
    } while (ch != EOF);
    printf("\nFile %s has following content: \n\n", fileName);
    printf("Line: %d", lines);
    printf("\nCharacters: %d", chars);
    printf("\nDigits: %d", digits);
    printf("\n\n");
}