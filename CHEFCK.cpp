#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<limits.h>
#define lli long long int
#define mod 1000000007
using namespace std;
lli N,K,Q;
lli arr[10000009];
lli a,b,c,d,e,f,r,s,t,m;
lli L1,La,Lc,Lm,D1,Da,Dc,Dm;
lli pow_t[100000009];
void power_t(lli n)
{
   pow_t[0]=1%s;
   for(lli i=1;i<n+3;i++)
   {
     pow_t[i]=pow_t[i-1]*t;
     pow_t[i]=pow_t[i]%s;
   }
}
lli generate_arr()
{
  power_t(N);
  for(lli x=2;x<=N;x++)
  {
    if(pow_t[x]%s<=r)
       arr[x]=(  ( ( ((a*arr[x-1])%m) *arr[x-1] )%m  +  (b*arr[x-1])%m )%m +c)%m;
    else
       arr[x]=(  ( ( ((d*arr[x-1])%m) *arr[x-1] )%m  +  (e*arr[x-1])%m )%m +f)%m;
       //arr[x]=(d*arr[x-1]*arr[x-1]+e*arr[x-1]+f)%m;
  }
  for(lli x=0;x<N;x++)
  {
    arr[x]=arr[x+1];
  }
}
lli max_size=0;
 
 
 
lli get_size()
{
    max_size=4*(N-1);
}
 
lli get_sum(lli*st,lli ss,lli se,lli qs,lli qe,lli index)
{
  if(qs<=ss && qe>=se)
    return st[index];
  if(se<qs || ss>qe)
    return LONG_LONG_MAX;
  lli mid=(ss+se)/2;
  return min( get_sum(st,ss,mid,qs,qe,2*index+1),
         get_sum(st,mid+1,se,qs,qe,2*index+2)  );
}
 
lli csumuntill(lli ss,lli se,lli *st,lli si)
{
  if(ss==se)
  {
    st[si]=arr[ss];
    return arr[ss];
  }
  lli mid=(ss+se)/2;
  st[si]=  min (csumuntill(ss,mid,st,si*2+1),
                 csumuntill(mid+1,se,st,si*2+2) );
  return st[si];
}
lli* csum()
{
   get_size();
   lli * sum_tree=(lli *)malloc(sizeof(lli)*max_size);
   csumuntill(0,N-1,sum_tree,0);
   return sum_tree;
}
 
 
 
void generate_range()
{
   lli * tree=csum();
   lli sum=0;
   lli prdct=1;
   for(lli i=1;i<=Q;i++)
   {
      L1=(La*L1+Lc)%Lm;
      D1=(Da*D1+Dc)%Dm;
      //printf("D1=%lld\n",D1);
      lli L=L1+1;
      lli R=min(L+K-1+D1,N);
      //printf("L===%lld R====%lld\n",L,R);
      lli qs=L-1;
      lli qe=R-1;
      if(qs>qe)
        swap(qs,qe);
    //  printf("qs===%lld qe====%lld\n",qs,qe);
 
      lli zuck=get_sum(tree,0,N-1,qs,qe,0);
      //printf("zuck===%lld\n",zuck);
      sum=sum+zuck;
      prdct=(prdct*zuck)%mod;
   }
   printf("%lld %lld\n",sum,prdct%mod);
}
 
int main()
{
   scanf("%lld%lld%lld",&N,&K,&Q);
   scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld",
   &a,&b,&c,&d,&e,&f,&r,&s,&t,&m,&arr[1]);
   scanf("%lld%lld%lld%lld%lld%lld%lld%lld",
   &L1,&La,&Lc,&Lm,&D1,&Da,&Dc,&Dm);
   generate_arr();
  /* for(lli i=0;i<N;i++)
     printf("%lld ",arr[i]);*/
 
   generate_range();
   return 0;
}