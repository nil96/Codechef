#include <bits/stdc++.h>
#define lli long long int
#define gc() getchar_unlocked()
using namespace std;
int main()
{
   lli t;
   scanf("%lld",&t);
   while(t--)
   {
   	  lli r,b,g,k,ans=0;
   	  scanf("%lld%lld%lld",&r,&b,&g);
   	  scanf("%lld",&k);
      lli x=min(min(r,b),g);
   	  if(x>=k)
   	  {
          ans=ans+3*(k-1);
   	  }
   	  else
   	  {
   	  	ans=min(r,k-1)+min(b,k-1)+min(g,k-1);
   	  }
   	  printf("%lld\n",ans+1);
   }   
 
   return 0;
} 