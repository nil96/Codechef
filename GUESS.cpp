#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define lli long long int
#define FOR(i,a,b) for(lli i=a;i<b;i++)
#define sc1(n) scanf("%lld",&n)
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
	gcd(y,x%y);
}
lli even1,even2,odd1,odd2;
lli find_odd1(lli n)
{
	 even1=n/2;
	 odd1=n-n/2;
}
 
lli find_odd2(lli n)
{
	even2=n/2;
	odd2=n-n/2;
}
int main()
{
	lli t;
	scanf("%lld",&t);
	while(t--)
	{
		lli n,m;
		sc2(n,m);
        lli x1=find_odd1(n);
        lli y1=find_odd2(m);
 
        lli up=even1*odd2+even2*odd1;
        lli down=n*m;
        lli c=gcd(up,down);
        up=up/c;
        down=down/c;
        printf("%lld/%lld\n",up,down);
	}
	return 0;
} 