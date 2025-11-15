#include <stdio.h>
#define WORDLENGTH 31

void everyOther(char word1[], char word2[]);
void twoAndTwo(char word1[], char word2[]);

int main()
{
    char word1[WORDLENGTH], word2[WORDLENGTH];
    int choice;

    printf("Ord 1: ");
    scanf("%s", word1);
    printf("Ord 2: ");
    scanf("%s", word2);

    do
    {
        printf("Varannan (1), Tva och tva (2), Avsluta (3): ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1: everyOther(word1, word2);
            break;
            case 2: twoAndTwo(word1, word2);
            break;
        }
    } 
    while (choice!=3);
    
    printf("Avslutar\n");
    return 0;
}

void everyOther(char word1[], char word2[])
{
    int index1=0, index2=0;
    while (word1[index1] || index2 = )
    {
        /* code */
    }
    
}
