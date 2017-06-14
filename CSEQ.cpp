#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#define lli long long int
#define mod 1000003
#define base 1000003
using namespace std;
vector<lli> nx;
vector<lli> rx;
vector<lli> :: iterator p;
lli convert_n(lli x)
{
   nx.clear();
   while(x!=0)
   {
 
     lli z=x%base;
     p=nx.begin();
     nx.insert(p,z);
     x=x/base;
   }
}
lli convert_r(lli x)
{
   rx.clear();
   while(x!=0)
   {
 
     lli z=x%base;
     p=rx.begin();
     rx.insert(p,z);
     x=x/base;
   }
}
lli balance()
{
   lli nx_size=nx.size();
   lli rx_size=rx.size();
   if(nx_size==rx_size)
     return 0;
   if(nx_size<rx_size)
   {
      while(nx_size!=rx_size)
      {
         p=nx.begin();
         nx.insert(p,0);
         nx_size++;
      }
   }
   else if(nx_size>rx_size)
   {
      while(nx_size!=rx_size)
      {
         p=rx.begin();
         rx.insert(p,0);
         rx_size++;
      }
   }
}
 
lli fact[1000050];
lli ifact[1000050];
lli power(lli a,lli b,lli m)
{
  if(b==0)
    return 1;
  lli x=power(a,b/2,m);
  x=x%mod;
  if(b%2==0)
     return (x*x)%mod;
  else
     return ((a%mod)*(x*x))%mod;
}
 
 
lli mod_inverse(lli x)
{
   return power(x,mod-2,mod);
}
 
 
lli calculate_fact()
{
   fact[0]=1;
   ifact[0]=1;
   for(lli i=1;i<=mod+7;i++)
   {
     fact[i]=(fact[i-1]*i)%mod;
     ifact[i]=(mod_inverse(i)*ifact[i-1])%mod;
   }
}
lli get_fact(lli x)
{
   if(x>mod)
    return 0;
   else
    return fact[x];
}
 
 
lli get_ifact(lli x)
{
   if(x>mod)
   {
     lli z=power(x,mod-2,mod);
     return ifact[z];
   }
   else
    return ifact[x];
}
lli ncr(lli n1,lli r1)
{
   if(r1>n1)
     return 0;
   return (((get_fact(n1%mod)*get_ifact(n1-r1))%mod)*get_ifact(r1) )%mod;
}
lli oprtn(lli n1,lli r1)
{
   convert_n(n1);
   convert_r(r1);
   balance();
   lli ans=1;
   for(lli i=0;i<nx.size();i++)
   {
     ans=( ans*ncr(nx[i],rx[i]) )%mod ;
   }
   return ans;
}
 
 
 
int main()
{
  calculate_fact();
 
 
  lli ans=mod_inverse(1000000+8);
  //printf("ans==%lld fact[i]=%lld\n",ans,fact[mod]);
 
  lli t,n,l,r;
  scanf("%lld",&t);
  while(t--)
  {
     scanf("%lld%lld%lld",&n,&l,&r);
     lli nd=(r-l+1);
     lli x=(nd-1);
     lli m=n;
     lli n1=(x+m+1);
     lli r1=(x+1);
     lli ans1=oprtn(n1,r1);
    // printf("ans1======%lld\n",ans1);
     ans1=( (ans1%mod-1%mod)+mod)%mod;
     printf("%lld\n",ans1);
  }
  return 0;
}