#include <bits/stdc++.h>
#define lli long long int
#define gc() getchar_unlocked();
#define sc(a) scanf("%lld",&a);
#define sc_(a,b) scanf("%lld%lld",&a,&b);
#define pf(a) printf("%lld\n",a);
#define FOR(i,a,b) for(lli i=a;i<b;i++)
using namespace std;
lli arr[1000000];
lli hash1[1000000];
lli init(lli n,lli k)
{
	FOR(i,0,20)
	{
	 hash1[i]=0;
	 arr[i]=0;
	}
}
int main()
{
	lli t;
	sc(t);
	while(t--)
	{
		lli n,k;
		sc_(n,k);
		init(n,k);
        lli l=0;
        FOR(i,0,n)
        {
        	lli temp;
        	sc(temp);
        	lli m=temp%(k+1);
        	if(hash1[m]==0)
        	{
        		arr[l++]=m;
        	}
        	 hash1[m]++;
        }
        if(l>2)
        {
        	printf("NO\n");
        }
        else
        {
        	if(l==1 || l==2 && (hash1[arr[0]]==n-1 || hash1[arr[1]]==n-1))
               printf("YES\n");
            else
               printf("NO\n");  		
        }
	}
	return 0;
} 
Comments 
