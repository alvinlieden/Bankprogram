#include <stdio.h>

int main()
{
    int tal[5]={10,42,35,90,2};
    int n=5;
    for (int i = 0; i < n - 1 ; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (tal[j] > tal[j+1])
            {
                int temp = tal[j];
                tal[j] = tal[j+1];
                tal[j+1] = temp;
            }            
        }
    }
    printf("Sorterade: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", tal[i]);
    }
    return 0;
    
    
}