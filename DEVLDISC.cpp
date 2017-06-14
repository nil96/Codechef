#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    lli t;
    scanf("%lld",&t);
    while(t--)
    {
    	lli n;
    	scanf("%lld",&n);
    	if(n<=6)
    	   printf("-1\n");
    	else
    	{
    		printf("%lld\n",n);
    		printf("1 2\n");
    		printf("2 3\n");
    		printf("3 7\n");
    		printf("3 4\n");
    		printf("4 5\n");
    		printf("5 6\n");
    		printf("1 6\n");
    		for(lli i=8;i<=n;i++)
    		{
              printf("3 %lld\n",i);
    		}
    		printf("2\n");
    	}
    }
} 