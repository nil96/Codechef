#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#define lli long long int
#define FOR(i,a,b) for(lli i=a;i<b;i++)
#define sc(n) scanf("%lld",&n)
#define sc2(x,y) scanf("%lld%lld",&x,&y)
#define sc3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define pf(n) printf("%lld ",n)
using namespace std;
lli gcd(lli x,lli y)
{
	if(x==0)
	 return y;
	if(y==0)
	 return x;
	return gcd(y,x%y);
}
int main()
{
	lli t;
	sc(t);
    while(t--)
    {
    	lli a,b,c,d,k;
    	sc2(a,b);sc2(c,d);sc(k);
        lli m=gcd(a,b);
        lli n=gcd(c,d);
        lli r=gcd(m,n);
        lli lcm=(m/r);
        lli ans=(k/lcm);
        ans=ans/n;
        printf("%lld\n",2*ans+1);
    }
    return 0;
} 