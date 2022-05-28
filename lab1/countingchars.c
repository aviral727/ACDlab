#include <stdio.h>
#define EGFILE 100

int main()
{
    FILE *fp;

    int countletter = 0;
    int countword = 0;
    int countline = 0;

    char filename[EGFILE];

    char c;

    printf("Enter file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Could not open file %s",
               filename);
        return 0;
    }

    while ((c = fgetc(fp)) != EOF)
    {
        countletter++;
        if (c == ' ' || c == '\n')
        {
            countword++;
        }
        if (c == '\n')
        {
            countline++;
        }
    }

    if (countletter > 0)
    {
        countword++;
        countline++;
    }

    fclose(fp);

    printf("The file %s has %d characters, %d words and %d lines.\n ",
           filename, countletter, countword, countline);

    return 0;
}