#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printA(int v[], int n);
void fillArray(int v[], int n);
void sortArray(int v[], int n);

int main()
{
    int a[5];
    srand(time(NULL));
    fillArray(a, 5);
    printA(a,5);
    sortArray(a,5);
    printf("Sorterad array:\n");
    printA(a ,5);
    return 0;
}

void printA(int v[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",v[i]);
        
    }
        printf("\n");
    
}
void fillArray(int v[], int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        v[i]= (rand()%21-10);
    }
}
void sortArray(int v[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-1-i; j++)
        {
            if (v[j] > v[j+1])
            {
                int temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
            
        }   
    
    }
}
