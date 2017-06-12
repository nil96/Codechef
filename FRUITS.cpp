#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
	lli t;
	scanf("%lld",&t);
	while(t--)
	{
       lli n,m,k;
       scanf("%lld%lld%lld",&n,&m,&k);
       lli x=abs(n-m);
       x=x-k;
       if(x<0)
       	 printf("0\n");
       else
       	 printf("%lld\n",x);
	}
	return 0;
} 