#include<bits/stdc++.h>
#define lli long long int
#define sc(a) scanf("%lld",&a);
#define sc_(a,b) scanf("%lld%lld",&a,&b);
#define sc__(a,b,c) scanf("%lld%lld%lld",&a,&b,&c);
#define FOR(i,a,b) for(lli i=a;i<b;i++)
#define FORE(i,a,b) for(lli i=a;i<=b;i++)
#define gc() getchar_unlocked();
#define MAX(a,b) a>b ? a:b;
#define MIN(a,b) a<b ? a:b;
#include<math.h>
using namespace std;
int main()
{
   lli t;
   sc(t);
   while(t--)
   {
     lli n1,n2,m;
     sc__(n1,n2,m);
     gc();
     lli nz=MIN(n1,n2);
     lli l=MIN(nz,m*(m+1)/2);
     l=n1+n2-2*l;
     printf("%lld\n",l);
   }
   return 0;
}
 