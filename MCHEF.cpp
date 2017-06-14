#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<limits>
#include<limits.h>
#define inf LONG_LONG_MAX
#define lli long long int
#define gc getchar_unlocked
using namespace std;
struct node
{
  lli inp;
  lli cost;
};
struct range
{
  lli s,e,c;
};
lli read_lli() {
  char c = gc();
  char x=c;
  while(c<'0' || c>'9') c = gc();
  lli ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  if(x=='-')
   return -ret;
  return ret;
}
 
 
struct range x[100005];
struct node arr[100005];
lli k[100000+1][501+1];
int cmp(const void *a1,const void*b1)//increasing
{
   lli a=((struct range *)a1)->c;
   lli b=((struct range *)b1)->c;
   if(a>b)
    return 1;
  if(a<b)
    return -1;
  if(a==b)
    return 0;
}
lli knap(lli W,lli wt[],lli val[],lli n)
{
  lli i,w;
  for(lli i=0;i<=n;i++)
  {
    for(lli w=0;w<=W;w++)
    {
       if(i==0 || w==0)
         k[i][w]=0;
        else if(wt[i-1]<=w)
         k[i][w]=max(val[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
        else
         k[i][w]=k[i-1][w];
    }
  }
  return k[n][W];
}
lli prepare_knapsack(lli n,lli k)
{
   lli wt[n+3];
   lli val[n+3];
   lli x=0;
   for(lli i=0;i<n;i++)
   {
     if(arr[i].inp<0)
     {
       val[x]=0-arr[i].inp;
       wt[x]=arr[i].cost;
       //printf("(%lld,%lld,%lld) ",i,arr[i].inp,arr[i].cost);
       x++;
     }
   }
   //printf("x==%lld k===%lld\n",x,k);
   return knap(k,wt,val,x);
}
int main()
{
   lli t;
   //scanf("%lld",&t);
   t=read_lli();
   while(t--)
   {
     lli n,k,m,temp,sum=0;
     //scanf("%lld%lld%lld",&n,&k,&m);
     n=read_lli();
     k=read_lli();
     m=read_lli();
     for(lli i=0;i<n;i++)
     {
        //scanf("%lld",&arr[i].inp);
        arr[i].inp=read_lli();
        //printf("%lld ",arr[i].inp);
        sum=sum+arr[i].inp;
        arr[i].cost=inf;
     }
     for(lli i=0;i<m;i++)
     {
       //scanf("%lld%lld%lld",&x[i].s,&x[i].e,&x[i].c);
       x[i].s=read_lli();
       x[i].e=read_lli();
       x[i].c=read_lli();
       x[i].s--;
       x[i].e--;
     }
     qsort(x,m,sizeof(struct range),cmp);
     for(lli i=0;i<n;i++)
     {
        for(lli j=0;j<m;j++)
        {
           if(i>=x[j].s && i<=x[j].e)
           {
             arr[i].cost=x[j].c;
             break;
           }
        }
 
     }
     lli z=prepare_knapsack(n,k);
    // printf("z===%lld sum==%lld\n",z,sum);
     printf("%lld\n",sum+z);
   }
 
}