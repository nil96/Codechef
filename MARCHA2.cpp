#include <bits/stdc++.h>
#define lli long long int
#define gc() getchar_unlocked()
#define FOR(i,a,b) for(lli i=a;i<b;i++)
#define FORR(i,a) for(lli i=b;i>=0;i--)
#define sc(n) scanf("%lld",&n);
#define pf(n) printf("%lld\n",n);
using namespace std;
lli arr[10000000];
int main()
{
	lli t;
	sc(t);
	while(t--)
	{
		lli n;
		sc(n);
		lli flag=0;
		lli leaf;
		lli steam=1;
		FOR(i,0,n)
		{
           sc(leaf);
           if(leaf>steam)
           	 flag=1;
            steam=2*(steam-leaf);
		}
		if(flag || steam)
		   printf("No\n");
		else
           printf("Yes\n");
	}
	return 0;
} 