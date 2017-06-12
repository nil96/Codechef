#include <bits/stdc++.h>
using namespace std;
#define lli long long int
map<lli,lli> m;
int main()
{
	lli t;
	scanf("%lld",&t);
	while(t--)
	{
       lli n;
       scanf("%lld",&n);
       m.clear();
       for(lli i=0;i<n;i++)
       {
       	 lli temp;
         scanf("%lld",&temp);
         if(m.find(temp)==m.end())
         	m[temp]=1;
         else
         	m[temp]++;
       }
       lli ans=0;
       map<lli,lli> :: iterator it;
       priority_queue<lli> q;
       while(!q.empty())
       	 q.pop();
       for(it=m.begin();it!=m.end();it++)
       {
       	 q.push(it->second);
       }
       while(q.size()>1)
       {
          if(q.size()>1)
          {
            lli z=q.top();q.pop();
            lli z1=q.top();q.pop();
            ans++;
            if(z1-1>0)
              q.push((z1-1));
            if(z-1>0)
              q.push((z-1));
          }
          else if(q.size()==1)
          	break;
       }
       if(q.size()==1)
       	 ans=ans+q.top();
       printf("%lld\n",ans);
 
	}
	return 0;
} 