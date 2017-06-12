#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#define lli long long int
using namespace std;
lli ans[100000];
int main()
{
  lli t;
  scanf("%lld",&t);
  while(t--)
  {
     lli n,k,l;
     scanf("%lld%lld%lld",&n,&k,&l);
     lli co=n-1;
     for(lli i=0;i<=co;i++)
      ans[i]=0;
     l=l-1;
 
     while(l>0)
     {
         ans[co]=l%k;
         l=l/k;
         co--;
     }
     for(lli i=0;i<n;i++)
     {
       printf("%lld ",ans[i]+1);
     }
     printf("\n");
  }
  return 0;
}