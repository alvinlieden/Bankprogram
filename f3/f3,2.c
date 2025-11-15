#include <stdio.h>

int main()
{
    int n;
    for (n=1;n<=32;n*=2) 
    {
        printf("%d",n);
        
        if (n<32) 
        {
            printf(", ");
        }
    }

}