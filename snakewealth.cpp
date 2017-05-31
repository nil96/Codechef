#include<bits/stdc++.h>
#define lli long long int
#define sc(a) scanf("%lld",&a);
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define FORE(i,a,n) for(int i=a;i<=n;i++)
#define gc() getchar_unlocked();
#define pb(a) push_back(a);
using namespace std;
lli arr[1003][1003];
lli x[]={0,0,1,-1,1,1,-1,-1};
lli y[]={1,-1,0,0,1,-1,1,-1};
lli getmax(lli r,lli c)
{
	lli max1=INT_MIN;
	FOR(i,0,r)
      FOR(j,0,c)
      	 max1=max(max1,arr[i][j]);
    return max1;
}
lli bfs(lli r,lli c,lli z)
{
  list<pair<lli,lli> > q;
  int vis[r+2][c+2];
  q.clear();
  lli counter=0;
   FOR(i,0,r)
      FOR(j,0,c)
      {
      	 vis[i][j]=0;
      	 if(arr[i][j]==z)
      	 {
      	 	pair<lli,lli> temp;
      	 	temp.first=i;
      	 	temp.second=j;
      	 	q.push_back(temp);
      	 	vis[i][j]=1;
      	 	counter++;
      	 }
      }
  list<pair<lli,lli> >::iterator it;  
  lli ans=0;
  while(!q.empty())
  {
  	 if(counter==0)
  	 {
  	 	ans++;
  	 	counter=q.size();
  	 }
  	 counter--;
  	 it=q.begin();
  	 q.pop_front();
  	 pair<lli,lli> z = *it;
     lli x1=z.first,y1=z.second;
     FOR(i,0,8)
     {
     	lli a=x1+x[i];
     	lli b=y1+y[i];
     	if(a>=0 && a<r && b>=0 && b<c && vis[a][b]==0)
     	{
     		vis[a][b]=1;
            z.first=a;
            z.second=b;
            q.push_back(z);
     	}
     }
  }
  return ans;    
}
int main()
{
	lli t;
	sc(t);
	while(t--)
	{
		lli r,c;
		sc(r);sc(c);
        FOR(i,0,r)
          FOR(j,0,c)
            sc(arr[i][j]);
        lli z=getmax(r,c);
        z=bfs(r,c,z);
        printf("%lld\n",z);
	}
}