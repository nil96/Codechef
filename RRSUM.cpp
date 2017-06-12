#include<stdio.h>
#include<stdlib.h>
#define lli long long int
lli mod(lli a)
{
  if(a>0)
   return a;
  else
   return -a;
}
int main()
{
   lli n,m,dis,q,l,k,ans;
   scanf("%lld%lld",&n,&m);
   l=3*n;
   k=2*n+1;
   while(m--)
   {
      ans=n;
      scanf("%lld",&q);
      if(q>=n+2 && q<=l)
      {
         dis=mod(k-q);
         ans=ans-dis;
         printf("%lld\n",ans);
      }
      else
      {
        printf("0\n");
      }
   }
   return 0;
}