#include <stdio.h>

int main(){
    int choice,code;
    char stop='n',sign;
    while(stop!='j'){
        printf("Vill du ange ett tecken (1) eller en kod (2): ");
        scanf("%d",&choice);
        if(choice==1){
            printf("Ange tecken: ");
            scanf(" %c",&sign);
            printf("Tecknet motsvaras av koden: %d\n",sign);
        }else{
            printf("Ange kod: ");
            scanf("%d",&code);
            if(0<=code&&code<128){
                printf("Koden motsvaras av tecknet: %c\n",code);
            }else{
                printf("Du angav inte en ascii-kod.\n");
            }
        }
        printf("Vill du avsluta (j/n): ");
        scanf(" %c",&stop);
    }
    printf("Avslutar\n");
    return 0;
}