#include <stdio.h>

int main()
{
    int i=1;
    while (i<=32)
    {
    printf("%d" , i);
    
    if (i<32)
    {
        printf(", ");
    }
    i*=2;
}

    return 0;
}