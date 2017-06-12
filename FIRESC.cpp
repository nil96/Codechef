#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#define lli long long int
#define visited 0
#define mod 1000000007
using namespace std;
vector<lli> v[100040];
lli arr[100040];
lli my_memset(lli n)
{
  lli i;
  for(i=0;i<=n;i++)
  {
    v[i].clear();
    arr[i]=i;
  }
}
lli count2=0;
lli dfs(lli node,lli n)
{
    lli i;
    arr[node]=visited;
    count2++;
    for(i=0;i<v[node].size();i++)
    {
       if(arr[v[node][i]]!=visited)
       {
          dfs(v[node][i],n);
       }
    }
 
}
int main()
{
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
     lli n=0,m=0,answer=1,count1=0,i=0;
     scanf("%lld%lld",&n,&m);
     my_memset(n);
     while(m--)
     {
       lli node1,node2;
       scanf("%lld%lld",&node1,&node2);
       v[node1].push_back(node2);
       v[node2].push_back(node1);
     }
     for(i=1;i<=n;i++)
     {
        if(arr[i]!=visited)
        {
           count2=0;
 
           dfs(i,n);
 
           answer=(answer*(count2%mod) )%mod;
          // printf("answer====%lld\n",answer);
           count1++;
         }
      }
       printf("%lld %lld\n",count1%mod,answer%mod);
  }
  return 0;
}
 