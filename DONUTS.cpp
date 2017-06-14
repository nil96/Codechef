#include<bits/stdc++.h>
#define lli long long int
using namespace std;
lli v[1000010];
lli cmp(lli i,lli j)
{
	return i<j;
}
int main()
{
	lli t;
	scanf("%lld",&t);
	while(t--)
	{
        lli n,m;
        scanf("%lld%lld",&n,&m);
       // v.clear();
        for(lli i=0;i<m;i++)
        {
           lli temp;
           scanf("%lld",&v[i]);
        }
        sort(v,v+m,cmp);
        lli i=0,c=0;
        while(m-1>0 && v[i]<m-1)
        {
           if(v[i]<m-1)
           {
           	  c=c+v[i];
           }
           else
           	break;
           m=m-v[i]-1;
           i++;
        }
        c=c+m-1;
        printf("%lld\n",c);
	}
	return 0;
} 