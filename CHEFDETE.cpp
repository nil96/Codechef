#include <bits/stdc++.h>
using namespace std;
#define lli long long int
map<lli,lli> m;
lli arr[1000000];
int main()
{
     lli n;
     lli z=0;
     scanf("%lld",&n);
     m.clear();
     for(lli i=1;i<=n;i++)
       arr[i]=0;
     for(lli i=1;i<=n;i++)
     {
     	lli temp;
     	scanf("%lld",&temp);
     	if(temp==0)
     	{
     		arr[i]=1;
     		z=i;
     	}
     	else
     	  arr[temp]=1;
     }
     if(n==1)
     	printf("%lld\n",z);
     for(lli i=1;i<=n;i++)
     {
     	if(arr[i]==0)
     		printf("%lld ",i);
     }
 
} 