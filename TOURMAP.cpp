#include <bits/stdc++.h>
#define lli long long int
#define gc() getchar_unlocked()
#define sc(a) scanf("%lld",&a);gc();
#define sc_(a,b) scanf("%lld%lld",&a,&b);gc();
#define FOR(i,a,b) for(lli i=a;i<b;i++)
using namespace std;
map<string,lli> m;
map<lli,string> rm;
string s,s1;
lli cstm[5001][5001];
vector<lli> v[5001];
stack<lli> stck;
lli visited[5003];
lli init(lli x)
{
	FOR(i,0,x)
	{
		v[i].clear();
		FOR(j,0,x)
		{
			cstm[i][j]=0;
		}
	}
	m.clear();
	rm.clear();
}
void print(lli x)
{
	FOR(i,0,x)
	{
	  FOR(j,0,x)
	  {
	    printf("%lld ",cstm[i][j]);
	  }
	  printf("\n");
	}
}
lli input()
{
	char buffer[1000];
    scanf("%s",buffer);gc();
    lli i=0;
    while(1)
    {
       if(buffer[i]=='$')
       {
       	 buffer[i]='\0';
       	 break;
       }
       i++;
    }
    return atoi(buffer);
}
void dfs(lli s)
{
	visited[s]=1;
	vector<lli> ::iterator it;
	for(it=v[s].begin();it<v[s].end();it++)
	{
		if(visited[*it]==0)
			dfs(*it);
	}
	stck.push(s);
}
lli fill(lli x)
{
 
	while(stck.empty()==false)
		stck.pop();
	FOR(i,0,x)
	 visited[i]=0;
	FOR(i,0,x)
	{
		if(visited[i]==0)
		  dfs(i);
	}
	lli ans=0,top;
	if(stck.empty()==false)
	  top=stck.top();
	lli n=0;
	while(stck.empty()==false)
	{
		if(n==x-1)
		  break;
		stck.pop();
		lli top1=stck.top();
        cout<<rm[top]<<" "<<rm[top1]<<" "<<cstm[top][top1]<<"$\n";
	    ans+=cstm[top][top1];
	    top=top1;
	    n++;
	}
	printf("%lld$\n",ans);
}
int main()
{
	lli t;
	sc(t);
	while(t--)
	{
		lli x;
		sc(x);
		init(x);		
		lli c=0;
		FOR(i,0,x-1)
		{
          cin>>s;gc();
          if(m.find(s)==m.end())
          {
          	m[s]=c;
          	rm[c]=s;
          	c++;
          }
          cin>>s1;gc();
          if(m.find(s1)==m.end())
          {
          	m[s1]=c;
          	rm[c]=s1;
          	c++;
          }
          lli cost=input();
          cstm[m[s]][m[s1]]=cost;
          v[m[s]].push_back(m[s1]);
		}
		fill(x);
	}
	return 0;
}
 