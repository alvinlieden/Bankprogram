#include <stdio.h>

int main()
{
    int bredd,höjd;
    printf("Ange bredd och höjd (udda tal mellan 3 och 33): ");
    scanf("%d %d",&bredd,&höjd);
    while (bredd % 2 == 0 || höjd % 2 == 0 || bredd < 3 || höjd < 3 || bredd > 33 || höjd > 33)
    {
        printf("Felaktig indata.\n");
        printf("Ange bredd och höjd (udda tal mellan 3 och 33): ");
        scanf("%d %d",&bredd,&höjd);
    }
    for (int rad = 0; rad < höjd; rad++)
    {
       printf("*");
        for (int kol = 0; kol < bredd; kol++)
        {
            if (rad==0)
            {
                printf("*");
            }
            else if (rad == höjd-1)
            {
                printf("*");
            }
            else if (rad == höjd/2)
            {
                printf("*");
            }
            else if (kol == bredd/2)
            {
                printf("*");
            }
            
            else
            {
                printf(" ");
            }
        }
        printf("*");
        printf("\n");
    }
    
    
    
    
    
    return 0;
}