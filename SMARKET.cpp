#include<bits/stdc++.h>
#define lli long long int
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define rlli(a) scanf("%lld",&a)
#define sc(a) scanf("%lld",&a)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define gc() getchar_unlocked()
#define pb(a) push_back(a)
#define pf(a) printf("%lld\n",a);
#define mp(a,b) make_pair(a,b) 
#define infi 10000000000000
using namespace std;
vector<lli> v;
lli oprtn(lli l,lli r,lli k)
{
	lli ans=0,count1=0;
	FORE(i,l-1,r-1)
	{
      lli x=v[i];
      while(v[i]==x && i<=(r-1))
      {
      	i++;
      	count1++;
      }
      if(count1>=k)
      	 ans++;
      i--;
      count1=0;
	}
	return ans;
}
int main()
{
	lli t;
	sc(t);
	while(t--)
	{
		lli n,q,temp;
		sc(n);sc(q);
		v.clear();
		FOR(i,0,n)
		{
			sc(temp);
			v.pb(temp);
		}
		while(q--)
		{
			lli l,r,k;
			sc(l),sc(r),sc(k);
			lli ans=oprtn(l,r,k);
		    pf(ans);
		}
	}
	return 0;
} 