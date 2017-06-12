#include<stdio.h>
#include<stdlib.h>
#define lli long long int
int main()
{
   lli t;
   float m=0.0f;
   scanf("%lld",&t);
   while(t--)
   {
     lli ds,dt,d;
     scanf("%lld%lld%lld",&ds,&dt,&d);
     if(ds>=d+dt)
       printf("%lld\n",ds-d-dt);
     else if(dt>=ds+d)
       printf("%lld\n",dt-d-ds);
     else if(d>=ds+dt)
       printf("%lld\n",d-dt-ds);
    else
      printf("0\n");
 
   }
   return 0;
}
 