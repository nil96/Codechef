#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<limits.h>
#include<list>
#define lli long long int
#define mod 1000000007
using namespace std;
lli N,K,Q;
lli arr[10000009];
lli ans[10000009];
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
       arr[x]=(a*arr[x-1]*arr[x-1]+b*arr[x-1] +c)%m;
    else
       arr[x]=(d*arr[x-1]*arr[x-1]+e*arr[x-1] +f)%m;
       //arr[x]=(d*arr[x-1]*arr[x-1]+e*arr[x-1]+f)%m;
  }
  for(lli x=0;x<N;x++)
  {
    arr[x]=arr[x+1];
  }
}
 
 
void fun()
{
   //lli arr[]={4,3,2,1};
   //lli len=sizeof(arr)/sizeof(lli);
   lli len=N;
   list<lli> p;
   p.clear();
   lli k=K;
   for(lli i=0;i<len;i++)
   {
       if(i>=k)
         ans[i-k]=p.front();
       while(!p.empty()  && p.back()>arr[i])
         p.pop_back();
       p.push_back(arr[i]);
      if(i>=k && arr[i-k]==p.front()){
         p.pop_front();
      }
   }
   lli min1=LONG_LONG_MAX;
   for(lli i=len-k;i<len;i++)
   {
      if(min1>arr[i])
        min1=arr[i];
   }
   for(lli i=len-k;i<len;i++)
   {
        ans[i]=min1;
   }
 
 /* printf("ans \n");
   for(lli i=0;i<len;i++)
   {
      printf("%lld ",ans[i]);
   }
   printf("ans\n");*/
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
lli query(lli qs,lli qe)
{
  return min(ans[qs],ans[qe-K+1]);
}
 
 
void generate_range()
{
   //lli * tree=csum();
   lli sum=0;
   lli prdct=1;
   fun();
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
 
      lli zuck;
      zuck=query(qs,qe);
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