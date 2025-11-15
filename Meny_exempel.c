#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void visaBokstäver(char arr[], int antal);
void sorteraBokstäver(char arr[], int antal);
void antalVokaler(char arr[], int antal);
void slumpaNyaBokstäver(char arr[], int antal);

int main()
{
    srand(time(NULL));
    char bokstäver[10];
    int antal=10;
    int val;
    for (int i = 0; i < antal; i++)
    {
        bokstäver[i]= 'a' + rand() % 26;
        
    }
    
    printf("(1) Visa bokstäver\n(2) Sortera bokstäver\n(3) Räkna antalet vokaler\n(4) Slumpa nya bokstäver\n(5) Avsluta\n");
    while(1)
    {
        printf("Val: ");
        scanf(" %d",&val);
        switch (val)
        {
        case 1:
            visaBokstäver(bokstäver,antal);
            break;
        case 2:
            sorteraBokstäver(bokstäver,antal);
            visaBokstäver(bokstäver,antal);
            break;
        case 3:
            antalVokaler(bokstäver,antal);
            break;
        case 4:
            slumpaNyaBokstäver(bokstäver,antal);
            visaBokstäver(bokstäver,antal);
            break;
        case 5:
            return 0;
        default:
            printf("Ange endast 1-5\n");
            break;
        }
    }
    return 0;
}
void visaBokstäver(char arr[], int antal)
{
    for (int i = 0; i < antal; i++)
    {
        printf("%c ",arr[i]);
    }
    printf("\n");
}
void sorteraBokstäver(char arr[], int antal)
{
    for (int i = 0; i < antal - 1; i++)
    {
        for (int j = 0; j < antal - i - 1 ; j++)
        {
            if (arr[j] > arr[j+1])
            {
                char temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    printf("Sorterade bokstäver: ");
}
void antalVokaler(char arr[], int antal)
{
   int antal_vokaler = 0; 
    for (int i = 0; i < antal; i++)
    {
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u' || arr[i] == 'y')
        {
            antal_vokaler++;
        }
    }
    printf("Antal vokaler: %d\n",antal_vokaler);
}
void slumpaNyaBokstäver(char arr[], int antal)
{
    for (int i = 0; i < antal; i++)
    {
        arr[i]= 'a' + rand() % 26;
    }
    printf("Nya bokstäver: ");
}