//Please like me
#include<stdio.h>
#include<stdlib.h>
int main()
{
  long long int t,L,D,S,C,i,k=1,flag=0;
  scanf("%lld",&t);
  while(t--)
  {
     flag=0;
     scanf("%lld %lld %lld %lld",&L,&D,&S,&C);
   //  printf("%lld,%lld,%lld,%lld\n",L,D,S,C);
     if(S>=L)
     {
         printf("ALIVE AND KICKING\n");
         continue;
     }
     for(i=2;i<=D;i++)
     {
        S=S+C*S;
        if(S>=L)
        {
          flag=1;
          break;
        }
     }
     if(flag==1)
      printf("ALIVE AND KICKING\n");
     else
      printf("DEAD AND ROTTING\n");
  }
  return 0;
}
 
Comments 
