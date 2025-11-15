#include <stdio.h>

typedef struct
{
    int kontoNr;
    char fornamn[16];
    char efternamn[16];
    char losenord[7];
    double saldo; 
} Konto;
void filInläsning(char *filnamn, Konto konton[], int *antalKonton);

int main()
{
    Konto konton[200];
    int antalKonton;
    char filnamn[100];
    printf("Ange filnamn (.txt) att läsa in: ");
    scanf("%99s", filnamn);
    
    filInläsning(filnamn, konton, &antalKonton);
    
    printf("Antal konton i programmet: %d\n", antalKonton);
return 0;
}

void filInläsning(char *filnamn, Konto konton[], int *antalKonton)
{
    FILE *fil =fopen(filnamn, "r");
    if (fil==NULL)
    {
        printf("Ingen fil hittades. Skapar en ny fil\n");
        fil=fopen(filnamn,"w");
        fclose(fil);
        *antalKonton=0;
    }
    else
    {
        printf("Laddar data från filen...\n");
        int i=0;
        while(i<200 && fscanf(fil,"%d %15s %15s %6s %lf",&konton[i].kontoNr,konton[i].fornamn,konton[i].efternamn,konton[i].losenord,&konton[i].saldo)==5)
        {
            i++;
        }
        *antalKonton =i;
        fclose(fil);
    }
    
    return;
}

