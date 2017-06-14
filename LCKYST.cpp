#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define lli long long int
using namespace std;
lli pow(lli a,lli b)
{
   if(b==0)
    return 1;
  lli x=pow(a,b/2);
  if(b%2==0)
   return x*x;
 else
  return a*x*x;
}
int main()
{
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
    lli n,n1;
    scanf("%lld",&n);
    n1=n;
    lli count1=0;
    while(1)
    {
       if(n%5==0)
        count1++;
      else
        break;
       n=n/5;
    }
    n=n1;
    while(1)
    {
       if(n%2==0)
        count1--;
      else
        break;
       n=n/2;
    }
    if(count1<0)
      count1=0;
    lli ans=count1/2;
    if(count1%2!=0)
      ans++;
   lli x=pow(4,ans);
   //printf("ans==%lld\n",ans);
   printf("%lld\n",x*n1);
  }
  return 0;
}
 