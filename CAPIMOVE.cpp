#include<bits/stdc++.h>
#define lli long long int
using namespace std;
vector<lli> v;
vector<lli> g[1000000];
vector<lli> gc[1000000];
struct node
{
   lli index,num;
   bool operator<(const node& b) const{
     return num < b.num;
   }
};
struct node temp;
priority_queue<node> pq;
void init(lli n)
{
   while(!pq.empty())
     pq.pop();
   v.clear();
   for(lli i=0;i<n;i++)
   {
      g[i].clear();
      gc[i].clear();
   }
}
lli cmp(lli a,lli b)
{
  return a>b;
}
int main()
{
   lli t;
   scanf("%lld",&t);
   while(t--)
   {
     lli n;
     scanf("%lld",&n);
     init(n+3);
     for(lli i=0;i<n;i++)
     {
       lli p;
       scanf("%lld",&p);
       v.push_back(p);
       temp.index=i+1;
       temp.num=p;
       pq.push(temp);
     }
     for(lli i=0;i<n-1;i++)
     {
        lli a,b;
        scanf("%lld%lld",&a,&b);
        g[a-1].push_back(b-1);
        gc[a-1].push_back(v[b-1]);
        g[b-1].push_back(a-1);
        gc[b-1].push_back(v[a-1]);
     }
     for(lli i=0;i<n;i++)
     {
        gc[i].push_back(v[i]);
        sort(gc[i].begin(),gc[i].end(),cmp);
     }
     for(lli i=0;i<n;i++)
     {
        vector<node> gat;gat.clear();
        for(lli j=0;j<gc[i].size();j++)
        {
          if(!pq.empty() && (pq.top()).num==gc[i][j])
          {
             gat.push_back(pq.top());
             pq.pop();
          }
        }
        if(!pq.empty())
          printf("%lld ",(pq.top()).index);
        else
          printf("0 ");
        for(lli j=0;j<gat.size();j++)
        {
            pq.push(gat[j]);
        }
     }
     printf("\n");
 
   }
   return 0;
 
}
 