#include<stdio.h>
#include<stdlib.h>
#define lli long long int
lli max1(lli x,lli y)
{
   if(x>y)
     return x;
   return y;
}
lli min1(lli x,lli y)
{
   if(x<y)
     return x;
   return y;
}
int main()
{
  lli t;
  lli arr[110];
  scanf("%lld",&t);
  while(t--)
  {
    for(lli i=0;i<=100;i++)
      arr[i]=0;
    lli m,x,y,sum=0;
    lli n=0,m1;
    scanf("%lld%lld%lld",&m,&x,&y);
    for(lli i=0;i<m;i++)
    {
       scanf("%lld",&n);
       for(lli j=n;j>=max1(n-x*y,1);j--)
         arr[j]=1;
        for(lli k=n;k<=min1(n+x*y,100);k++)
         arr[k]=1;
    }
    for(lli i=1;i<=100;i++)
    {
      if(arr[i]==0)
      {
        sum++;
      }
    }
  
    printf("%lld\n",sum);
  }
  return 0;
}