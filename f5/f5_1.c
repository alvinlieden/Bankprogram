#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int die1 = rand()%10-2;
    float die2 = rand()/(float)RAND_MAX*5-2;
    float die3 = rand()/(float)RAND_MAX*24;
    printf("Du fick %d, %f och %f",die1,die2,die3);
    return 0;
}