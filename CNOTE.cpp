#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#define lli long long int
#define gc() getchar_unlocked()
using namespace std;
lli page[100001],price[100001];
int main()
{
  lli t;
  scanf("%lld",&t);
  gc();
  while(t--)
  {
     lli x,y,k,n;
     scanf("%lld%lld%lld%lld",&x,&y,&k,&n);
     for(lli i=0;i<n;i++)
     {
       scanf("%lld",&page[i]);
       scanf("%lld",&price[i]);
     }
     lli l=x-y;
     lli flag=0;
     for(lli i=0;i<n;i++)
     {
        if(l<=page[i] && price[i]<=k)
        {
          flag=1;
          break;
        }
     }
     if(flag==0)
     {
       printf("UnluckyChef\n");
     }
     else
     {
       printf("LuckyChef\n");
     }
   }
   return 0;
 }