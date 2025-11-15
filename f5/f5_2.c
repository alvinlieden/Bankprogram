#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
   int stickor = 15;
   int spelarens_val;
   int datorns_val;
   int spelaren_vann = 0;
   int datorn_vann = 0;

  srand(time(NULL));
  printf("Välkommen till tandsticksspelet.\n");
  
  while(stickor>0 && spelaren_vann == 0 && datorn_vann == 0)
  {
    for (int i = 0; i < stickor; i++)
    {
        printf("| ");
    }
    printf(" \n");
    printf("Hur många stickor vill du ta? (1-3)\n");
    scanf("%d",&spelarens_val);
    if (spelarens_val < 1 || spelarens_val >3 || spelarens_val > stickor )
    {
        printf("Ogiltigt drag! (1-3)\n");
        continue;
    } 
    else
        {
        stickor = stickor - spelarens_val;
        }
    if (stickor==0)
    {
        spelaren_vann=1;
    }
    
    datorns_val = rand()%3+1;
    if (datorns_val > stickor)
        datorns_val = stickor;
    printf("Datorn tar %d stickor.\n",datorns_val);
    stickor = stickor - datorns_val;
    if (stickor==0)
    {
        datorn_vann=1;
    }
    
    if(spelaren_vann)
    {
        printf("Du vann!\n");
    } else if (datorn_vann)
    {
        printf("Datorn vann!\n");
    }
  }
   return 0;
}