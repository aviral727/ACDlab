#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char nt[87], t[87];

void append(char *s, char c)
{
    int len = strlen(s);
    s[len] = c;
    s[len + 1] = '\0';
}

int main()
{
    int i;
    char str[87];
    printf("Enter all production rules in the grammar separated by spaces: \n");
    gets(str);

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            if (strchr(t, str[i]) == NULL)
                append(t, str[i]);
        }
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            if (strchr(nt, str[i]) == NULL)
                append(nt, str[i]);
        }
    }

    printf("Terminals:  %s\n", t);
    printf("Non-Terminals:  %s\n", nt);

    return 0;
}