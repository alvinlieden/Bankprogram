#include <stdio.h>
#include <string.h>

struct bankAccount
{
    char namn[41];
    int saldo;
};
typedef struct bankAccount konto;

konto createAccount(char namn[], int saldo);
void printAccount(konto k);
void transfer(konto *from, konto *to);

int main()
{
    konto account1=createAccount("Simran Singh",3210);
    konto account2=createAccount("Mark Asplund",210);

    printAccount(account1);
    printAccount(account2);

    transfer(&account1, &account2);
    
    printAccount(account1);
    printAccount(account2);

    
    return 0;
}

konto createAccount(char namn[], int saldo)
{
    konto nyttKonto;
    strcpy(nyttKonto.namn,namn);
    nyttKonto.saldo=saldo;
    return nyttKonto;
}
void printAccount(konto k)
{
    printf("%s %d kr\n",k.namn,k.saldo);
}
void transfer(konto *from, konto *to)
{
    to->saldo += from->saldo;
    from->saldo=0;
    return;
}
