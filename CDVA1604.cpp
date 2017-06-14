#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli dp[10000000];
int main()
{
   lli t;
   scanf("%lld",&t);
   dp[0]=1;
   dp[1]=1;dp[2]=2;dp[3]=2;dp[4]=4;
   for(lli i=4;i<=1000000;i++)
   {
   	if(i%2==0)
   	   dp[i]=2*dp[i/2];
   	if(i%2==1)
   	{
      lli x=dp[i/2];
      if(x==i/2)
      	dp[i]=2;
      else
      	dp[i]=2+2*x;
   	}
   }
   while(t--)
   {
     lli z;
     scanf("%lld",&z);
     printf("%lld\n",dp[z]);
   }
   return 0;
} 