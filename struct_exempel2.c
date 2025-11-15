#include <stdio.h>

struct logg
{
    int pulsmätningar[20];
};

struct person
{
    char namn[20];
    struct logg person_logg;
    int antal;
};
void addPulse(struct person *p,int nyMätning);
void printPerson(struct person p);
float medelPuls(struct person *p);
int main()
{
    struct person patient_1={{"Alvin"},{72,75,80},3};
    printf("Första mätning:\n");
    printPerson(patient_1);

    printf("Andra mätning:\n");
    addPulse(&patient_1, 78);
    printPerson(patient_1);
    float medelVärde=medelPuls(&patient_1);
    
    printf("Medelpuls: %.1f",medelVärde);
    
    return 0;

}
void addPulse(struct person *p,int nyMätning)
{
    if (p->antal >= 20)
    {
        printf("Fullt med mätningar!");
        return;
    }
    else
    {
        p->person_logg.pulsmätningar[p->antal] = nyMätning;
        p->antal++;
    }
    
}
void printPerson(struct person p)
{
    printf("Person: %s\n",p.namn);
    printf("Pulsmätningar: ");
    for (int i = 0; i < p.antal; i++)
    {
        printf("%d ",p.person_logg.pulsmätningar[i]);
    }
    printf("\n");
}
float medelPuls(struct person *p)
{
    int summa=0;
    for (int i = 0; i < p->antal; i++)
    {
        summa += p->person_logg.pulsmätningar[i];
    }
    float medelVärde = (float)summa/p->antal;
    return medelVärde;
}



