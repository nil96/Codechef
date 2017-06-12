#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#define lli long long int
#define FOR(i,a,b) for(lli i=a;i<b;i++)
#define sc1(n) scanf("%lld",&n)
#define sc2(x,y) scanf("%lld%lld",&x,&y)
#define sc3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define pf(n) printf("%lld ",n)
using namespace std;
lli arr[1000000];
map<lli,lli> m;
map<lli,lli> :: iterator it;
lli cmp(lli x,lli y)
{
	return x<y;
}
int main()
{
	lli t;
	scanf("%lld",&t);
	while(t--)
	{
		lli n,k;
		sc2(n,k);
		m.clear();
		FOR(i,0,n)
		{
           sc1(arr[i]);
		}
		sort(arr,arr+n,cmp); 
		FOR(i,0,n)
		{
		   lli old=1000000000000;
           FOR(j,i+1,n)
           {
              lli z=abs(arr[i]+arr[j]-k);
              if(m.find(z)==m.end())
              {
              	m[z]=1;
              }
              else
              {
              	m[z]++;
              }
              if(old<z)
              	break;
              old=z;
           }
		}
		lli min=10000000000;
		lli count1=0;
		for(it=m.begin();it!=m.end();it++)
		{
			if(it->first<min)
			{
				min=it->first;
                count1=it->second;
			}
		}
		printf("%lld %lld\n",min,count1);
	}
	return 0;
} 
Submission Info: