#include <stdio.h>

struct logg 
{
    float temperaturer[20];
    int antal;
};
void addTemp(struct logg *l, float nyTemp);
void printLogg(struct logg l);
float medel(struct logg l);
int main()
{
    float nyTemp;
    struct logg mätning_1={{31.4,31.0,30.5,30.3,29.5},5};
    printf("Före: ");
    printLogg(mätning_1);
    addTemp(&mätning_1, 28.5);
    printf("\nEfter: ");
    printLogg(mätning_1);
    float medelvärde=medel(mätning_1);
    printf("\nMedelvärde: %.1f",medelvärde);
    return 0;
}
void addTemp(struct logg *l, float nyTemp)
{
    l->temperaturer[l->antal]=nyTemp;
    l->antal++;
}
void printLogg(struct logg l)
{
    for (int i = 0; i < l.antal; i++)
    {
        printf("%.1f, ",l.temperaturer[i]);
    }
}
float medel(struct logg l)
{
    float summa=0;
    for (int i = 0; i < l.antal; i++)
    {
        summa += l.temperaturer[i];
    }
    float medelvärde = (float)summa/l.antal;
    return medelvärde;

}


