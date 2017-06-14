#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#define lli long long int
using namespace std;
lli gcd(lli a,lli b)
{
   if(b==0)
     return a;
   else
   {
     return gcd(b,a%b);
   }
}
int main()
{
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
     lli a,b;
     scanf("%lld%lld",&a,&b);
     lli x=gcd(a,b);
     b=b/x;
     lli flag=0;
     while(1)
     {
          x=gcd(b,x);
          if(b==x)
          {
            flag=1;
            break;
          }
          else if(x==1)
          {
             flag=0;
             break;
         }
         b=b/x;
     }
     if(flag==1)
       printf("Yes\n");
     else if(flag==0)
       printf("No\n");
  }
  return 0;
}