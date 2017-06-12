#include<stdio.h>
#include<stdlib.h>
#define lli long long int
lli dp[10000001];
lli max(lli a,lli b)
{
  if(a>b)
   return a;
  else
   return b;
}
lli learn()
{
  dp[0]=0;
  lli i;
  for(i=1;i<10000001;i++)
  {
    dp[i]=max(i,dp[i/2]+dp[i/3]+dp[i/4]);
  }
}
lli query(lli t)
{
  if(t<10000001)
  {
    return dp[t];
  }
  else
  {
    lli ans;
    ans=max(t,query(t/2)+query(t/3)+query(t/4));
    return ans;
  }
}
int main()
{
  lli t;
  learn();
  while(scanf("%lld",&t)>0)
  {
     lli ans=query(t);
     printf("%lld\n",ans);
  }
  return 0;
}