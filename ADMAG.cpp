#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define lli long long int
using namespace std;
lli arr[10000000];
lli sum1=1000000000000000000;
lli init()
{
   arr[0]=1;
   arr[1]=1;
   lli i;
   for(i=2;i<1000000;i++)
   {
      arr[i]=arr[i-1]+arr[i-2];
      if(arr[i]>sum1)
      {
        //printf("i==%lld arr[i]==%lld\n",i,arr[i]);
        break;
      }
   }
   return i;
}
 
int main()
{
   lli m=init();
   lli t;
   scanf("%lld",&t);
   while(t--)
   {
     lli s=0,e=0,sum=0,i,x;
     scanf("%lld",&x);
     for(i=0;i<=m;i++)
     {
       sum=sum+arr[i];
       if(sum>=x)
       {
           break;
       }
     }
     printf("%lld\n",i+1);
   }
   return 0;
}