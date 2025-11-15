#include <stdio.h>
#include <string.h>

void addWordPair(char svenska[20][21],char engelska[20][21], int *nrOfWordPairs);
void printWordPair(char svenska[20][21],char engelska[20][21], int nrOfWordPairs);

int main()
{
    int userChoice=0;
    int nrWordPairs=0;
    char svenska[20][21];
    char engelska[20][21];
    while (1)
    {
        printf("(1) Skriva in (2) Skriva ut (3) Radera (4) Avsluta:");
        scanf("%d",&userChoice);
        
        switch (userChoice)
        {
            case 1:
            addWordPair(svenska, engelska,&nrWordPairs);
            break;
            case 2:
            printWordPair(svenska, engelska, nrWordPairs);
            break;
            case 3:
            nrWordPairs=0;
            break;
            case 4:
            printf("Avslutar\n");
            return 0;
            default:
            printf("Ogiltig val!\n");
            break;
        }
    }
return 0;
}

void addWordPair(char svenska[20][21],char engelska[20][21], int *nrOfWordPairs)
{
    char svOrd[21];
    char enOrd[21];
        while(*nrOfWordPairs<20)
        {
            printf("Svenska:");
            scanf("%20s",svOrd);
            if (strcmp(svOrd, "q")==0)
            {
                return;
            }
            
        
            printf("Engelska:");
            scanf("%20s",enOrd);
            if (strcmp(enOrd, "q")==0)
            {
                return;
            }

            strcpy(svenska[*nrOfWordPairs], svOrd);
            strcpy(engelska[*nrOfWordPairs],enOrd);
            (*nrOfWordPairs)++;
        }
}

void printWordPair(char svenska[20][21],char engelska[20][21], int nrOfWordPairs)
{
    if (nrOfWordPairs==0)
    {
        printf("Gloslistan är tom\n");
        return;
    }
    
    for(int i=0;i<nrOfWordPairs;i++)
    {
        printf("%s - %s\n",svenska[i], engelska[i]);
    }
}

