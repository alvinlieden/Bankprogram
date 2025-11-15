#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int enter(int arr[], int n, int counter);
void view(int arr[], int n);
void compute(int arr [], int n);
int getMax(int arr[], int n);
int getMin(int arr[], int n);
float getAvg(int arr[], int n);
void getNorm(int arr[], int n, float avr, int result[]);

int main()
{
    int counter=1;
    char userChoice;
    int measurements[10];
    int nrOfMeasurements=0;
    bool flag=true;
    printf("v(view) - visar vilka matvärden som finns lagrade\n"
           "e(Enter) - tillåter användaren att lägga till mätvärden\n"
           "c(Compute) - presenterar max, min, medelvärde och normaliserade mätvärden\n"
           "r(Reset) - raderar alla inmatade mätvärden\n"
           "q(Quit) - avslutar programmet\n"
           "Measurement tool 2.0\n");
    
    while (flag)
    {
        printf("VECRQ? ");
        scanf(" %c", &userChoice);
        switch(userChoice)
        {
            case 'v':
                view(measurements, nrOfMeasurements);
                break;
            case 'e':
                nrOfMeasurements=enter(measurements, nrOfMeasurements, counter);
                counter=nrOfMeasurements+1;
                break;
            case 'c':
                compute(measurements, nrOfMeasurements);
                break;
            case 'r':
                nrOfMeasurements=0;
                printf("Removed all measurements\n");
                counter=1;
                break;
            case 'q':
                printf("Exit Measurement tool\n");
                flag=false;
                break;
            default:
                printf("Inkorrekt val, försök igen\n");
        }

    }
    return 0;
}

int enter(int arr[], int n, int counter)
{
    while(n<10)
    {
        printf("Enter measurement #%d (or q to quit) : ",counter);
        int read=scanf("%d",&arr[n]);
        if (read==1)
        {
            n++;
            counter++;
        }
        else
        {
            char tmp;
            scanf(" %c", &tmp);
            if (tmp !='q') 
            { 
                printf("felaktig inmatning, 'q' för att avsluta\n");
            }
            return n;
        }
    }
    return n;
}

void view(int arr[], int n)
{
    if (n==0)
    {
        printf("No measurements\n");
        return;
    }
    else
    {
        printf("[ ");
        for (int i = 0; i<n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("]\n");
    }
}

void compute(int arr[], int n)
{
    if (n==0)
    {
        printf("No measurements\n");
        return;
    }
        int max=getMax(arr, n);
        int min=getMin(arr, n);
        float avr=getAvg(arr, n);
    
    
        printf("Max value: %d\n", max);
        printf("Min value: %d\n", min);
        printf("Avr value: %.2f\n", avr);
        
        int normalized[10];
        getNorm(arr, n, avr, normalized);
        
        printf("Normalized: [ ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", normalized[i]);
        }
        
        printf("]\n");
}
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i=1;i<n;i++)
    {
        if (arr[i] > max)
            {
                max=arr[i];
            }
    }
    return max;
}

int getMin(int arr[], int n)
{
    int min = arr[0];
    for (int i=1;i<n;i++)
    {
        if (arr[i] < min)
        {
            min=arr[i];
        }
    }
    return min;
}

float getAvg(int arr[], int n)
{
    int sum=0;
    for (int i=0;i<n;i++)
    {
        sum+= arr[i];
    }
    return (float)sum/n; 

}
void getNorm(int arr[], int n, float avr, int result[])
{
    for (int i = 0; i < n; i++)
        {
            result[i]=(int)round(arr[i]-avr);
        }
}
