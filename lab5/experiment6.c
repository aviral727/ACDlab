#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validate(char str[87])
{
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] != '0' && str[i] != '1')
            break;
    }
    return i == strlen(str);
}

int main()
{
    int i, state = 0;
    char str[87];

    printf("Enter a binary string: \n");
    gets(str);

    if (!validate(str))
    {
        printf("Invalid Input");
        exit(1);
    }

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '1')
        {
            if (str[i + 1] == '1')
            {
                if (str[i + 2] == '1')
                {
                    state = 1;
                    break;
                }
            }
        }
    }

    if (state == 1)
    {
        printf("ACCEPTED");
    }
    else
    {
        printf("REJECTED");
    }

    return 0;
}