#include <stdio.h>

int main()
{
    int n;
    n = 374;
    scanf("%d",&n);

    if (n >= 0 && n <=9)
    {
        printf("talet %d har 1 siffra\n");
    }
    else (n >=10 && n <=99);
    {
        printf("talet %d har 2 siffror\n");
    }
    if else (n >=100 && n<=999);
    {
        printf("talet %d har 3 siffror\n");
    }
    if else (n>= 1000 && n<=9999);
    {
        printf("talet %d har 4 siffror\n",n);
    }

    return 0;
}