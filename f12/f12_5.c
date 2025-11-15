#include <stdio.h>
#include <string.h>

struct tempData
{
    char date[11];
    float temperatur[10];
    int data;
};
void printTemp(struct tempData t);
void concatenate(struct tempData *t1, struct tempData *t2);

int main()
{
    struct tempData temperatures1={"2021-06-27",{18.7, 19.2, 18.3}, 3};
    printTemp(temperatures1);
    
    struct tempData temperatures2={"2021-06-27",{22.1, 23.4}, 2};
    concatenate(&temperatures1, &temperatures2);

    printTemp(temperatures1);


return 0;
}
void printTemp(struct tempData t)
{
    printf("%s ",t.date);
    for (int i = 0; i < t.data; i++)
    {
        printf("%.1f ",t.temperatur[i]);
    }
    printf("\n");
}
void concatenate(struct tempData *t1, struct tempData *t2)
{
    if (strcmp(t1->date, t2->date)!=0)
    return;
    
    int platsKvar=10-t1->data;
    int antalAttKopiera= t2->data;

    if (antalAttKopiera>platsKvar)
        antalAttKopiera=platsKvar;
    for (int i = 0; i < antalAttKopiera; i++)
    {
        t1->temperatur[t1->data+i]=t2->temperatur[i];
    }
    t1->data +=antalAttKopiera;
}
