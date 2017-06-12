#include <bits/stdc++.h>
#define lli long long int
#define gc() getchar_unlocked()
using namespace std;
int main()
{
   lli t;
   scanf("%lld",&t);gc();
   while(t--)
   {
   	 lli n;
      scanf("%lld",&n);gc();
      lli r=0,g=0,b=0,i=n;
      while(n--)
      {
        char c;
        scanf("%c",&c);
        if(c=='R')
          r++;
        else if(c=='G')
          g++;
        else
          b++;
      }
      lli z=max(max(r,g),b);
      printf("%lld\n",i-z);
   }
   return 0;
} 