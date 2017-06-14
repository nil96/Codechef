#include<bits/stdc++.h>
#define lli long long int
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define rlli(a) scanf("%lld",&a)
#define sc(a) scanf("%lld",&a)
#define gc() getchar_unlocked()
#define pb(a) push_back(a)
using namespace std;
int arr[100040];
vector<lli> v[100030];
char ans[][10]={"sad","all","some"};
void init(lli k)
{
	FOR(i,0,k+1)
	{
	   arr[i]=0;
	   v[i].clear();
	}
}
size_t oprtn(lli n,lli k)
{
	int flag=0;
	FORE(i,1,k)
    {
      if(arr[i]==0)
      	return flag;
    }
	FOR(i,0,n)
	{
		int survived=1;
        FOR(j,0,v[i].size())
        {
        	arr[v[i][j]]--;
        }
        int zz=1;
        FOR(j,0,v[i].size())
        {
          zz=zz*arr[v[i][j]];
        }
        if(zz>0)
        {
          	//printf("i====%d\n",i);
          	return 2;
        }
        FOR(j,0,v[i].size())
        {
        	arr[v[i][j]]++;
        }
	}
	return 1;
}
int main()
{
	lli t;
	sc(t);
	while(t--)
	{
		lli n,k,x,temp;
		sc(n);sc(k);
		init(k+1);
		FOR(i,0,n)
		{
            sc(x);
            FOR(j,0,x)
            {
            	sc(temp);
            	v[i].pb(temp);
            	arr[temp]++;
            }
		}
		size_t x1=oprtn(n,k);
		printf("%s\n",ans[x1]);
	}
	return 0;
} 