#include <stdio.h>
#include <string.h>

typedef struct 
{
    char kontoNr[7];
    char fornamn[16];
    char efternamn[16];
    char losenord[7];
    double saldo; 
}Konto;

void filInläsning(char *filnamn, Konto konton[], int *antalKonton);
void adminMeny(Konto konton[], int *antalKonton, char *filnamn);
void användarMeny(Konto konton[], int *antalKonton, char *filnamn);
void registreraNyttKonto(Konto konton[], int *antalKonton);
void skrivaUtKonton(Konto konton[], int antalKonton);
void sorteraKonton(Konto konton[], int antalKonton);
void kontoSökande(Konto konton[], int antalKonton);
void avregKonto(Konto konton[], int *antalKonton);
void sparaTillFil(char *filnamn, Konto konton[], int antalKonton);

void utskriftEttKonto(Konto k);
int hittaRättKonto(Konto konton[], int antalKonton, char *kontoNr);
void kontoVal(Konto konton[], int index, char *filnamn, int *antalKonton);

int main()
{
    Konto konton[200];
    int antalKonton;
    char filnamn[100];

    printf("Ange filnamn (.txt) att läsa in: ");
    scanf("%99s", filnamn);
    filInläsning(filnamn, konton, &antalKonton);
    while (1)
    {
        int val=0;
        printf("(1)   Logga in som admin\n"
               "(2)   Logga in som användare\n"
               "(3)   Avsluta\n"
               "Ange val: ");
        scanf("%d", &val);
        switch (val)
        {
            case 1:
                adminMeny(konton, &antalKonton,filnamn);
                break;
            case 2:
                användarMeny(konton,&antalKonton,filnamn);
                break;
            case 3:
                printf("Avslutar...\n");
                return 0;
            default:
                printf("Ogiltigt val\n");
            break;
        }
    }
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
        while(i<200 && fscanf(fil,"%s %15s %15s %6s %lf",konton[i].kontoNr,konton[i].fornamn,konton[i].efternamn,konton[i].losenord,&konton[i].saldo)==5)
        {
            i++;
        }
        *antalKonton =i;
        fclose(fil);
    }
    
    return;
}
void utskriftEttKonto(Konto k)
{   
    char hela_namnet[35];
    sprintf(hela_namnet,"%s %s",k.fornamn,k.efternamn);
    printf("%-8s %-25s %8.0f\n",k.kontoNr,hela_namnet,k.saldo);
}
int hittaRättKonto(Konto konton[], int antalKonton, char *kontoNr)
{
    for (int i = 0; i < antalKonton; i++)
    {
        if (strcmp(konton[i].kontoNr, kontoNr) == 0)
        {
            return i;
        }
    }
    return -1;
}
void kontoVal(Konto konton[], int index, char *filnamn, int *antalKonton)
{
    int val;
    printf("(1) Skriv ut konto\n(2) Ändra lösenord\n(3) Ändra saldo\n(4) Huvudmeny\nAnge val: ");
    scanf("%d", &val);

    switch (val)
    {
    case 1:
        utskriftEttKonto(konton[index]);
        break;
    case 2:
        {
            char nytt_lösen[10];
            while (1)
            {
                printf("Ange ett nytt lösenord (6 tecken): ");
                scanf("%9s", nytt_lösen);
                if (strlen(nytt_lösen) == 6)
                {
                    strcpy(konton[index].losenord, nytt_lösen);
                    printf("Lösenordets bytet lyckades!\n");
                    break;
                }
                else
                printf("ERROR: Felaktigt antal tecken\n");
            }
            break;
        }
    case 3:
        {
            double belopp;
            int alternativ;
            printf("Ditt saldo: %.2f kr\nInsättning (1) eller uttag (2): ",konton[index].saldo);
            scanf("%d",&alternativ);
            if (alternativ == 1)
            {  
                printf("Ange belopp att sätta in: ");
                scanf("%lf", &belopp);
                konton[index].saldo += belopp;
            }
            else if (alternativ == 2)
            {
                printf("Ange belopp att ta ut");
                scanf("%lf", &belopp);
                if (belopp > konton[index].saldo)
                {
                    printf("ERROR: Du har otillräckligt saldo!\n");
                }
                else
                {
                    konton[index].saldo -= belopp;
                }
            }
            printf("Ditt nya saldo: %.2f kr\n", konton[index].saldo);
            break;
        }
    case 4:
        sparaTillFil(filnamn,konton,*antalKonton);
        return;
    default:
        break;
    }
}
void registreraNyttKonto(Konto konton[], int *antalKonton)
{
    char kontoNr[20];
    while (1)
    {
        if (*antalKonton >= 200)
        {
            printf("Kontoregistret är fullt\n");
            return;
        }
        else
        {
            printf("Ange kontonummer (q för att avsluta): ");
            scanf("%s", kontoNr);
        }
        if (strcmp(kontoNr, "q") == 0)
        {
            break;
        }
            if (strlen(kontoNr) !=6)
        {
            printf("Kontonumret skall vara 6 siffror\n");
            continue;
        }

        int sifferKontroll = 1;
        for (int i = 0; i < 6; i++)
        {
            if (kontoNr[i] < '0' || kontoNr[i] > '9')
            {
                sifferKontroll = 0;
                break;
            }
        }
        if (!sifferKontroll)
        {
            printf("Kontonumret får bara innehålla siffror\n");
            continue; 
        }

        if (hittaRättKonto(konton,*antalKonton,kontoNr) != -1)
        {
            printf("ERROR:Kontonumret finns redan\n");
            continue;
        }
                
        Konto nytt;
        strcpy(nytt.kontoNr, kontoNr);
        printf("Ange ägare: ");
        scanf("%15s %15s", nytt.fornamn, nytt.efternamn);    
        while (1) 
        {
            printf("Ange lösenord (6 tecken): ");
            scanf("%10s", nytt.losenord);
            if (strlen(nytt.losenord) != 6)
            {
                printf("Felaktigt antal tecken.\n");
            }
            else
            {
                break;
            }
        }    
        nytt.saldo = 0;
        konton[*antalKonton] = nytt;
        (*antalKonton)++;
        printf("Konto registrerat!\n");
    }
}
void skrivaUtKonton(Konto konton[], int antalKonton)
{
    if (antalKonton == 0)
    {
        printf("Inga konton finns registrerade.\n");
        return;
    }
    printf("%-8s %-25s %-8s\n","Konto-nr","Namn","Saldo(kr)");
    printf("_______________________________________________\n");
    for (int i = 0; i < antalKonton; i++)
    {
        utskriftEttKonto(konton[i]);
    }
    printf("\n");
}
void sorteraKonton(Konto konton[], int antalKonton)
{
    if (antalKonton < 2)
    {
        printf("För få konton för sortering.\n");
        return;
    }
    int val;
    printf("Vill du sortera efter konto-nr (1), namn (2) eller saldo(3): ");
    scanf("%d",&val);

    for (int i = 0; i < antalKonton - 1; i++)
    {
        for (int j = 0; j < antalKonton - i - 1; j++)
        {
            int byte = 0;
            switch (val)
            {
            case 1:
                if (strcmp(konton[j].kontoNr, konton[j + 1].kontoNr) > 0)
                {
                    byte = 1;
                }
                break;
            case 2:
                if (strcmp(konton[j].efternamn, konton[j + 1].efternamn) > 0)
                {
                    byte = 1;
                }
                break;
            case 3:
                if (konton[j].saldo > konton[j + 1].saldo)
                {
                    byte = 1;
                }
                break;
            default:
                break;
            }
            if (byte)
            {
                Konto temp = konton[j];
                konton[j] = konton[j + 1];
                konton[j + 1] = temp;
            }
        }
    }
}
void kontoSökande(Konto konton[], int antalKonton)
{
    int val=0;
    char sök_kontoNr[20];
    char sök_namn[20];
    double minsta_saldo, största_saldo;
    int konto_funnit;
    while (1) 
    {
        printf("(1) Konto-nr\n(2) Namn\n(3) Saldo\n(4) Admin-meny\nAnge val:");
        scanf("%d",&val);
        switch (val)
        {
        case 1:
            printf("Ange konto-nr:");
            scanf("%6s",sök_kontoNr);
            konto_funnit = 0;
            for (int i = 0; i < antalKonton; i++)
            {
                if (strcmp(konton[i].kontoNr,sök_kontoNr) == 0)
                {
                    utskriftEttKonto(konton[i]);
                    konto_funnit = 1;
                    break;
                }
            }
            if (!konto_funnit)
            {
                printf("Kontonummer saknas.\n");
            }
            break;
        case 2:
            printf("Ange söksträng:");
            scanf("%19s",sök_namn);
            konto_funnit = 0;
            for (int i = 0; i < antalKonton; i++)
            {
                if (strstr(konton[i].fornamn, sök_namn) != NULL || strstr(konton[i].efternamn, sök_namn) != NULL)
                {
                    printf("%9s %15s %15s %.0f\n",konton[i].kontoNr,konton[i].fornamn,konton[i].efternamn, konton[i].saldo);
                    konto_funnit = 1;
                }
            }
            if (!konto_funnit)
            {
                printf("ERROR: Inga konton matchar den söksträngen\n");
            }
            break;
        case 3:
            printf("Ange min: ");
            scanf("%lf",&minsta_saldo);
            printf("Ange max: ");
            scanf("%lf",&största_saldo);
            printf("\nKonto-nr  Namn            Saldo (kr)\n");
            printf("__________________________________________\n");
            konto_funnit = 0;
            for (int i = 0; i < antalKonton; i++)
            {
                if (konton[i].saldo >= minsta_saldo && konton[i].saldo <= största_saldo)
                {
                    printf("%9s %15s %15s %.0f\n",konton[i].kontoNr, konton[i].fornamn, konton[i].efternamn, konton[i].saldo);
                    konto_funnit = 1;
                }
            }
            if (!konto_funnit)
            {
                printf("ERROR: Inga konton funna inom det intervallet");
            }
            break;
        case 4:
            return;
        default:
            break;
        }
    } 
}
void sparaTillFil(char *filnamn, Konto konton[], int antalKonton)
{
    FILE *fil = fopen(filnamn, "w");
    if (!fil)
    {
        printf("ERROR: Filen kunde ej sparas!\n");
        return;
    }
    for (int i = 0; i < antalKonton; i++)
    {
        fprintf(fil,"%s %s %s %s %.2f\n", konton[i].kontoNr,konton[i].fornamn,konton[i].efternamn,konton[i].losenord,konton[i].saldo);
    }
    fclose(fil);
}
void avregKonto(Konto konton[], int *antalKonton)
{
    char input[20];
    char bekräftning[3];
    int konto_funnit = -1;
    int val;
    double minsta_saldo, största_saldo;
    while (1)
    {
        int antal_träffar = 0;
        int index = -1;
        printf("\nVälj sökalternativ:\n");
        printf("(1) Konto-nr\n(2) Namn\n(3) Saldo\n(4) Admin-meny\nAnge val: ");
        scanf("%d",&val);
        switch (val)
        {
        case 1:
            printf("Ange konto-nr:");
            scanf("%19s",input);
            index = hittaRättKonto(konton, *antalKonton, input);
            antal_träffar = (index != -1);
            break;
        case 2:
            printf("Ange söksträng:");
            scanf("%19s",input);
            for (int i = 0; i < *antalKonton; i++)
            {
                if (strstr(konton[i].fornamn, input) != NULL || strstr(konton[i].efternamn,input) != NULL)
                {
                    printf("%9s %15s %15s %.0f\n",konton[i].kontoNr,konton[i].fornamn,konton[i].efternamn,konton[i].saldo);

                    antal_träffar++;
                    index = i;
                }
            }
            break;
        case 3:
            printf("Ange min: ");
            scanf("%lf",&minsta_saldo);
            printf("Ange max: ");
            scanf("%lf",&största_saldo);

            for (int i = 0; i < *antalKonton; i++)
            {
                if (konton[i].saldo >= minsta_saldo && konton[i].saldo <= största_saldo)
                {
                    printf("%9s %15s %15s %.0f\n",konton[i].kontoNr,konton[i].fornamn,konton[i].efternamn,konton[i].saldo);
                    antal_träffar++;
                    index = i;
                }
            }
            break;
        case 4:
            return;
        default:
            continue;
        }
        if (antal_träffar != 1)
        {
            printf("Du fick inte exakt ett konto!\n");
            continue;
        }
        utskriftEttKonto(konton[index]);
        if (konton[index].saldo != 0)
        {
            printf("Det finns pengar på saldot, kan inte avregistrera kontot.\n");
            continue;
        }
        printf("Vill du avregistrera kontot= (j/n): ");
        scanf("%2s", bekräftning);
            
        if (strcmp(bekräftning, "j") != 0)
        {
            continue;
        }
        for (int i = index; i < *antalKonton - 1; i++)
        {
            konton[i] = konton[i + 1];
        }
        (*antalKonton)--;
        printf("Kontot avregistreras\n");
    }
}
void användarMeny(Konto konton[], int *antalKonton, char *filnamn)
{
    char kontoNr[10];
    char lösenord[10];
    int konto_funnit = -1;
    while (1) 
    {
        printf("Ange konto (6 siffror): ");
        scanf("%9s", kontoNr);
        if (strcmp(kontoNr, "q") == 0)
        {
            return;
        }
        if (strlen(kontoNr) != 6)
        {
            printf("ERROR: Endast 6 siffror!\n");
            continue;
        }
        int sifferKontroll = 1;
        konto_funnit = hittaRättKonto(konton, *antalKonton, kontoNr);
        if (konto_funnit == -1)
        {
            printf("ERROR: Kunde inte hitta konto\n");
            continue;
        }
        while (1) 
        {
            printf("Ange lösenord för konto %s: ",kontoNr);
            scanf("%9s", lösenord);
            if (strcmp(lösenord, "q") == 0)
            {
                return;
            }
            if (strcmp(konton[konto_funnit].losenord, lösenord) == 0)
            {
                break;
            }
            else
            {
                printf("Felaktigt lösenord.\n");
            }
        }
        kontoVal(konton,konto_funnit,filnamn,antalKonton);
    } 
}
void adminMeny(Konto konton[], int *antalKonton, char *filnamn)
{
    int val=0;
    int antal_försök=0;
    char angivet_lösen[10];
    while (antal_försök < 3)
    {
        printf("Ange admin-lösenord (q för huvudmenyn): ");
        scanf("%9s", angivet_lösen);
        if (strcmp(angivet_lösen, "q") == 0)
        {
            return;
        }
        else if (strcmp(angivet_lösen, "******") == 0)
        {
            break;
        }
        else
        {
            printf("Du angav fel lösenord\n");
            antal_försök++;
        }
    }
    while (1)
    {
        printf("\n(1) Registrera nya konton\n(2) Skriva ut alla konton\n(3) Sortera konton\n(4) Söka efter konto\n(5) Avregistrera ett konto\n(6) Huvudmeny\n\nAnge val: ");
        scanf("%d",&val);
        switch (val)
        {
        case 1:
            printf("Registrera nya konton:\n");
            registreraNyttKonto(konton,antalKonton);
            break;
        case 2:
            skrivaUtKonton(konton, *antalKonton);
            break;
        case 3:
            sorteraKonton(konton, *antalKonton);
            break;
        case 4:
            printf("Välj sökalternativ:\n");
            kontoSökande(konton, *antalKonton);
            break;
        case 5:
            printf("För att avregistrera behöver du söka ut ett konto.\n");
            avregKonto(konton, antalKonton);
            break;
        case 6:
            sparaTillFil(filnamn,konton,*antalKonton);
            return;
        default:
            printf("ERROR: Pröva annan siffra mellan 1-6!");
            break;
        }
    }
}