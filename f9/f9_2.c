#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArray(int arr[], int n);
void shuffleArray(int arr[], int n);
void printArray(int arr[], int n);

int main()
{
    srand(time(NULL));
    int n;
    printf("Vilket är det högsta heltal du vill ha med (1-1000)\n");
    scanf("%d", &n);
    while (n<1 || n>1000)
    {
        printf("Du måste välja mellan 1 och 1000!\n");
        scanf("%d", &n);
    }
    int numbers[n];
    fillArray(numbers, n);
    shuffleArray(numbers, n);
    printArray(numbers, n);
    return 0;
} 
void fillArray(int arr[], int n)
{
    for (int i=0;i<n;i++)
    {
        arr[i]=i+1;
    }
    
}
void shuffleArray(int arr[], int n)
{
    for (int i=n-1;i>0;i--)
    {
        int j=rand()%(i+1);
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}
void printArray(int arr[], int n)
{
    for (int i=0; i<n;i++)
    {
        printf("%d", arr[i]);
        if (i<n-1)
        {
            printf(", ");
        }   
    }
    printf("\n");
}

    

