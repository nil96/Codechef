#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#define lli long long int
using namespace std;
vector<lli> list1[10010];
lli visited[10010];
lli ChainHead[10010],ChainPos[10010];
lli ChainLength[10010],ChainIndex[10010];
lli subsize[10010];
lli chainNo=0;
lli visited1[10010];
lli fsubsize(lli cur)
{
   lli i;
   lli sum=0,x=0;
   visited1[cur]=1;
   if(list1[cur].size()==1)
   {
   //   printf("leaf %lld\n",cur);
      subsize[cur]=1;
     // printf("%lld cur =%lld sizel\n",cur,subsize[cur]);
      return 1;
   }
     for(i=0;i<list1[cur].size();i++)
     {
       if(visited1[list1[cur][i]]==0)
       {
           x=x+fsubsize(list1[cur][i]);
       }
     }
     subsize[cur]=x+1;
     return subsize[cur];
}
 
lli zount=0;
void hld(lli cur)
{
   lli i;
   //printf("%lld \n",cur);
  // if(visited[cur]==1)
    // return ;
  // else
   {
      visited[cur]=1;
      if(ChainHead[chainNo]==-1)
         ChainHead[chainNo]=cur;
      ChainIndex[cur]=chainNo;
      ChainPos[cur]=ChainLength[chainNo];
      ChainLength[chainNo]++;
 
      lli ind=-1,mai=-1;
      for(i=0;i<list1[cur].size();i++)
      {
         if(visited[list1[cur][i]]==0)
         {
           if(subsize[list1[cur][i]]>mai)
           {
              mai=subsize[list1[cur][i]];
              ind=i;
           }
        }
      }
 
 
      if(ind>=0)
      {
        if(visited[list1[cur][ind]]==0)
            hld(list1[cur][ind]);
      }
      for(i=0;i<list1[cur].size();i++)
      {
        if(visited[list1[cur][i]]==0)
        {
           if(i!=ind)
           {
             chainNo++;
             hld(list1[cur][i]);
           }
        }
      }
   }
}
lli parent[10010],depth[10010];
 
lli Dfs(lli cur,lli cp,lli dip)
{
  visited[cur]=1;
  parent[cur]=cp;
  depth[cur]=dip;
  lli i;
  for(i=0;i<list1[cur].size();i++)
  {
    if(visited[list1[cur][i]]==0)
    {
      Dfs(list1[cur][i],cur,dip+1);
    }
  }
}
lli lca(lli a,lli b)
{
    while(ChainIndex[a]!=ChainIndex[b])
    {
      if(depth[ChainHead[ChainIndex[a]]]<depth[ChainHead[ChainIndex[b]]])
      {
        b=parent[ChainHead[ChainIndex[b]]];
      }
      else
      {
        a=parent[ChainHead[ChainIndex[a]]];
      }
    }
    if(depth[a]<depth[b])
      return a;
    return b;
}
void intilize(lli t,lli root)
{
  lli i;
  for(i=0;i<=t+10;i++)
  {
    ChainHead[i]=-1;
    ChainIndex[i]=0;
    ChainLength[i]=0;
    ChainPos[i]=0;
    visited1[i]=0;
    visited[i]=0;
    subsize[i]=-1;
  }
   fsubsize(root);
   hld(root);
   for(i=0;i<10010;i++)
     visited[i]=0;
   Dfs(root,root,0);
}
lli v1[10010];
vector<lli> v[10010];
int main()
{
   lli t,i,k;
   scanf("%lld%lld",&t,&k);
   lli x,y;
   lli root;
   scanf("%lld",&root);
   for(i=1;i<t;i++)
   {
     scanf("%lld%lld",&x,&y);
     list1[x].push_back(y);
     list1[y].push_back(x);
   }
   intilize(t,root);
 //  printf("till done\n");
   lli city;
   for(i=1;i<=t;i++)
   {
      scanf("%lld",&v1[i]);
      v[v1[i]].push_back(i);
   }
   lli q;
   scanf("%lld",&q);
   while(q--)
   {
     lli x,y;
     scanf("%lld%lld",&x,&y);
     lli ans1=100000000;
     lli dip=-1;
     lli source=x,dest;
     for(i=0;i<v[y].size();i++)
     {
       lli _lca;
       dest=v[y][i];
       _lca=lca(source,dest);
    //   printf("(%lld %lld) %lld\n",source,dest,_lca);
       if(depth[_lca]>=dip)
       {
          if(depth[_lca]==dip)
          {
             if(ans1>dest)
             {
               ans1=dest;
             }
          }
          else
          {
            ans1=dest;
            dip=depth[_lca];
          }
       }
     }
     printf("%lld\n",ans1);
   }
}