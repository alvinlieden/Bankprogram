#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void fillArray(int arr[], int n);
void printArray(int arr[], int n);
float calculateAverage(int arr[], int n);
float calculateMedian(int arr[], int n);
float calculateType(int arr[], int n);

int main()
{
    srand(time(NULL));
    int amount;
    int ages[999];
    
    printf("Hur många personer vill du göra statistik på?");
    scanf("%d", &amount);
    while (amount<0 || amount>999)
    {
        printf("Endast 0-1000 är tillåtna värden");
        scanf("%d", &amount);
    }
    fillArray(ages, amount);
    printArray(ages, amount);
    float avg= calculateAverage(ages, amount);
    float med= calculateMedian(ages, amount);
    float typ= calculateType(ages, amount);
    printf("Medelvärde: %.1f\n", avg);
    printf("Median: %.1f\n", med);
    return 0;
}

void fillArray(int arr[], int n)
{
    for (int i = 0; i<n; i++)
    {
        arr[i]= rand()%21+20;
    }
    
}

void printArray(int arr[], int n)
{
    if (n<31)
        {
            for (int i = 0; i < n; i++)
            {
                printf("%d", arr[i]);
                if (i < n-1)
                {
                    printf(", ");
                }
                printf("\n");
            }
            
        }
    
}

float calculateAverage(int arr[], int n)
{
    float sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+= arr[i];
    }
    float avg=sum/n;
    return avg;
}

float calculateMedian(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j< n-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }       
            if (n%2!=0)
            {
                return (float)arr[n/2];
            }
            else
            return (arr[n/2-1]+arr[n/2])/2.0;
}

float calculateType(int arr[], int n)
{
    int count[21]={0};
    int maxCount=0;
    for (int i = 0; i < n; i++)
    {
        count[arr[i]-20]++;
    }
    
    for (int i = 0; i < 21; i++)
    {
        if (count[i]>maxCount)
        {
            maxCount=count[i];
            
        }
        
    }
    printf("Typvärde: ");
    for (int i = 0; i < 21; i++)
    {
        if (count[i]==maxCount)
        {
            printf("%d, ", i+20);
            
        }
        
    }
    for (int i = 0; i < 21; i++)
    {
        if (count[i]==maxCount)
        {
            return i+20;
        }
    }
}
