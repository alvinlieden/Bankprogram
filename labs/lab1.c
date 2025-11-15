#include <stdio.h>

int main()
{
    int t;
    float h,v;
    t=0;
    h=250.0;
    v=-25.0;
    printf("Lunar descent challenge!\n");
    printf("Set the throttle for each second. (0-100)\n");
    printf("Time(s) Height(m) Velocity(m/s) Throttle?\n");
    
    for(t=0;1==1;t++)
    {
        printf("%4d %9.1f %11.1f",t,h,v);
        int f;
        printf("          ");
        scanf("%d",&f);
        while(f<0 || f>100) 
            {
                printf("Throttle 0-100!\n");
                printf("%4d %9.1f %11.1f          ",t,h,v);
                scanf("%d",&f);
        
            }   
        h=h+v+(0.1*f-1.5)/2;
            v=v+(0.1*f-1.5);
            if(h<=0)
            {
            break;
        }
    }
        if(v>=-2){
            printf("You successfully landed!\n");
        }
        else
        {
            printf("FAILED! Crash landing at %.1f m/s\n,",v);
        }
    
    return 0;
}