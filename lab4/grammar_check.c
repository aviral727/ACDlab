#include <stdio.h>
#include <string.h>
int main()
{
    int n, first = 1;
    int final = 3;
    static int ll = 0, rl = 0;
    char delta_element;
    printf("Enter number of strings: ");
    scanf("%d", &n);
    for (int k = 0; k < n; k++)
    {
        char str[20];
        int i = 0, flag = 0;
        char delim[] = "=";
        char c;
        int type = -1;
        printf("Enter the string(s): ");
        scanf("%s", str);
        printf("%s\n", str);
        char *lhs = strtok(str, delim);
        printf("lhs='%s'\n", lhs);
        char *rhs = strtok(NULL, delim);
        printf("rhs='%s'\n", rhs);
        int lhs_size = strlen(lhs);
        int rhs_size = strlen(rhs);
        printf("%d,%d\n", lhs_size, rhs_size);
        while (1)
        {
            for (i = 0; i < strlen(lhs); i++)
            {
                c = lhs[i];
                if (isupper(c))
                {
                    flag++;
                }
            }
            if (flag >= 1)
            {
                printf("Type 0\n");
                type++;
                break;
            }
        }
        if (lhs_size <= rhs_size && type > -1)
        {
            if (rhs[0] == '0')
            {
                delta_element = lhs[0];
            }
            int type1 = 1;
            if (!first)
            {
                for (int j = 0; j < rhs_size; j++)
                {
                    if (rhs[j] == delta_element)
                    {
                        type1 = 0;
                        break;
                    }
                }
            }
            first = 0;
            if (type1)
            {
                printf("Type 1\n");
                type++;
            }
        }

        if (lhs_size == 1 && type > 0)
        {
            printf("Type 2\n");
            type++;
        }

        if (isupper(rhs[0]) && type > 1 && rl == 0)
        {
            flag = 0;
            for (i = 1; i < strlen(rhs); i++)
            {
                c = rhs[i];
                if (isupper(c))
                {
                    flag++;
                }
            }
            if (flag == 0)
            {
                printf("Type 3\n");
                ll = 1;
                type++;
            }
        }
        else if (isupper(rhs[strlen(rhs) - 1]) && type > 1 && ll == 0)
        {
            flag = 0;
            for (i = 0; i < strlen(rhs) - 1; i++)
            {
                c = rhs[i];
                if (isupper(c))
                {
                    flag++;
                }
            }
            if (flag == 0)
            {
                printf("Type 3\n");
                rl = 1;
                type++;
            }
        }
        else if (type > 1)
        {
            while (1)
            {
                flag = 0;
                for (i = 0; i < strlen(rhs); i++)
                {
                    c = rhs[i];
                    if (isupper(c))
                    {
                        flag++;
                    }
                }
                if (flag == 0)
                {
                    printf("Type 3\n");
                    type++;
                    break;
                }
                break;
            }
        }
        if (rhs[0] == '0' && type == 3)
            type--;
        printf("The grammar is of the type: %d \n", type);
        if (final > type)
        {
            final = type;
        }
    }
    printf("The language is of the type : %d", final);
}
