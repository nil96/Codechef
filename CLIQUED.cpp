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
lli n,k,x,m,s;
vector<pair<lli,lli> > v[100030];
lli visited[100030],dist[100030];
void init()
{
	FOR(i,0,n+2)
	{
		visited[i]=0;
		v[i].clear();
	}
}
lli isSpecialVertex(lli x)
{
   if(x>=1 && x<=k)
     return 1;
   return 0;
}
class CompareDist
{
   public:
   	bool operator()(pair<lli,lli>a,pair<lli,lli> b)
   	{
   		return a.second>b.second;
   	}
};
void printDist()
{
    printf("\n------------------------------\n");
    FORE(i,1,n)
      printf("%lld ",dist[i]);
    printf("\n------------------------------\n");
}
void Dijkitras(lli s)
{
	priority_queue<pair<lli,lli> ,vector<pair<lli,lli> >,CompareDist > pq;
    while(!pq.empty())
       pq.pop();
    FORE(i,1,n)
      dist[i]=infi;
    pq.push(mp(s,0));
    dist[s]=0;
    lli flag=0;
    while(!pq.empty())
    {
    	pair<lli,lli> temp=pq.top();
        lli u=temp.first,wt=temp.second;
        pq.pop();
        if(visited[u]==1)
        	continue;
        visited[u]=1;
        FOR(i,0,v[u].size())
        {
        	if(wt+v[u][i].second<dist[v[u][i].first] )
        	{	
        	  dist[v[u][i].first] = wt + v[u][i].second;
        	  pq.push(mp(v[u][i].first,dist[v[u][i].first]));
        	}
        }
        //printDist();
        if(flag==0 && isSpecialVertex(u)==1)
        {
            flag=1;
            FORE(i,1,k)
            {
                if(i!=u)
                {
                  pq.push(mp(i,min(dist[u]+x,dist[i])));
                  dist[i]=min(dist[u]+x,dist[i]);
                }
 
            }
        }
    } 
}
int main()
{
	lli t;
	sc(t);
	while(t--)
	{
        sc(n),sc(k),sc(x),sc(m),sc(s);
        init();
        FOR(i,0,m)
        {
        	lli a,b,c;
        	sc3(a,b,c);
        	v[a].pb(mp(b,c));
        	v[b].pb(mp(a,c));
        }
        Dijkitras(s);
        FORE(i,1,n)
	    {
	       printf("%lld ",dist[i]);
	    }
	    printf("\n");
 
	}
 
} 