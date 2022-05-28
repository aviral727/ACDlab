#include <stdio.h>
#define EGFILE 100

int main()
{
    FILE *fp;

    int countvowel = 0;
    int countcons = 0;

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

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            countvowel++;
        }
        else
        {
            countcons++;
        }
    }

    // if (countletter > 0)
    // {
    //     countword++;
    //     countline++;
    // }

    // Close the file
    fclose(fp);

    printf("The file %s has %d vowels and %d consonants.\n ",
           filename, countvowel, countcons);

    return 0;
}