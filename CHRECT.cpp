#include<stdio.h>
#include<stdlib.h>
#define lli long long int
int main()
{
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
    lli n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    if(n==1 && m==2)
    {
       printf("0\n");
       continue;
    }
    if(m==1 && n==2)
    {
       printf("0\n");
       continue;
    }
    if(n==1 || m==1)
    {
       printf("%lld\n",k);
       continue;
    }
    else
    {
       if(k%2==0)
       {
         printf("%lld\n",k/2);
       }
       else
       {
           printf("%lld\n",k/2+1);
       }
    }
  }
  return 0;
}
 