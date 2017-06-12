#include <bits/stdc++.h>
#define lli long long int
#define FOR(i,a,b) for(lli i=a;i<b;i++)
#define FORE(i,a,b) for(lli i=a;i<=b;i++)
#define sc(a) scanf("%lld",&a);
#define sc_(a,b) scanf("%lld%lld",&a,&b);
using namespace std;
int main()
{
  lli t;
  sc(t);
 
  while(t--)
  {
    lli n;
    sc(n);
    lli min=10000000;
    lli ans=0;
    FOR(i,0,n)
    {
      lli temp;
      sc(temp);
      ans+=temp;
      if(min>temp)
        min=temp;
    }
    ans-=min;
    ans*=min;
    printf("%lld\n",ans);
  }
  return 0;
}
 