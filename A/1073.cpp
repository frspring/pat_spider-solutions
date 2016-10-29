
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
 
using namespace std;
int main()
{
    char in[9999];
    int i, j = 1;
    int before, after;
    scanf("%s", in);
    if (in[0] == '-')
        putchar('-');
    for (i = 0; in[i] != 'E'; i++)
    {
    }
    after = atoi(in + i + 1);
    if (after < 0)
    {
        after++;
        after++;
        printf("0");
        printf(".");
        while (after<=0)
        {
            printf("0");
            after++;
        }
        while (j<i)
        {
            if(in[j]!='.')
                putchar(in[j]);
            j++;
        }
    }
    else
    {
        after++;
        while (after>=0)
        {
            if (in[j] != '.'&&j < i)
                putchar(in[j]);
            else if(j>=i)
            {
                putchar('0');
            }
            j++;
            after--;
        }
        if (j < i)
            putchar('.');
        while (j<i)
        {
            putchar(in[j++]);
        }
    }
 
    getchar();
    getchar();
    return 0;
}